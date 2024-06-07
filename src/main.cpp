#include "./Scheduler/Scheduler.hpp"

int main(){
    c_Scheduler Scheduler(10, 3, 3, 2, 2);

    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_LOAD, 6, 3, 34));
    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_LOAD, 2, 5, 45));
    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_MUL, 1, 2, 4));
    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_ADD, 8, 6, 2));
    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_MUL, 10, 1, 6));
    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_ADD, 6, 8, 2));

    while(Scheduler.m_CompletedInstructions < Scheduler.m_TotalInstructions){
        Scheduler.f_Cycle();
    }

    std:: cout << "Simulation completed in " << Scheduler.m_ClockCycle - 1 << " cycles" << std::endl;
    return 0;
}