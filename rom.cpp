#include "rom.h"

ROM::ROM(string romPath) {
	try {
		if (!loadFile(romPath)) {
			throw 1;
		}
	} catch(int error) {
		cout << "Error Nr. " << error << ". Look at the documentation for more details." << '\n';
	}
}

ROM::~ROM() {
	delete header;
	delete _fileStream;
}

bool ROM::loadFile(string path) {
	setFileStream(new ifstream());
	fileStream()->open(path.c_str(), ios_base::in | ios_base::binary);
	if (fileStream()->is_open()) {
		fileStream()->seekg(0x0100);
		char headerBytes[HEADER_LENGTH];
		fileStream()->getline(headerBytes, HEADER_LENGTH);
		setHeader(new CartridgeHeader(headerBytes));
		fileStream()->close();
	} else {
		return false;
	}
	return true;
}

CartridgeHeader* ROM::cartridgeHeader() {
	return header;
}

void ROM::setHeader(CartridgeHeader *cHeader) {
	header = cHeader;
}

ifstream* ROM::fileStream() {
	return _fileStream;
}

void ROM::setFileStream(ifstream *fileStream) {
	_fileStream = fileStream;
} 

