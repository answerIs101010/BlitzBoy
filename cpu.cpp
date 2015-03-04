#include "cpu.h"

CPU::CPU() {
	initialize();	
}

CPU::~CPU() {

}

void CPU::initialize() {
	_memory = new unsigned char[8192];
	_videoMemory = new unsigned char[8192];
	_FR = 0;
	setRA(0);	
	setRB(0);	
	setRC(0);	
	setRD(0);	
	setRE(0);	
	setRF(0);	
	setRH(0);	
	setRL(0);
	setSP(0xFFFE);
	setPC(0x100);	
}

inline char CPU::rA() {
	return _rA;
}

inline void CPU::setRA(unsigned char value) {
	_rA = value;	
}

inline char CPU::rB() {
	return _rB;
}

inline void CPU::setRB(unsigned char value) {
	_rB = value;
}

inline char CPU::rC() {
	return _rC;
}

inline void CPU::setRC(unsigned char value) {
	_rC = value;
}

inline char CPU::rD() {
	return _rD;
}

inline void CPU::setRD(unsigned char value) {
	_rD = value;
}

inline char CPU::rE() {
	return _rE;
}

inline void CPU::setRE(unsigned char value) {
	_rE = value;
}

inline char CPU::rF() {
	return _rF;
}

inline void CPU::setRF(unsigned char value) {
	_rF = value;
}

inline char CPU::rH() {
	return _rH;
}

inline void CPU::setRH(unsigned char value) {
	_rH = value;
}

inline char CPU::rL() {
	return _rL;
}

inline void CPU::setRL(unsigned char value) {
	_rL = value;
}

inline short CPU::SP() {
	return _SP;
}

inline void CPU::setSP(unsigned short value) {
	_SP = value;
}

inline short CPU::PC() {
	return _PC;
}

inline void CPU::setPC(unsigned short value) {
	_PC = value;	
}

inline bool CPU::zeroFlag() {
	return (_FR & 0x80) >> 7;
}

inline void CPU::setZeroFlag(bool value) {
	_FR |= 0x80;
}

inline bool CPU::subtractFlag() {
	return (_FR & 0x40) >> 6;
}

inline void CPU::setSubtractFlag(bool value) {
	_FR |= 0x40;
}

inline bool CPU::halfCarryFlag() {
	return (_FR & 0x20) >> 5;
}

inline void CPU::setHalfCarryFlag(bool value) {
	_FR |= 0x20;
}

inline bool CPU::carryFlag() {
	return (_FR & 0x10) >> 4;
}

inline void CPU::setCarryFlag(bool value) {
	_FR |= 0x10;
}

