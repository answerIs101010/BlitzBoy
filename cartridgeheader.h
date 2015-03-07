#include <cstring>
#include <iostream>
#include "constants.h"

/*
 * Class that represents the Cartridge Header of a rom
 */

class CartridgeHeader {

public:
	CartridgeHeader(char data[]);
	~CartridgeHeader();

	// Entry point getter and setter
	char * entryPoint();
	bool setEntryPoint(char data[]);

	// Nintendo Logo getter and setter
	char * nintendoLogo(); 
	bool setNintendoLogo(char data[]);

	// Title getter and setter
	char * title();
	bool setTitle(char data[]);

	// Manufacturer Code getter and setter
	char * manufacturerCode();
	bool setManufacturerCode(char data[]);

	// New license code getter and setter
	char * newLicenseCode();
	bool setNewLicenseCode(char data[]);

	// SGB Flag getter and setter
	char sgbFlag();
	void setSgbFlag(char data);

	// Cartridge Type getter and setter
	char cartridgeType();
	void setCartridgeType(char data);

	// ROM size getter and setter
	char romSize();
	void setRomSize(char data);

	// RAM size getter and setter
	char ramSize();
	void setRamSize(char data);

	// Destination code getter and setter
	char destinationCode();
	void setDestinationCode(char data);

	// Old license code getter and setter
	char oldLicenseCode();
	void setOldLicenseCode(char data);

	// Mask ROM version number getter and setter
	char maskRomVersionNumber();
	void setMaskRomVersionNumber(char data);

	// Header checksum getter and setter
	char headerChecksum();
	void setHeaderChecksum(char data);

	// Global checksum getter and setter
	char * globalChecksum();
	bool setGlobalChecksum(char data[]);

	void printlol();
private:
	char _entryPoint[ENTRY_POINT_LENGTH];
	char _nintendoLogo[NINTENDO_LOGO_LENGTH];
	char _title[TITLE_LENGTH];
	char _manufacturerCode[MANUFACTURER_CODE_LENGTH];
	char _newLicenseCode[NEW_LICENSE_CODE_LENGTH];
	char _sgbFlag;
	char _cartridgeType;
	char _romSize;
	char _ramSize;
	char _destinationCode;
	char _oldLicenseCode;
	char _maskRomVersionNumber;
	char _headerChecksum;
	char _globalChecksum[GLOBAL_CHECKSUM_LENGTH];
};
