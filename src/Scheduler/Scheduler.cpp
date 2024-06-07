#include "Scheduler.hpp"

c_UNIT::c_UNIT(int p_Time)
{
    m_TimeToExecute = p_Time;
}

c_Scheduler::c_Scheduler(int p_NumberOfRegisters, int p_NumberOfAddReservationStations, int p_NumberOfMulReservationStations, int p_NumberOfLoadStations, int p_NumberOfStoreStations)
{
    m_InstructionsList.push_back(NULL);
    m_Config = new c_Config(p_NumberOfRegisters, p_NumberOfAddReservationStations, p_NumberOfMulReservationStations, p_NumberOfLoadStations, p_NumberOfStoreStations);
    m_Adder = new c_UNIT(2);
    m_Multiplier = new c_UNIT(10);
    m_LoadUnit = new c_UNIT(1);
    m_AGU = new c_UNIT(1);
}

c_Scheduler::~c_Scheduler()
{
    delete m_LoadUnit;
    delete m_Config;
    delete m_Adder;
    delete m_Multiplier;
    delete m_AGU;
}

void c_Scheduler::f_AddInstruction(c_Instruction *p_Instruction)
{
    m_TotalInstructions++;
    m_Instructions.push(p_Instruction);
    m_InstructionsList.push_back(p_Instruction);
}

void c_Scheduler::f_Cycle()
{
    m_ClockCycle++;
    f_WriteBack();
    f_Execution();
    f_Issue();
}

void c_Scheduler::f_Issue()
{
    if (m_Instructions.size() > 0)
    {
        c_Instruction *l_Instruction = m_Instructions.front();
        
        if (l_Instruction->m_InstructionType == t_InstructionType::E_IT_ADD)
        {
            for (int i = 1; i <= m_Config->getAddReservationStations(); i++)
            {
                if (f_ReserveStation(m_Config->m_AddReservationStationsList[i], l_Instruction))
                {
                    m_Instructions.pop();
                    break;
                }
            }
        }
        else if (l_Instruction->m_InstructionType == t_InstructionType::E_IT_MUL)
        {
            for (int i = 1; i <= m_Config->getMultiplyReservationStations(); i++)
            {
                if (f_ReserveStation(m_Config->m_MultiplyReservationStationsList[i], l_Instruction))
                {
                    m_Instructions.pop();
                    break;
                }
            }
        }
        else if (l_Instruction->m_InstructionType == t_InstructionType::E_IT_LOAD)
        {
            for (int i = 1; i <= m_Config->getLoadBuffer(); i++)
            {
                if (f_ReserveStation(m_Config->m_LoadBufferList[i], l_Instruction))
                {
                    m_Instructions.pop();
                    break;
                }
            }
        }
    }
}

void c_Scheduler::f_Execution()
{
    if (m_AGU->m_IsBusy and m_AGU->m_WillFree == m_ClockCycle)
    {
        m_AGU->m_IsBusy = false;
        m_AGU->m_ReservationStation->f_GetInstruction()->m_IsImmReady = true;
        m_AGU->m_ReservationStation->f_GetInstruction()->m_InstructionStatus = t_InstructionStatus::E_IS_ISSUED;
    }

    if (not m_LoadUnit->m_IsBusy)
    {
        for (int i = 1; i <= m_Config->getLoadBuffer(); i++)
        {
            if (m_Config->m_LoadBufferList[i]->f_GetStatus() == false)
                continue;
            if (m_Config->m_LoadBufferList[i]->f_GetInstruction()->m_IsImmReady == false)
                continue;
            if (f_AllocateUnit(m_Config->m_LoadBufferList[i], m_LoadUnit))
            {
                break;
            }
        }
    }

    if (not m_Adder->m_IsBusy)
    {
        for (int i = 1; i <= m_Config->getAddReservationStations(); i++)
        {
            if (f_AllocateUnit(m_Config->m_AddReservationStationsList[i], m_Adder))
                break;
        }
    }

    if (not m_Multiplier->m_IsBusy)
    {
        for (int i = 1; i <= m_Config->getMultiplyReservationStations(); i++)
        {
            if (f_AllocateUnit(m_Config->m_MultiplyReservationStationsList[i], m_Multiplier))
                break;
        }
    }

    if (not m_AGU->m_IsBusy)
    {
        for (int i = 1; i <= m_Config->getLoadBuffer(); i++)
        {
            if (m_Config->m_LoadBufferList[i]->f_GetStatus() == false)
                continue;
            if (m_Config->m_LoadBufferList[i]->f_GetInstruction()->m_IsImmReady == true)
                continue;
            if (f_AllocateUnit(m_Config->m_LoadBufferList[i], m_AGU))
            {
                break;
            }
        }
    }
}

