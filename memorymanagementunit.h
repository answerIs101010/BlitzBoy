#ifndef ROM_DEFINED
	#include "rom.h"
#endif
#include "memorybankcontroller.h"

/*
 * Class that represents the memory management unit.
 * This means the emulation of ROM Banks, Video, External and Work RAM
 *
 * Memory Map:
 * 0 0000 - 3FFF 16KB Bank 00 (in cartridge, fixed at bank 00)
 * 1 4000 - 7FFF 16KB Bank NN (in cartridge, switchable bank number)
 * 2 8000 - 9FFF 8KB Video RAM (VRAM)
 * 3 A000 - BFFF 8KB External RAM (in cartridge, switchable bank, if any)
 * 4 C000 - CFFF 4KB Work RAM Bank 0 (WRAM)
 * 5 D000 - DFFF 4KB Work RAM Bank 1 (WRAM)
 * 6 E000 - FDFF Same as C000 - DDFF (ECHO)
 * 7 FE00 - FE9F Sprite Attribute Table (OAM)
 * 8 FEA0 - FEFF Not Usable
 * 9 FF00 - FF7F I/O Ports
 * 10 FF80 - FFFE High RAM (HRAM)
 * 11 FFFF Interrupt Enable Register
 */

class MemoryManagementUnit {

public:
	MemoryManagementUnit(ROM *Rom);
	~MemoryManagementUnit();
	
	void initialize();

	// Manage operations
	int recalculateAddress(int address);
	int readFromBank(int address);

	// Read operations
	char readByte(int address);
	char readShort(int address);

	// Write operations
	bool writeByte(int address, char value);
	bool writeShort(int address, short value);
	void writeVRAMByte(int address, char value);
	void writeWRAM1Byte(int address, char value);
	void writeWRAM2Byte(int address, char value);
	void writeSpriteAttributeTableByte(int address, char value);
	void writeIOPortsByte(int address, char value);
	void writeHRAMByte(int address, char value);
	void writeInterruptEnableRegisterByte(char value);

	ROM* rom();
	void setROM(ROM *Rom);

	MemoryBankController* MBC();
	void setMBC(MemoryBankController *mbc);

private:
	ROM *_rom;
	MemoryBankController *_mbc;

	// Video RAM
	char _videoRAM[VIDEO_RAM_LENGTH];
	
	// Work RAM
	char _workRAM1[WORK_RAM_LENGTH];
	char _workRAM2[WORK_RAM_LENGTH];

	// Sprite Attribute Table
	char _spriteAttributeTable[SPRITE_ATTRIBUTE_TABLE_LENGTH];

	// I/O Ports
	char _ioPorts[IO_PORTS_LENGTH];

	// High RAM
	char _highRAM[HIGH_RAM_LENGTH];

	// Interrupt Enable Register
	char _interruptEnableRegister;
};
