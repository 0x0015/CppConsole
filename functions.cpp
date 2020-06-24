#include <iostream>

using namespace std;

extern bool beginsWith(string source, string substring);
extern bool stringContains(string source, string substring);
extern int countFreq(const string pat, const string txt);

extern void bracket(string* command);

extern bool beginsWithInitializer(string command);

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