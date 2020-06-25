#include <experimental/filesystem>
#include <iostream>

using namespace std;

void removeDirectory(string directory) {
	std::error_code errorCode;
	if (!std::experimental::filesystem::remove(directory, errorCode)) {
		//std::cout << errorCode.message() << std::endl;
	}
	std::error_code errorCode2;
	if (!std::experimental::filesystem::remove_all(directory, errorCode2)) {
		//std::cout << errorCode2.message() << std::endl;
	}

}