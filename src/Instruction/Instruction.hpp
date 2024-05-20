#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "../types.hpp"

class c_Instruction{
    public:
        c_Instruction(t_InstructionType);
        ~c_Instruction();
        void f_SetDestinationRegister(int);
        void f_SetSourceRegister1(int);
        void f_SetSourceRegister2(int);
        void f_SetImmediate(int);
        void f_SetInstructionType(t_InstructionType);
        void f_SetInstructionAddress(int);
        int f_GetDestinationRegister();
        int f_GetSourceRegister1();
        int f_GetSourceRegister2();
        int f_GetImmediate();
        t_InstructionType f_GetInstructionType();
        int f_GetInstructionAddress();
    private:
        int m_DestinationRegister = -1;
        int m_SourceRegister1 = -1;
        int m_SourceRegister2 = -1;
        int m_Immediate = -1;
        t_InstructionType m_InstructionType;
        int m_InstructionAddress = -1;
};