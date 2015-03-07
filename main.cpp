#include "main.h"

using namespace std;

int main() {
	cpu = new CPU();
	rom = new ROM("cpu_instrs.gb");
	mmu = new MemoryManagementUnit(rom);
	cpu->setMMU(mmu);
	cpu->setROM(mmu->rom());

	return 0;	
}
