#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../reservation_station/ReservationStation.hpp"

#ifndef TYPES_H
#include "../types.hpp"
#endif

class c_Config{
    private:
        int m_Registers = 0;
        int m_AddReservationStations = 0;
        int m_MultiplyReservationStations = 0;
        int m_LoadBuffer = 0;
        int m_StoreBuffer = 0;
        // Assuming 1 ADD unit, 1 MUL unit and 1 LOAD/STORE unit
        c_ReservationStation** m_AddReservationStationsList;
        c_ReservationStation** m_MultiplyReservationStationsList;
        c_ReservationStation** m_LoadBufferList;
        c_ReservationStation** m_StoreBufferList;
    public:
        c_Config(int, int, int, int, int);
        ~c_Config();
        void f_SetNumberOfRegisters(int);
        void f_SetAddReservationStations(int);
        void f_SetMultiplyReservationStations(int);
        void f_SetLoadBuffer(int);
        void f_SetStoreBuffer(int);
        int f_GetNumberOfRegisters();
        int f_GetAddReservationStations();
        int f_GetMultiplyReservationStations();
        int f_GetLoadBuffer();
        int f_GetStoreBuffer();
        c_ReservationStation** f_GetAddReservationStationsList();
        c_ReservationStation** f_GetMultiplyReservationStationsList();
        c_ReservationStation** f_GetLoadBufferList();
        c_ReservationStation** f_GetStoreBufferList();
};