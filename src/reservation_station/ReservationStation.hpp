#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../types.hpp"

class c_ReservationStation{
    public:
        c_ReservationStation(t_ReserveStationType);
        ~c_ReservationStation();
        void f_SetBusy(bool);
        void f_SetInstructionType(t_InstructionType);
        void f_SetVj(int);
        void f_SetVk(int);
        void f_SetQj(int);
        void f_SetQk(int);
        void f_SetA(int);
        t_ReserveStationType f_GetReserveStationType();
        t_InstructionType f_GetInstructionType();
        bool f_GetBusy();
        int f_GetVj();
        int f_GetVk();
        int f_GetQj();
        int f_GetQk();
        int f_GetA();
    private:
        t_ReserveStationType m_ReserveStationType;
        bool m_Busy = false;
        t_InstructionType m_InstructionType;
        int m_Vj = -1;
        int m_Vk = -1;
        int m_Qj = -1;
        int m_Qk = -1;
        int m_A = -1;
};