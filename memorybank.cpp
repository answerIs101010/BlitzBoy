#include "memorybank.h"

MemoryBank::MemoryBank()
{
	for (int i = 0; i < BANK_LENGTH; i++) {
		_memory[i] = 0;
	}
}

MemoryBank::~MemoryBank()
{

}

char MemoryBank::readByte(int address)
{
	return _memory[address];
}

void MemoryBank::setByte(int address, char value)
{
	_memory[address] = value;
}

void MemoryBank::fillBank(char* data)
{
	strcpy(_memory, data);
}

