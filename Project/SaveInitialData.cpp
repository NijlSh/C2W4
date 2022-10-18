#include "SaveInitialData.h"

void SaveInitialData(std::string text)
{
	std::string file_name = "";
	std::ofstream file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	
	try 
	{
		file_name = GetFileName(output);
		file.open(file_name);
		file << text;
	}
	catch (std::exception&) 
	{
		std::cout << "Ошибка доступа." << std::endl;
	}
	file.close();
}
