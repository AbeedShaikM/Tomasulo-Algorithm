#include "./Shader/Shader.hpp"

int main(){
    c_Scheduler Scheduler(10, 3, 3, 2, 2);

    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_ADD, 1, 2, 3));
    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_MUL, 4, 1, 6));
    Scheduler.f_AddInstruction(new c_RInstruction(t_InstructionType::E_IT_ADD, 5, 1, 7));

    while(Scheduler.m_CompletedInstructions < Scheduler.m_TotalInstructions){
        Scheduler.f_Cycle();
    }

    std:: cout << "Simulation completed in " << Scheduler.m_ClockCycle - 1 << " cycles" << std::endl;
    return 0;
}