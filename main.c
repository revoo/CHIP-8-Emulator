/* CHIP-8 Virtual Machine Emulator */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
	fread(hex_buffer, BYTES_PER_INS, input_size / 2, hex_file);
	printf("Success!\n");
	printf("found instruction: %x\n", hex_buffer[0]);
	printf("Input file processed, closing... ");
	fclose((hex_file));
	printf("file descriptor closed.\n");
	printf("Disassembling into pseudo-x86 assembly...\n");
	for (unsigned i = 0; i < input_size; i++) {
		switch (hex_buffer[i]) {
		case 0x00: {

		}
		}
	}

}
