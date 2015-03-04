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
	delete _header;
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
			
	} else {
		return false;
	}
	return true;
}

CartridgeHeader* ROM::header() {
	return _header;
}

void ROM::setHeader(CartridgeHeader *header) {
	_header = header;
}

ifstream* ROM::fileStream() {
	return _fileStream;
}

void ROM::setFileStream(ifstream *fileStream) {
	_fileStream = fileStream;
} 

