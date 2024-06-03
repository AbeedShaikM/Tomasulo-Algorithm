#include "./ReservationStation.hpp"

int c_ReservationStation::m_Count = 0;

c_ReservationStation::c_ReservationStation(t_ReserveStationType p_ReserveStationType){
    m_ReserveStationIndex = ++m_Count;
    m_ReserveStationType = p_ReserveStationType;
}

c_ReservationStation::~c_ReservationStation(){
    delete m_Instruction;
}

bool c_ReservationStation::f_GetStatus(){
    return m_Busy;
}

int c_ReservationStation::f_GetVJ(){
    return m_Vj;
}

int c_ReservationStation::f_GetVK(){
    return m_Vk;
}

int c_ReservationStation::f_GetQj(){
    return m_Qj;
}

int c_ReservationStation::f_GetQk(){
    return m_Qk;
}

int c_ReservationStation::f_GetImm(){
    return m_Imm;
}

void c_ReservationStation::init(c_Instruction *p_Instruction)
{
    m_Instruction = p_Instruction;
    p_Instruction->m_ReserveStationIndex = m_ReserveStationIndex;
    m_Busy = true;
}


void c_ReservationStation::f_SetStatus(bool p_Status){
    m_Busy = p_Status;
}

void c_ReservationStation::f_SetQJ(int p_Qj){
    m_Qj = p_Qj;
}

void c_ReservationStation::f_SetQK(int p_Qk){
    m_Qk = p_Qk;
}

c_Instruction* c_ReservationStation::f_GetInstruction(){
    return m_Instruction;
}

void c_ReservationStation::f_SetVJ(int p_Vj){
    m_Vj = p_Vj;
}

void c_ReservationStation::f_SetVK(int p_Vk){
    m_Vk = p_Vk;
}

// Path: src/reservation_station/ReservationStation.hpp

