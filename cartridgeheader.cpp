#include "cartridgeheader.h"

CartridgeHeader::CartridgeHeader(char data[]) {
	
	// index variable for the char array
	int index = 0;

	// create a char array, assign the data to it and set the entry point bytes to it
	for (int i = 0; i < ENTRY_POINT_LENGTH; i++, index++) {
		_entryPoint[i] = data[index];
	}

	// create a char array, assign the data to it and set the nintendo logo bytes to it
	for (int i = 0; i < NINTENDO_LOGO_LENGTH; i++, index++) {
		_nintendoLogo[i] = data[index];
	}

	// create a char array, assign the data to it and set the title bytes to it
	for (int i = 0; i < TITLE_LENGTH; i++, index++) {
		_title[i] = data[index];
	}

	// create a char array, assign the data to it and set the manufacturer code bytes to it
	for (int i = 0; i < MANUFACTURER_CODE_LENGTH; i++, index++) {
		_manufacturerCode[i] = data[index];
	}

	// create a char array, assign the data to it and set the new license code bytes to it
	for (int i = 0; i< NEW_LICENSE_CODE_LENGTH; i++, index++) {
		_newLicenseCode[i] = data[index];
	}

	_sgbFlag = data[index++]; // set SGB flag to data[index] and increment the index
	_cartridgeType = data[index++]; // set cartridge type to data[index] and increment the index
	_romSize = data[index++]; // set ROM size to data[index] and increment the index
	_ramSize = data[index++]; // set RAM size to data[index] and increment the index
	_destinationCode = data[index++]; // set the destination code to data[index] and increment the index
	_oldLicenseCode = data[index++]; // set the old license code to data[index] and increment the index
	_maskRomVersionNumber = data[index++]; // set the mask ROM version number to data[index] and increment the index
	_headerChecksum = data[index++]; // set the header checksum to data[index] and increment the index

	// create a char array, assign the data to it and set the global checksum bytes to it
	for (int i = 0; i < GLOBAL_CHECKSUM_LENGTH; i++, index++) {
		_globalChecksum[i] = data[index];
	}
}

CartridgeHeader::~CartridgeHeader() {

}

char CartridgeHeader::cartridgeType()
{
	return _cartridgeType;
}

char CartridgeHeader::destinationCode()
{
	return _destinationCode;
}

char CartridgeHeader::headerChecksum()
{
	return _headerChecksum;
}

char CartridgeHeader::maskRomVersionNumber()
{
	return _maskRomVersionNumber;
}

char CartridgeHeader::oldLicenseCode()
{
	return _oldLicenseCode;
}

char CartridgeHeader::ramSize()
{
	return _ramSize;
}

char CartridgeHeader::romSize()
{
	return _romSize;
}

char CartridgeHeader::sgbFlag()
{
	return _sgbFlag;
}

char * CartridgeHeader::entryPoint()
{
	return _entryPoint;
}

char * CartridgeHeader::globalChecksum()
{
	return _globalChecksum;
}

char * CartridgeHeader::manufacturerCode()
{
	return _manufacturerCode;
}

char * CartridgeHeader::newLicenseCode()
{
	return _newLicenseCode;
}

char * CartridgeHeader::nintendoLogo()
{
	return _nintendoLogo;
}

char * CartridgeHeader::title()
{
	return _title;
}

void CartridgeHeader::setCartridgeType(char data)
{
	_cartridgeType = data;
}

void CartridgeHeader::setDestinationCode(char data)
{
	_destinationCode = data;
}

bool CartridgeHeader::setEntryPoint(char data[])
{
	if (sizeof(data) == 0x04) {
		strcpy(_entryPoint, data);
		return true;
	} else {
		return false;
	}
}

bool CartridgeHeader::setGlobalChecksum(char data[])
{
	if (sizeof(data) == 0x02) {
		strcpy(_globalChecksum, data);
		return true;
	} else {
		return false;
	}
}

void CartridgeHeader::setHeaderChecksum(char data)
{
	_headerChecksum = data;
}

bool CartridgeHeader::setManufacturerCode(char data[])
{
	if (sizeof(data) == 0x04) {
		strcpy(_manufacturerCode, data);
		return true;
	} else {
		return false;
	}
}

void CartridgeHeader::setMaskRomVersionNumber(char data)
{
	_maskRomVersionNumber = data;
}

bool CartridgeHeader::setNewLicenseCode(char data[])
{
	if (sizeof(data) == 0x02) {
		strcpy(_newLicenseCode, data);
		return true;
	} else {
		return false;
	}
}

bool CartridgeHeader::setNintendoLogo(char data[])
{
	if (sizeof(data) == 0x30) {
		strcpy(_nintendoLogo, data);
		return true;
	} else {
		return false;
	}
}

void CartridgeHeader::setOldLicenseCode(char data)
{
	_oldLicenseCode = data;
}

void CartridgeHeader::setRamSize(char data)
{
	_ramSize = data;
}

void CartridgeHeader::setRomSize(char data)
{
	_romSize = data;
}

void CartridgeHeader::setSgbFlag(char data)
{
	_sgbFlag = data;
}

bool CartridgeHeader::setTitle(char data[])
{
	if (sizeof(data) == 0x10) {
		strcpy(_title, data);
		return true;
	} else {
		return false;
	}
}

void CartridgeHeader::printlol() {
}
