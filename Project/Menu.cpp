#include "Menu.h"

int AscUserInputType()
{
	int variant;
	std::cout << "¬ведите 1 дл€ консольного ввода" << std::endl
		<< "¬ведите 2 дл€ ввода из файла" << std::endl
		<< "¬ведите 3 дл€ завершени€ работы программы" << std::endl;
	variant = CheckMenu(3);
	return variant;
}

int AscOutputType()
{
	int variant;
	std::cout << "¬ведите 1 дл€ консольного вывода" << std::endl
		<< "¬ведите 2 дл€ вывода в файла" << std::endl;
	variant = CheckMenu(2);
	return variant;
}


int AscInitialDataSaveMenu()
{
	int variant;

		std::cout << "1 - сохранить исходные данные" << std::endl
		<< "2 - не сохран€ть исходные данные" << std::endl;
	variant = CheckMenu(2);
	return variant;
}
