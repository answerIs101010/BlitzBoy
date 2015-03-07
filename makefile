#blitzboy: main.o cpu.o memorymanagementunit.o
#	g++ main.o cpu.o memorymanagementunit.o -o blitzboy

blitzboy: main.o cpu.o memorybankcontroller.o memorybank.o memorymanagementunit.o rom.o cartridgeheader.o
	g++ main.o cpu.o memorybankcontroller.o memorybank.o memorymanagementunit.o rom.o cartridgeheader.o -o blitzboy

debug: main.o cpu.o memorybankcontroller.o memorybank.o memorymanagementunit.o rom.o cartridgeheader.o
	g++ main.o cpu.o memorybankcontroller.o memorybank.o memorymanagementunit.o rom.o cartridgeheader.o -g main.cpp -o blitzboy.debug

main.o: main.h main.cpp
	g++ -c main.cpp -o main.o

cpu.o: cpu.h cpu.cpp
	g++ -c cpu.cpp -o cpu.o

memorybankcontroller.o: memorybankcontroller.h memorybankcontroller.cpp
	g++ -c memorybankcontroller.cpp -o memorybankcontroller.o

memorybank.o: memorybank.h memorybank.cpp
	g++ -c memorybank.cpp -o memorybank.o

memorymanagementunit.o: memorymanagementunit.h memorymanagementunit.cpp
	g++ -c memorymanagementunit.cpp -o memorymanagementunit.o

rom.o: rom.h rom.cpp
	g++ -c rom.cpp -o rom.o

cartridgeheader.o: cartridgeheader.h cartridgeheader.cpp
	g++ -c cartridgeheader.cpp -o cartridgeheader.o
