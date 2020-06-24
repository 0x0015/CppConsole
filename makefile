all:
	g++ src/main.cpp src/compile.cpp src/file.c src/file.cpp src/textHelper.cpp src/customCommands.cpp src/flowLogic.cpp src/functions.cpp -lstdc++fs -o cppconsole

clean:
	rm cppterm
