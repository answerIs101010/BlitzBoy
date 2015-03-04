#include "cartridgeheader.h"

CartridgeHeader::CartridgeHeader(char data[]) {
	// index variable for the char array
	int index = 0;

	// create a char array, assign the data to it and set the entry point bytes to it
	char entryPointData[ENTRY_POINT_LENGTH];
	for (int i = 0; i < ENTRY_POINT_LENGTH; i++, index++) {
		entryPointData[i] = data[index];
	}
	setEntryPoint(entryPointData);

	// create a char array, assign the data to it and set the nintendo logo bytes to it
	char nintendoLogoData[NINTENDO_LOGO_LENGTH];
	for (int i = 0; i < NINTENDO_LOGO_LENGTH; i++, index++) {
		nintendoLogoData[i] = data[index];
	}
	setNintendoLogo(nintendoLogoData);

	// create a char array, assign the data to it and set the title bytes to it
	char titleData[TITLE_LENGTH];
	for (int i = 0; i < TITLE_LENGTH; i++, index++) {
		titleData[i] = data[index];
	}
	setTitle(titleData);

	// create a char array, assign the data to it and set the manufacturer code bytes to it
	char manufacturerCodeData[MANUFACTURER_CODE_LENGTH];
	for (int i = 0; i < MANUFACTURER_CODE_LENGTH; i++, index++) {
		manufacturerCodeData[i] = data[index];
	}
	setManufacturerCode(manufacturerCodeData);

	// create a char array, assign the data to it and set the new license code bytes to it
	char newLicenseCodeData[NEW_LICENSE_CODE_LENGTH];
	for (int i = 0; i< NEW_LICENSE_CODE_LENGTH; i++, index++) {
		newLicenseCodeData[i] = data[index];
	}
	setNewLicenseCode(newLicenseCodeData);

	setSgbFlag(data[index++]); // set SGB flag to data[index] and increment the index
	setCartridgeType(data[index++]); // set cartridge type to data[index] and increment the index
	setRomSize(data[index++]); // set ROM size to data[index] and increment the index
	setRamSize(data[index++]); // set RAM size to data[index] and increment the index
	setDestinationCode(data[index++]); // set the destination code to data[index] and increment the index
	setOldLicenseCode(data[index++]); // set the old license code to data[index] and increment the index
	setMaskRomVersionNumber(data[index++]); // set the mask ROM version number to data[index] and increment the index
	setHeaderChecksum(data[index++]); // set the header checksum to data[index] and increment the index

	// create a char array, assign the data to it and set the global checksum bytes to it
	char globalChecksumData[GLOBAL_CHECKSUM_LENGTH];
	for (int i = 0; i < GLOBAL_CHECKSUM_LENGTH; i++, index++) {
		globalChecksumData[i] = data[index];
	}
	setGlobalChecksum(globalChecksumData);
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

