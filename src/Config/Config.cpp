#include "./Config.hpp"

c_Config::c_Config(int p_Registers, int p_ReservationAddStations, int p_ReservationMulStations, int p_LoadBuffer, int p_StoreBuffer){
    m_Registers = p_Registers;
    m_AddReservationStations = p_ReservationAddStations;
    m_MultiplyReservationStations = p_ReservationMulStations;
    m_LoadBuffer = p_LoadBuffer;
    m_StoreBuffer = p_StoreBuffer;
    m_AddReservationStationsList = new c_ReservationStation*[m_AddReservationStations + 1];
    for(int i = 1; i <= m_AddReservationStations; i++){
        m_AddReservationStationsList[i] = new c_ReservationStation(t_ReserveStationType::E_RST_ADD);
    }
    m_MultiplyReservationStationsList = new c_ReservationStation *[m_MultiplyReservationStations + 1];

    for(int i = 1; i <= m_MultiplyReservationStations; i++){
        m_MultiplyReservationStationsList[i] = new c_ReservationStation(t_ReserveStationType::E_RST_MUL);
    }
    m_LoadBufferList = new c_ReservationStation *[m_LoadBuffer + 1];
    for(int i = 1; i <= m_LoadBuffer; i++){
        m_LoadBufferList[i] = new c_ReservationStation(t_ReserveStationType::E_RST_LOAD);
    }
    m_StoreBufferList = new c_ReservationStation *[m_StoreBuffer + 1];
    for(int i = 1; i <= m_StoreBuffer; i++){
        m_StoreBufferList[i] = new c_ReservationStation(t_ReserveStationType::E_RST_STORE);
    }
    m_RegisterList = new c_Register*[m_Registers + 1];
    for(int i = 0; i <= m_Registers; i++){
        m_RegisterList[i] = new c_Register();
    }
}

c_Config::~c_Config(){
    for(int i = 0; i < m_AddReservationStations; i++){
        delete m_AddReservationStationsList[i];
    }
    for(int i = 0; i < m_MultiplyReservationStations; i++){
        delete m_MultiplyReservationStationsList[i];
    }
    for(int i = 0; i < m_LoadBuffer; i++){
        delete m_LoadBufferList[i];
    }
    for(int i = 0; i < m_StoreBuffer; i++){
        delete m_StoreBufferList[i];
    }
    for(int i = 0; i < m_Registers; i++){
        delete m_RegisterList[i];
    }
    delete[] m_AddReservationStationsList;
    delete[] m_MultiplyReservationStationsList;
    delete[] m_LoadBufferList;
    delete[] m_StoreBufferList;
    delete[] m_RegisterList;
}

int c_Config::getRegisters()
{
    return m_Registers;
}

int c_Config::getAddReservationStations(){
    return m_AddReservationStations;
}

int c_Config::getMultiplyReservationStations(){
    return m_MultiplyReservationStations;
}

int c_Config::getLoadBuffer(){
    return m_LoadBuffer;
}

int c_Config::getStoreBuffer(){
    return m_StoreBuffer;
}

