#include <iostream>
#include "textHelper.hpp"
#include "flowLogic.hpp"
#include "functions.hpp"
#include "types.hpp"

using namespace std;

bool beginsWithInitializer(string command);

bool checkCommand(string* command, string* includes, string* variables, string* functions) {
	if(beginsWith(*command, "exit")) {
		exit(0);
	}
	if(beginsWith(*command, "#include ")) {
		*includes = *includes + *command + "\n";
		cout<<"Adding : " + *command<<endl;
		return(false);
	}
	if(beginsWith(*command, "using namespace ")) {
		*includes = *includes + *command + "\n";
		cout<<"Adding : " + *command<<endl;
		return(false);
	}
	if(stringContains(*command, "{")) {
		if(beginsWith(*command, "if(") || beginsWith(*command, "for(") || beginsWith(*command, "while(") || beginsWith(*command, "do(")) {
			bracket(command);
			return(true);
		}
		if(beginsWithInitializer(*command)) {
			addFunction(command, functions);
			return(false);
		}
	}
	if(beginsWithInitializer(*command)) {
		*variables = *variables + *command + "\n";
		return(false);
	}
	if(countFreq(*command, "=") == 1) {
		*variables = *variables + *command + "\n";
		return(false);
	}
	return(true);
}

