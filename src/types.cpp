#include <iostream>
#include "textHelper.hpp"

using namespace std;

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
	if(beginsWith(command, "bool ")){
		return(true);
	}
	if(beginsWith(command, "bool* ")){
		return(true);
	}
	if(beginsWith(command, "unsigned ")){
		return(true);
	}
	if(beginsWith(command, "signed ")){
		return(true);
	}
	if(beginsWith(command, "auto ")){
		return(true);
	}
	return(false);
}