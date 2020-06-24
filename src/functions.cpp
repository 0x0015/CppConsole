#include <iostream>
#include "textHelper.hpp"
#include "flowLogic.hpp"
#include "customCommands.hpp"

using namespace std;

void addFunction(string* command, string* functions){
	string tempcmd = "";
	bool continuing = true;
	if(beginsWithInitializer(*command)){
		*functions = *functions + "\n" + *command;
		while(continuing){
		cout<<"	";
		//cin>>str;
		getline(cin, tempcmd);
		
		if(countFreq(tempcmd, "{") - countFreq(tempcmd, "}") == -1){
			continuing = false;
		}
		
		if(stringContains(tempcmd, "{")){
			if(beginsWith(tempcmd, "if(") || beginsWith(tempcmd, "for(") || beginsWith(tempcmd, "while(") || beginsWith(tempcmd, "do(")){
				bracket(&tempcmd);
			}
		}
		*functions = *functions + "\n" + tempcmd;
		}
	}
}