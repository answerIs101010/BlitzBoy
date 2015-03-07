#include "memorybankcontroller.h"

MemoryBankController::MemoryBankController() {
	setMemoryBankIndex(0x0);
}

MemoryBankController::~MemoryBankController() {

}

void MemoryBankController::initialize()
{
	
}

int MemoryBankController::externalRamBankIndex()
{
	return _externalRamBankIndex;
}

void MemoryBankController::setExternalRamBankIndex(int index)
{
	_externalRamBankIndex = index;
}

int MemoryBankController::memoryBankIndex()
{
	return _memoryBankIndex;
}

bool MemoryBankController::setMemoryBankIndex(int index)
{
	if (index < 0x100) {
		_memoryBankIndex = index;
		return true;
	} else {
		return false;
	}
}

MemoryBank * MemoryBankController::memoryBank(int index)
{
	if (index < 0x100) {
		return _memoryBanks[index];
	} else {
		return 0;
	}
}

void MemoryBankController::setMemoryBank(int index, MemoryBank *memoryBank)
{
	_memoryBanks[_memoryBankIndex] = memoryBank;
}

int MemoryBankController::createMemoryBank()
{
	setMemoryBank(_memoryBankIndex, new MemoryBank());
	return _memoryBankIndex++;
}

