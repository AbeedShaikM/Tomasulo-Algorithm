#include <limits.h>

#ifndef TYPES_H
#define TYPES_H

enum t_BufferType{
    E_BT_LOAD = 0,
    E_BT_STORE = 1,
    E_NUM_BuffTypes = 2
};

enum t_InstructionType{
    E_IT_ADD = 0,
    E_IT_MUL = 1,
    E_IT_LOAD = 2,
    E_IT_STORE = 3,
    E_IT_BNE = 4,
    E_NUM_InstructionTypes = 5
};

enum t_InstructionStatus{
    E_IS_ISSUED = 0,
    E_IS_EXECUTING = 1,
    E_IS_EXECUTED = 2,
    E_IS_WRITEBACK = 3,
    E_IS_COMMITED = 4,
};

enum t_ReserveStationType{
    E_RST_ADD = 0,
    E_RST_MUL = 1,
    E_RST_LOAD = 2,
    E_RST_STORE = 3
};

enum t_RegisterStatus{
    E_RS_BUSY = 0,
    E_RS_READY = 1
};



#endif // TYPES_H

