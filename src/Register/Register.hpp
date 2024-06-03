#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef TYPES_H
#include "../types.hpp"
#endif

#ifndef REGISTER_HPP
#define REGISTER_HPP

class c_Register{
    public:
        static int m_Count;
        c_Register();
        int m_RegisterNumber;
        void f_SetValue(int);
        void f_SetWrittingUnit(int);
        float f_GetValue();
        int f_GetWrittingUnit();
    private:
        float m_Value = 0;
        int m_Qi = 0;
};

#endif // REGISTER_HPP