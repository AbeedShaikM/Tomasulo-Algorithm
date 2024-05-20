#include "./Config.hpp"

c_Config::c_Config(int p_Registers, int p_ReservationAddStations, int p_ReservationMulStations, int p_LoadBuffer, int p_StoreBuffer){
    m_Registers = p_Registers;
    m_AddReservationStations = p_ReservationAddStations;
    m_MultiplyReservationStations = p_ReservationMulStations;
    m_LoadBuffer = p_LoadBuffer;
    m_StoreBuffer = p_StoreBuffer;
    m_AddReservationStationsList = new c_ReservationStation*[m_AddReservationStations];
    m_MultiplyReservationStationsList = new c_ReservationStation*[m_MultiplyReservationStations];
    m_LoadBufferList = new c_ReservationStation*[m_LoadBuffer];
    m_StoreBufferList = new c_ReservationStation*[m_StoreBuffer];
}

c_Config::~c_Config(){
    delete[] m_AddReservationStationsList;
    delete[] m_MultiplyReservationStationsList;
    delete[] m_LoadBufferList;
    delete[] m_StoreBufferList;
}

void c_Config::f_SetNumberOfRegisters(int p_Registers){
    m_Registers = p_Registers;
}

void c_Config::f_SetAddReservationStations(int p_AddReservationStations){
    m_AddReservationStations = p_AddReservationStations;
}

void c_Config::f_SetMultiplyReservationStations(int p_MultiplyReservationStations){
    m_MultiplyReservationStations = p_MultiplyReservationStations;
}

void c_Config::f_SetLoadBuffer(int p_LoadBuffer){
    m_LoadBuffer = p_LoadBuffer;
}

void c_Config::f_SetStoreBuffer(int p_StoreBuffer){
    m_StoreBuffer = p_StoreBuffer;
}

int c_Config::f_GetNumberOfRegisters(){
    return m_Registers;
}

int c_Config::f_GetAddReservationStations(){
    return m_AddReservationStations;
}

int c_Config::f_GetMultiplyReservationStations(){
    return m_MultiplyReservationStations;
}

int c_Config::f_GetLoadBuffer(){
    return m_LoadBuffer;
}

int c_Config::f_GetStoreBuffer(){
    return m_StoreBuffer;
}

c_ReservationStation** c_Config::f_GetAddReservationStationsList(){
    return m_AddReservationStationsList;
}

c_ReservationStation** c_Config::f_GetMultiplyReservationStationsList(){
    return m_MultiplyReservationStationsList;
}

c_ReservationStation** c_Config::f_GetLoadBufferList(){
    return m_LoadBufferList;
}

c_ReservationStation** c_Config::f_GetStoreBufferList(){
    return m_StoreBufferList;
}
