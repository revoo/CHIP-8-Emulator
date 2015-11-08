/* CHIP-8 Virtual Machine Emulator */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "processor.h"

// Bytes per instruction, in the case of CHIP-8 every instruction is 2 bytes
const uint8_t BYTES_PER_INS = 2;
const char FILE_PATH[] = "C:\\Users\\russ\\Desktop\\CHIP-8\\CHIP-8-ROMS\\PONG";

// Prototypes
uint8_t disassemble(char[]);

int main() {
	printf("*************************************************\n");
	printf("------------ Revoo's CHIP-8 Emulator ------------\n");
	printf("*************************************************\n");
	printf("Beginning initialization...\n");
	disassemble(FILE_PATH);
	getch();
	return 0;
}

/* CHIP-8 Disassembler: takes in a ROM CHIP-8 hex file and disassembles it to a pseudo-x86 assembler. */
uint8_t disassemble(const char file_path[]) {
	printf("Disassembling CHIP-8 binary file: %s\n", FILE_PATH);
	char* hex_buffer;
	long input_size = 0;
	FILE* hex_file;
	// Open file in read-binary mode since it's a hexadecimal assembled file
	printf("Opening file... ");
	hex_file = fopen(file_path, "rb");
	/* NULL check */
	if (!hex_file)
		return -1;
	printf("Success!\n");
	// Calculate size of hex input by moving file pointer to the end of the file, acquiring position, and rewinding it back to the start of the file
	printf("Calculating file size... ");
	fseek(hex_file, 0, SEEK_END);
	input_size = ftell(hex_file);
	rewind(hex_file);
	printf("Found %d bytes.\n", input_size);
	// Allocate buffer large enough for input file
	printf("Dynamically allocating %d bytes... ", input_size);
	hex_buffer =  (char*) malloc(input_size);
	printf("Success!\n");
	printf("Reading input file into local buffer... ");
	// Read the input file into the hex buffer which is a char array containing one byte of the two byte instruction
	fread(hex_buffer, 1, input_size, hex_file);
	printf("Success!\jn");
	printf("found instruction: %x\n", hex_buffer[0]);
	printf("Input file processed, closing... ");
	fclose((hex_file));
	printf("file descriptor closed.\n");
	printf("Disassembling into pseudo-x86 assembly...\n");

	// Print out hex dump of the file
	for (long i = 0; i < input_size; i++) {
		// printf converts %x to an int so values higher then 0x80 are viewed as negative and added with ffffff sign bits so AND it with 0xff
		printf("%02x ", hex_buffer[i] & 0xff);
		if (((i + 1) % 18) == 0) printf("\n");
	}
	printf("\n");
	// Switch statement for various op-codes of the architecture
	/*uint16_t address = 0x0000;
	for (unsigned i = 0; i < input_size; i += 2) {
		printf("%04x", address);
		switch (hex_buffer[i] >> 4) {
			case 0x0: {
				// Clear Screen 00E0
				if (hex_buffer[i + 1] & 0xff == 0xE0) printf(" CLS");
				// Return from subroutine 00EE
				else printf(" RET");
				break;
			}
			case 0x1: printf("JMP %x%02x", hex_buffer[i] << 4, hex_buffer[i + 1] & 0xff); break;
		}
		printf("\n");
		// Increment address by 2 bytes
		address += 0x0002;
	}*/
	//printf("%x \n", (hex_buffer[0] >> 0) & 0xf);
	printf(testvar);
	

}
