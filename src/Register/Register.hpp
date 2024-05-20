#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "../types.hpp"

class c_Register{
    public:
        void f_SetValue(int);
        void f_SetStatus(t_RegisterStatus);
        void f_SetWrittingUnit(int);
        float f_GetValue();
        t_RegisterStatus f_GetStatus();
        int f_GetWrittingUnit();
    private:
        float m_Value = 0;
        t_RegisterStatus m_Status = E_RS_READY;
        int m_WrittingUnit = -1;
};