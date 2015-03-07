#define ROM_DEFINED
#include "cartridgeheader.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;


/*
 * Class that handles the ROM of GB programs
 */

class ROM {

public:
	ROM(string romPath);
	~ROM();

	bool loadFile(string path);

	// Cartridge header pointer getter and setter
	CartridgeHeader * cartridgeHeader();
    void setHeader(CartridgeHeader *cHeader);	

	// Input file stream object getter and setter
	ifstream * fileStream();
	void setFileStream(ifstream *fileStream);

	CartridgeHeader *header;
private:
	ifstream *_fileStream;
};

