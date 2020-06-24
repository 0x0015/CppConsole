#include <iostream>
using namespace std;

bool beginsWith(string source, string substring){
	if(source.size()<substring.size()){
		return(false);
	}
	for(std::string::size_type i = 0; i < substring.size(); ++i) {
	    if(source[i] != substring[i]){
			return(false);
		}
	}
	return(true);
}

bool stringContains(string source, string substring){
	if (source.find(substring) != std::string::npos) {
	    return(true);
	}
	return(false);
}

int countFreq(const string str, const string sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}