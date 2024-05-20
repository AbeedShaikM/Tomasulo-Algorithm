#include "./ReservationStation.hpp"

c_ReservationStation::c_ReservationStation(t_ReserveStationType p_ReserveStationType){
    m_ReserveStationType = p_ReserveStationType;
}

c_ReservationStation::~c_ReservationStation(){
}

void c_ReservationStation::f_SetBusy(bool p_Busy){
    m_Busy = p_Busy;
}

void c_ReservationStation::f_SetInstructionType(t_InstructionType p_InstructionType){
    m_InstructionType = p_InstructionType;
}

void c_ReservationStation::f_SetVj(int p_Vj){
    m_Vj = p_Vj;
}

void c_ReservationStation::f_SetVk(int p_Vk){
    m_Vk = p_Vk;
}

void c_ReservationStation::f_SetQj(int p_Qj){
    m_Qj = p_Qj;
}

void c_ReservationStation::f_SetQk(int p_Qk){
    m_Qk = p_Qk;
}

void c_ReservationStation::f_SetA(int p_A){
    m_A = p_A;
}

t_ReserveStationType c_ReservationStation::f_GetReserveStationType(){
    return m_ReserveStationType;
}

t_InstructionType c_ReservationStation::f_GetInstructionType(){
    return m_InstructionType;
}

bool c_ReservationStation::f_GetBusy(){
    return m_Busy;
}

int c_ReservationStation::f_GetVj(){
    return m_Vj;
}

int c_ReservationStation::f_GetVk(){
    return m_Vk;
}

int c_ReservationStation::f_GetQj(){
    return m_Qj;
}

int c_ReservationStation::f_GetQk(){
    return m_Qk;
}

int c_ReservationStation::f_GetA(){
    return m_A;
}

