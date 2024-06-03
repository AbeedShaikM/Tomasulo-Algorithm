#include "Instruction.hpp"

int c_Instruction::m_Count = 0;

c_RInstruction::c_RInstruction(t_InstructionType p_InstructionType, int p_DestinationRegister, int p_SourceRegister1, int p_SourceRegister2)
{
    m_DestinationRegister = p_DestinationRegister;
    m_SourceRegister2 = p_SourceRegister2;
    m_SourceRegister1 = p_SourceRegister1;
    m_InstructionType = p_InstructionType;
    m_InstructionIndex = ++m_Count;
}

c_RInstruction::~c_RInstruction()
{
}

int c_RInstruction::f_GetSourceRegister2()
{
    return m_SourceRegister2;
}

c_LOADSTOREInstruction::c_LOADSTOREInstruction(t_InstructionType p_InstructionType, int p_DestinationRegister, int p_SourceRegister1, int p_Immediate)
{
    m_SourceRegister1 = p_SourceRegister1;
    m_DestinationRegister = p_DestinationRegister;
    m_Immediate = p_Immediate;
    m_InstructionType = p_InstructionType;
    m_InstructionIndex = ++m_Count;
}

c_LOADSTOREInstruction::~c_LOADSTOREInstruction()
{
}

int c_LOADSTOREInstruction::f_GetImmediate()
{
    return m_Immediate;
}

int c_Instruction::f_GetDestinationRegister()
{
    return m_DestinationRegister;
}

int c_Instruction::f_GetSourceRegister1()
{
    return m_SourceRegister1;
}
