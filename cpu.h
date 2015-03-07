#include "memorymanagementunit.h"

/*
 * Class that holds the virtual CPU
 */

class CPU {

public:
	CPU();
	~CPU();
	
	// method for emulation  control
	bool startEmulation();
	bool pauseEmulation();
	bool quitEmulation();


	// method for variable initialization	
	void initialize();
	
	// Memory Management Unit getter and setter
	MemoryManagementUnit * MMU();
	void setMMU(MemoryManagementUnit *mmu);

	// ROM getter and setter
	ROM* rom();
	void setROM(ROM *Rom);

	// A register getter and setter
	char rA();
	void setRA(unsigned char value);

	// B register getter and setter
	char rB();
	void setRB(unsigned char value);

	// C register getter and setter
	char rC();
	void setRC(unsigned char value);

	// D register getter and setter
	char rD();
	void setRD(unsigned char value);

	// E register getter and setter
	char rE();
	void setRE(unsigned char value);

	// F register getter and setter
	char rF();
	void setRF(unsigned char value);

	// H register getter and setter
	char rH();
	void setRH(unsigned char value);

	// L register getter and setter
	char rL();
	void setRL(unsigned char value);

	// Stack Poiner getter and setter
	short SP();
	void setSP(unsigned short value);

	// Program counter getter and setter
	short PC();
	void setPC(unsigned short value);

	// Flag register operations
	
	// Zero flag getter and setter
	bool zeroFlag();
	void setZeroFlag(bool value);
	
	// Subtract Flag getter and setter
	bool subtractFlag();
	void setSubtractFlag(bool value);
	
	// Half carry flag getter and setter
	bool halfCarryFlag();
	void setHalfCarryFlag(bool value);
	
	// Carry flag getter and setter
	bool carryFlag();
	void setCarryFlag(bool value);

private:
	// Memory Management Unit
	MemoryManagementUnit *_mmu;
	// ROM - Read Only Memory of the game
	ROM *_rom;
	// Registers
	unsigned char _rA;
	unsigned char _rB;
	unsigned char _rC;
	unsigned char _rD;
	unsigned char _rE;
	unsigned char _rF;
	unsigned char _rH;
	unsigned char _rL;
	unsigned short _SP; // Stack pointer
	unsigned short _PC; // Program counter
	unsigned char _FR; // Flag register

};
