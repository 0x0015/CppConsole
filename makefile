all:
	g++ main.cpp compile.cpp file.c file.cpp textHelper.cpp customCommands.cpp flowLogic.cpp functions.cpp -lstdc++fs -o cppconsole

clean:
	rm cppterm
