#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../reservation_station/ReservationStation.hpp"

#ifndef REGISTER_HPP
#include "../Register/Register.hpp"
#endif

#ifndef TYPES_H
#include "../types.hpp"
#endif

#ifndef CONFIG_HPP
#define CONFIG_HPP

class c_Config{
    private:
        int m_Registers = 0;
        int m_AddReservationStations = 0;
        int m_MultiplyReservationStations = 0;
        int m_LoadBuffer = 0;
        int m_StoreBuffer = 0;
    public:
        c_Config(int, int, int, int, int);
        ~c_Config();
        c_Register **m_RegisterList;
        // Assuming 1 ADD unit, 1 MUL unit and 1 LOAD/STORE unit
        c_ReservationStation **m_AddReservationStationsList;
        c_ReservationStation **m_MultiplyReservationStationsList;
        c_ReservationStation **m_LoadBufferList;
        c_ReservationStation **m_StoreBufferList;
        int getRegisters();
        int getAddReservationStations();
        int getMultiplyReservationStations();
        int getLoadBuffer();
        int getStoreBuffer();
};

#endif // CONFIG_HPP