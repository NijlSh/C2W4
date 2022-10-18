#include "Check.h"
int CheckMenu(int items)
{
	std::string value_input;
	int value;
	while (true)
	{

		std::cout << "Ввод: ";
		std::getline(std::cin, value_input);
		std::cout << std::endl;
		std::cin.sync();

		try
		{
			value = stoi(value_input);
			if (value <= items && value >= 1)
				return value;
			else
				throw value;
		}
		catch (std::exception&)
		{

			std::cout << "Не существующий пункт меню. Повторите ввод." << std::endl;
		}
		catch (int ex_value)
		{
			std::cout << ex_value << "Не существующий пункт меню. Повторите ввод." << std::endl;
		}
	}
}