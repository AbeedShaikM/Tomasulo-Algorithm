#include "./Register.hpp"

int c_Register::m_Count = 0;

c_Register::c_Register(){
    m_Value = 0;
    m_Qi = 0;
    m_RegisterNumber = m_Count++;
}

void c_Register::f_SetValue(int p_Value){
    m_Value = p_Value;
    m_Qi = 0;
}

void c_Register::f_SetWrittingUnit(int p_WrittingUnit){
    m_Qi = p_WrittingUnit;
}

float c_Register::f_GetValue(){
    return m_Value;
}


int c_Register::f_GetWrittingUnit(){
    return m_Qi;
}


