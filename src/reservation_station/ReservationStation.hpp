#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../types.hpp"

#ifndef INSTRUCTION_HPP
#include "../Instruction/Instruction.hpp"
#endif

#ifndef RESERVATIONSTATION_HPP
#define RESERVATIONSTATION_HPP

class c_ReservationStation{
    public:
        static int m_Count;
        int m_ReserveStationIndex;
        c_ReservationStation(t_ReserveStationType);
        ~c_ReservationStation();
        void init(c_Instruction*);
        bool f_GetStatus();
        void f_SetStatus(bool);
        void f_SetQJ(int);
        void f_SetQK(int);
        void f_SetVJ(int);
        void f_SetVK(int);
        int f_GetVJ();
        int f_GetVK();
        int f_GetQj();
        int f_GetQk();
        int f_GetImm();
        c_Instruction* f_GetInstruction();
        t_ReserveStationType m_ReserveStationType;
    private:
        c_Instruction *m_Instruction;
        bool m_Busy = false;
        int m_Vj = 0;
        int m_Vk = 0;
        int m_Qj = 0;
        int m_Qk = 0;
        int m_Out = 0;
        int m_Imm = 0;
};

#endif // RESERVATIONSTATION_HPP
