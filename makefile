#blitzboy: main.o cpu.o memoryrouter.o
#	g++ main.o cpu.o memoryrouter.o -o blitzboy

blitzboy: main.o cpu.o memorybankcontroller.o memoryrouter.o rom.o cartridgeheader.o
	g++ main.o cpu.o memorybankcontroller.o memoryrouter.o rom.o cartridgeheader.o -o blitzboy

main.o: main.h main.cpp
	g++ -c main.cpp -o main.o

cpu.o: cpu.h cpu.cpp
	g++ -c cpu.cpp -o cpu.o

memorybankcontroller.o: memorybankcontroller.h memorybankcontroller.cpp
	g++ -c memorybankcontroller.cpp -o memorybankcontroller.o

memoryrouter.o: memoryrouter.h memoryrouter.cpp
	g++ -c memoryrouter.cpp -o memoryrouter.o

rom.o: rom.h rom.cpp
	g++ -c rom.cpp -o rom.o

cartridgeheader.o: cartridgeheader.h cartridgeheader.cpp
	g++ -c cartridgeheader.cpp -o cartridgeheader.o
