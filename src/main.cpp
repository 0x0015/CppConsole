#include <iostream>
#include "file.h"
#include "compile.hpp"
#include "file.hpp"
#include "customCommands.hpp"

using namespace std;



int main() {
	string str;
	int times = 0;
	FILE *fp;

	string filename;

	string text;
	
	bool doCompile = true;
	
	string includes = "#include <iostream>\n";
	
	string variables = "";
	
	string functions = "";
	
	removeDirectory("temp");
	
	for(;;) {
		cout<<"\n>  ";
		//cin>>str;
		getline(cin, str);
		
		doCompile = checkCommand(&str, &includes, &variables, &functions);
		
		if(doCompile){
		text = formatForCommands(includes, variables, str, functions);
		//cout<<text;

		//cout<<endl;
		filename = "temp/" + to_string(times) + "tmp.c";
		//cout<<filename<<endl;
		
		fp = openFile(filename.c_str(), "w+");
		appendToFile(fp, text.c_str());
		closeFile(fp);
		
		compileRun(filename);
		times++;
		}
	}
	return 0;
}