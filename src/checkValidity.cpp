#include <iostream>
#include "textHelper.hpp"

using namespace std;


bool validLine(string command){
	if(command.back() == ";"){
		return(true);
	}
	if(command.back() == "{"){
		return(true);
	}
	if(command.back() == "("){
		return(true);
	}
	if(command.back() == "}"){
		return(true);
	}
	if(command.back() == ")"){
		return(true);
	}
	return(false);
}
