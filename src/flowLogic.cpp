#include <iostream>
#include "textHelper.hpp"

using namespace std;



void bracket(string* command, int extraindent = 0) {
	int  time = 1;
	string inputstr;

	if(countFreq(*command, "{") - countFreq(*command, "}") == 0) {
		return;
	}

	while(time > 0) {

		for(int i=0; i<time+extraindent; i++) {
			cout<<"	";
		}

		getline(cin, inputstr);
		//out<<"{" + to_string(countFreq(inputstr, "{")) + "}" + to_string(countFreq(inputstr, "}"))<<endl;
		//cout<<inputstr + " " + to_string(time)<<endl;
		*command = *command + "\n" + inputstr;

		time = time + countFreq(inputstr, "{") - countFreq(inputstr, "}");

	}
}