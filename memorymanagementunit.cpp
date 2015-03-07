#include "memorymanagementunit.h"

MemoryManagementUnit::MemoryManagementUnit(ROM *Rom) {
	setMBC(new MemoryBankController());
	setROM(Rom);
	initialize();
}

MemoryManagementUnit::~MemoryManagementUnit() {

}

void MemoryManagementUnit::initialize()
{
	MBC()->createMemoryBank(); // 16kb ROM Bank 00 fixed (Cartridge)

	for (int i = 0; i < VIDEO_RAM_LENGTH; i++) {
		writeVRAMByte(i, 0);
	}

	for (int i = 0; i < WORK_RAM_LENGTH; i++) {
		writeWRAM1Byte(i, 0);
	}

	for (int i = 0; i < WORK_RAM_LENGTH; i++) {
		writeWRAM2Byte(i, 0);
	}

	for (int i = 0; i < SPRITE_ATTRIBUTE_TABLE_LENGTH; i++) {
		writeSpriteAttributeTableByte(i, 0);
	}

	for (int i = 0; i < IO_PORTS_LENGTH; i++) {
		writeIOPortsByte(i, 0);
	}

	for (int i = 0; i < HIGH_RAM_LENGTH; i++) {
		writeHRAMByte(i, 0);
	}
	
	_interruptEnableRegister = 0;
}

int MemoryManagementUnit::recalculateAddress(int address) {
}

int MemoryManagementUnit::readFromBank(int address) {
	switch(address & 0xF000) {
		case 0x0000:
		case 0x1000:
		case 0x2000:
		case 0x3000:
			return MBC()->memoryBank(0)->readByte(address);
		case 0x4000:
		case 0x5000:
		case 0x6000:
		case 0x7000:
			return MBC()->memoryBank(MBC()->memoryBankIndex())->readByte(address - 0x4000);
		case 0x8000:
		case 0x9000:
		case 0xA000:
		case 0xB000:
			// Fix External Cartridge RAM :D
			return MBC()->memoryBank(MBC()->memoryBankIndex())->readByte(address - 0x4000);
		case 0xC000:
			return _workRAM1[address - 0xC000];
		case 0xD000:
			return _workRAM2[address - 0xD000];
		case 0xE000:
			return _workRAM1[address - 0xE000];
		case 0xF000:
			if (address < 0xFE00) {
				return _workRAM2[address - 0xF000];
			} else if (address < 0xFEA0) {
				return _spriteAttributeTable[address - 0xFE00];
			} else if (address > 0xFEFF && address < 0xFF80) {
				return _ioPorts[address - 0xFF00];
			} else if (address < 0xFFFF) {
				return _highRAM[address - 0xFF80];
			} else {
				return _interruptEnableRegister;
			}
		default:
			std::cout << "Unknown address: " << address << '\n';
	}
}

bool MemoryManagementUnit::writeByte(int address, char value)
{
	return true;
}

bool MemoryManagementUnit::writeShort(int address, short value)
{
	return true;
}

inline void MemoryManagementUnit::writeVRAMByte(int address, char value)
{
	_videoRAM[address] = value;
}
void MemoryManagementUnit::writeHRAMByte(int address, char value)
{
	_highRAM[address] = value;
}

void MemoryManagementUnit::writeIOPortsByte(int address, char value)
{
	_ioPorts[address] = value;
}

void MemoryManagementUnit::writeInterruptEnableRegisterByte(char value)
{
	_interruptEnableRegister = value;
}

void MemoryManagementUnit::writeSpriteAttributeTableByte(int address, char value)
{
	_spriteAttributeTable[address] = value;
}

void MemoryManagementUnit::writeWRAM1Byte(int address, char value)
{
	_workRAM1[address] = value;
}

void MemoryManagementUnit::writeWRAM2Byte(int address, char value)
{
	_workRAM2[address] = value;
}

char MemoryManagementUnit::readByte(int address)
{
	return 'a';
}

char MemoryManagementUnit::readShort(int address)
{
	return 'a';
}

ROM* MemoryManagementUnit::rom()
{
	return _rom;
}

void MemoryManagementUnit::setROM(ROM *Rom)
{
	_rom = Rom;
}

MemoryBankController* MemoryManagementUnit::MBC()
{
	return _mbc;
}

void MemoryManagementUnit::setMBC(MemoryBankController *mbc)
{
	_mbc = mbc;
}

