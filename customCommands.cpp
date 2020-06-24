#include <iostream>
using namespace std;

extern bool beginsWith(string source, string substring);
extern bool stringContains(string source, string substring);
extern int countFreq(const string pat, const string txt);

extern void bracket(string* command);

extern void addFunction(string* command, string* functions);

bool beginsWithInitializer(string command);

bool checkCommand(string* command, string* includes, string* variables, string* functions){
	if(beginsWith(*command, "exit")){
		exit(0);	
	}
	if(beginsWith(*command, "#include ")){
		*includes = *includes + *command + "\n";
		cout<<"Adding : " + *command<<endl;
		return(false);
	}
	if(beginsWith(*command, "using namespace ")){
		*includes = *includes + *command + "\n";
		cout<<"Adding : " + *command<<endl;
		return(false);
	}
	if(stringContains(*command, "{")){
		if(beginsWith(*command, "if(") || beginsWith(*command, "for(") || beginsWith(*command, "while(") || beginsWith(*command, "do(")){
		bracket(command);
		return(true);	
		}
		if(beginsWithInitializer(*command)){
			addFunction(command, functions);
			return(false);
		}
	}
	if(beginsWithInitializer(*command)){
		*variables = *variables + *command + "\n";
		return(false);
	}
	if(countFreq(*command, "=") == 1){
		*variables = *variables + *command + "\n";
		return(false);
	}
	return(true);
}

bool beginsWithInitializer(string command){
	if(beginsWith(command, "int ")){
		return(true);
	}
	if(beginsWith(command, "int* ")){
		return(true);
	}
	if(beginsWith(command, "string ")){
		return(true);
	}
	if(beginsWith(command, "string* ")){
		return(true);
	}
	if(beginsWith(command, "float ")){
		return(true);
	}
	if(beginsWith(command, "float* ")){
		return(true);
	}
	if(beginsWith(command, "char ")){
		return(true);
	}
	if(beginsWith(command, "char* ")){
		return(true);
	}
	if(beginsWith(command, "double ")){
		return(true);
	}
	if(beginsWith(command, "double* ")){
		return(true);
	}
	if(beginsWith(command, "void ")){
		return(true);
	}
	if(beginsWith(command, "void* ")){
		return(true);
	}
	return(false);
}