void c_Scheduler::f_WriteBack()
{
    if (not m_CDBAccess.empty())
    {
        int l_InstructionIndex = m_CDBAccess.top();
        int l_ReserveStationIndex = m_InstructionsList[l_InstructionIndex]->m_ReserveStationIndex;
        m_CDBAccess.pop();
        m_InstructionsList[l_InstructionIndex]->m_InstructionStatus = t_InstructionStatus::E_IS_WRITEBACK;
        m_Config->m_RegisterList[m_InstructionsList[l_InstructionIndex]->f_GetDestinationRegister()]->f_SetValue(0);
        if (m_InstructionsList[l_InstructionIndex]->m_InstructionType == t_InstructionType::E_IT_MUL)
        {
            f_FreeReservationStation(m_Config->m_MultiplyReservationStationsList[l_ReserveStationIndex - m_Config->getAddReservationStations()]);
        }
        else if (m_InstructionsList[l_InstructionIndex]->m_InstructionType == t_InstructionType::E_IT_ADD)
        {
            f_FreeReservationStation(m_Config->m_AddReservationStationsList[l_ReserveStationIndex]);
        }
        else
        {
            f_FreeReservationStation(m_Config->m_LoadBufferList[l_ReserveStationIndex - m_Config->getAddReservationStations() - m_Config->getMultiplyReservationStations()]);
        }

        for (int i = 1; i <= m_Config->getAddReservationStations(); i++)
        {
            f_WriteBackToReserverStation(m_Config->m_AddReservationStationsList[i], l_ReserveStationIndex);
        }

        for (int i = 1; i <= m_Config->getMultiplyReservationStations(); i++)
        {
            f_WriteBackToReserverStation(m_Config->m_MultiplyReservationStationsList[i], l_ReserveStationIndex);
        }

        for (int i = 1; i <= m_Config->getLoadBuffer(); i++)
        {
            f_WriteBackToReserverStation(m_Config->m_LoadBufferList[i], l_ReserveStationIndex);
        }

        m_CompletedInstructions++;
    }

    if (m_Adder->m_IsBusy and m_Adder->m_WillFree == m_ClockCycle)
    {
        f_FreeUnit(m_Adder);
    }

    if (m_Multiplier->m_IsBusy and m_Multiplier->m_WillFree == m_ClockCycle)
    {
        f_FreeUnit(m_Multiplier);
    }

    if (m_LoadUnit->m_IsBusy and m_LoadUnit->m_WillFree == m_ClockCycle)
    {
        f_FreeUnit(m_LoadUnit);
    }
}

