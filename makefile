all:
	g++ src/main.cpp src/compile.cpp src/file.c src/file.cpp src/textHelper.cpp src/customCommands.cpp src/flowLogic.cpp src/functions.cpp src/types.cpp -lstdc++fs -o cppconsole

clean:
	rm cppterm

win:
	x86_64-w64-mingw32-g++ src/main.cpp src/compile.cpp src/file.c src/file.cpp src/textHelper.cpp src/customCommands.cpp src/flowLogic.cpp src/functions.cpp src/types.cpp -lstdc++fs -static -static-libgcc -static-libstdc++ -o cppconsole
