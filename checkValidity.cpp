#include <iostream>

using namespace std;

extern bool stringContains(string source, string substring);
extern int countFreq(const string pat, const string txt);

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