void c_Scheduler::f_OperandUpdate(c_ReservationStation *p_ReservationStation)
{
    c_Instruction *l_Instruction = p_ReservationStation->f_GetInstruction();
    int l_SourceRegister1 = l_Instruction->f_GetSourceRegister1();
    int l_SourceRegister2;
    if (l_Instruction->m_InstructionType == t_InstructionType::E_IT_LOAD)
    {
        l_SourceRegister2 = 0;
    }
    else
    {
        l_SourceRegister2 = l_Instruction->f_GetSourceRegister2();
    }

    if (m_Config->m_RegisterList[l_SourceRegister1]->f_GetWrittingUnit() == 0)
    {
        p_ReservationStation->f_SetVJ(m_Config->m_RegisterList[l_SourceRegister1]->f_GetValue());
        p_ReservationStation->f_SetQJ(0);
    }
    else
    {
        p_ReservationStation->f_SetQJ(m_Config->m_RegisterList[l_SourceRegister1]->f_GetWrittingUnit());
    }

    if (m_Config->m_RegisterList[l_SourceRegister2]->f_GetWrittingUnit() == 0)
    {
        p_ReservationStation->f_SetVK(m_Config->m_RegisterList[l_SourceRegister2]->f_GetValue());
        p_ReservationStation->f_SetQK(0);
    }
    else
    {
        p_ReservationStation->f_SetQK(m_Config->m_RegisterList[l_SourceRegister2]->f_GetWrittingUnit());
    }

    return;
}

void c_Scheduler::f_FreeUnit(c_UNIT *p_Unit)
{
    std::cout << p_Unit->m_ReservationStation->f_GetInstruction()->m_InstructionIndex << " completed at " << m_ClockCycle << std::endl;
    p_Unit->m_IsBusy = false;
    p_Unit->m_ReservationStation->f_GetInstruction()->m_InstructionStatus = t_InstructionStatus::E_IS_WRITEBACK;
    m_CDBAccess.push(p_Unit->m_ReservationStation->f_GetInstruction()->m_InstructionIndex);
}

bool c_Scheduler::f_ReserveStation(c_ReservationStation *p_ReserveStation, c_Instruction *p_Instruction)
{
    if (p_ReserveStation->f_GetStatus() == true)
        return false;
    p_ReserveStation->init(p_Instruction);
    f_OperandUpdate(p_ReserveStation);

    return true;
}

bool c_Scheduler::f_AllocateUnit(c_ReservationStation *p_ReservationUnit, c_UNIT *p_UNIT)
{
    if (p_ReservationUnit->f_GetStatus() == false)
        return false;
    if (p_ReservationUnit->f_GetInstruction()->m_InstructionStatus >= t_InstructionStatus::E_IS_EXECUTING)
        return false;
    
    if (p_ReservationUnit->f_GetQj() == 0 and p_ReservationUnit->f_GetQk() == 0)
    {
        p_ReservationUnit->f_GetInstruction()->m_InstructionStatus = t_InstructionStatus::E_IS_EXECUTING;
        p_UNIT->m_ReservationStation = p_ReservationUnit;
        p_UNIT->m_WillFree = m_ClockCycle + p_UNIT->m_TimeToExecute;
        m_Config->m_RegisterList[p_ReservationUnit->f_GetInstruction()->f_GetDestinationRegister()]->f_SetWrittingUnit(p_ReservationUnit->m_ReserveStationIndex);
        return p_UNIT->m_IsBusy = true;
    }
}

void c_Scheduler::f_FreeReservationStation(c_ReservationStation *p_ReservationStation)
{
    p_ReservationStation->f_SetStatus(false);
}

void c_Scheduler::f_WriteBackToReserverStation(c_ReservationStation *p_ReservationStation, int p_WrittingReservestationIndex)
{
    if (p_ReservationStation->f_GetQj() == p_WrittingReservestationIndex)
    {
        p_ReservationStation->f_SetQJ(0);
        p_ReservationStation->f_SetVJ(m_Config->m_RegisterList[p_ReservationStation->f_GetInstruction()->f_GetSourceRegister1()]->f_GetValue());
    }
    if (p_ReservationStation->f_GetQk() == p_WrittingReservestationIndex)
    {
        p_ReservationStation->f_SetQK(0);
        p_ReservationStation->f_SetVK(m_Config->m_RegisterList[p_ReservationStation->f_GetInstruction()->f_GetSourceRegister2()]->f_GetValue());
    }
}