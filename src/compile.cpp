#include <iostream>
#include "file.hpp"
#include "file.h"

using namespace std;



void compile(string filename) {
	string command;
	command = "g++ " + filename + " -o " + filename + ".out";
	//printf(command);
	system(command.c_str());
}

void compileRun(string filename) {
	compile(filename);
	string command;
	command = filename + ".out";
	if(fileExists(command.c_str())) {
		system(command.c_str());
	} else {
		//cout<<"Error"<<endl;
	}
	//cout<<command<<endl;
}

string formatForCommands(string includes, string variables, string commands, string functions) {
	string command;
	command = includes + "\n" + functions + "\n\nint main(){\n\n" + variables + "\n" + commands + "\n\nreturn(0);}";
	//cout<<command<<endl;
	return(command);
}