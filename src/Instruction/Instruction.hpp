#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <iostream>

#ifndef TYPES_H
#include "../types.hpp"
#endif

#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

class c_Instruction{
    public:
        static int m_Count;
        virtual int f_GetSourceRegister2(){
            std::cout << "Error: f_GetSourceRegister2() called on a non-R type instruction" << std::endl;
            assert(false);
        }
        virtual int f_GetImmediate()
        {
            std::cout << "Error: f_getImmediate() called on a non-LOAD/STORE type instruction" << std::endl;
            assert(false);
        }
        static int count;
        t_InstructionType m_InstructionType;
        t_InstructionStatus m_InstructionStatus;
        int f_GetDestinationRegister();
        int f_GetSourceRegister1();
        int m_InstructionIndex = 0;
        int m_ReserveStationIndex = 0;
    protected:
        int m_DestinationRegister = 0;
        int m_SourceRegister1 = 0;
};

class c_RInstruction : public c_Instruction{
    public:
        c_RInstruction(t_InstructionType, int, int, int);
        ~c_RInstruction();
        virtual int f_GetSourceRegister2();
    private:
        int m_SourceRegister2 = 0;
};

class c_LOADSTOREInstruction : public c_Instruction{
    public:
        c_LOADSTOREInstruction(t_InstructionType, int, int, int);
        ~c_LOADSTOREInstruction();
        virtual int f_GetImmediate();
    private:
        int m_Immediate = -1;
};


#endif // INSTRUCTION_HPP