#include <./Instruction.hpp>

c_Instruction::c_Instruction(t_InstructionType p_InstructionType){
    m_InstructionType = p_InstructionType;
}

c_Instruction::~c_Instruction(){
}

void c_Instruction::f_SetDestinationRegister(int p_DestinationRegister){
    m_DestinationRegister = p_DestinationRegister;
}

void c_Instruction::f_SetSourceRegister1(int p_SourceRegister1){
    m_SourceRegister1 = p_SourceRegister1;
}

void c_Instruction::f_SetSourceRegister2(int p_SourceRegister2){
    m_SourceRegister2 = p_SourceRegister2;
}

void c_Instruction::f_SetImmediate(int p_Immediate){
    m_Immediate = p_Immediate;
}

void c_Instruction::f_SetInstructionType(t_InstructionType p_InstructionType){
    m_InstructionType = p_InstructionType;
}

void c_Instruction::f_SetInstructionAddress(int p_InstructionAddress){
    m_InstructionAddress = p_InstructionAddress;
}

int c_Instruction::f_GetDestinationRegister(){
    return m_DestinationRegister;
}

int c_Instruction::f_GetSourceRegister1(){
    return m_SourceRegister1;
}

int c_Instruction::f_GetSourceRegister2(){
    return m_SourceRegister2;
}

int c_Instruction::f_GetImmediate(){
    return m_Immediate;
}

t_InstructionType c_Instruction::f_GetInstructionType(){
    return m_InstructionType;
}

int c_Instruction::f_GetInstructionAddress(){
    return m_InstructionAddress;
}
