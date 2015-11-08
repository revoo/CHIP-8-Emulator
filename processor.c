/* Instruction implementation */
#include "processor.h"

//instruction CLS = { 0x0, 0x0E0 };  // Clear Screen
instruction CLS;
instruction RET;  // Return from subroutine
instruction JMP;  // Jump to 16-bit address address
instruction CALL; // Call subroutine
int testvar = 5;
