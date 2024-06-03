#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <queue>

#ifndef Config_HPP
#include "../Config/Config.hpp"
#endif

#ifndef ReservationStation_HPP
#include "../Reservation_station/ReservationStation.hpp"
#endif

#ifndef Instruction_HPP
#include "../Instruction/Instruction.hpp"
#endif

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
class c_UNIT{
    public:
        c_UNIT(int);
        int m_TimeToExecute = 0;
        int m_IsBusy = false;
        int m_WillFree = 0;
        c_ReservationStation* m_ReservationStation;
};

class c_Scheduler{
    private:
        void f_WriteBack();
        void f_Execution();
        void f_Issue();
        void f_FreeUnit(c_UNIT*);
        bool f_ReserveStation(c_ReservationStation *, c_Instruction *);
        void f_OperandUpdate(c_ReservationStation *, int, int);
        bool f_AllocateUnit(c_ReservationStation*, c_UNIT*);
        void f_FreeReservationStation(c_ReservationStation*);
        void f_WriteBackToReserverStation(c_ReservationStation*, int);
    public:
        int m_TotalInstructions = 0;
        int m_ClockCycle = 0;
        int m_CompletedInstructions = 0;
        void f_Cycle();
        c_UNIT* m_Adder;
        c_UNIT* m_Multiplier;
        c_Scheduler(int, int, int, int, int);
        ~c_Scheduler();
        void f_AddInstruction(c_Instruction*);
        std::queue<c_Instruction*> m_Instructions;
        std::vector<c_Instruction*> m_InstructionsList;
        c_Config* m_Config;
        std::priority_queue<int, std::vector<int>, std::greater<int>> m_CDBAccess;
};

#endif // SCHEDULER_HPP