/* 8-bit CPU header data */
#ifndef PROCESSER_H
#define PROCESSER_H

typedef struct instruction {
	unsigned char opcode;
    unsigned short args;
	// OP_SIZE is 2 bytes per instruction
} instruction;

/* Available opcodes initialization  */
extern instruction CLS;  // Clear Screen
extern instruction RET;  // Return from subroutine
extern instruction JMP;  // Jump to 16-bit address address
extern instruction CALL; // Call subroutine
extern int testvar;
#endif
