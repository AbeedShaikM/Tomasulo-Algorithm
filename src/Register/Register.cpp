#include "./Register.hpp"

void c_Register::f_SetValue(int p_Value){
    m_Value = p_Value;
}

void c_Register::f_SetStatus(t_RegisterStatus p_Status){
    m_Status = p_Status;
}

void c_Register::f_SetWrittingUnit(int p_WrittingUnit){
    m_WrittingUnit = p_WrittingUnit;
}

float c_Register::f_GetValue(){
    return m_Value;
}

t_RegisterStatus c_Register::f_GetStatus(){
    return m_Status;
}

int c_Register::f_GetWrittingUnit(){
    return m_WrittingUnit;
}


