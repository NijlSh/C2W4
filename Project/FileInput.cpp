#include "FileInput.h"

std::string FileInput()
{
	system("cls");
	std::string text = "";
	std::ifstream file;
	std::string file_name;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{
		try
		{
			file_name = GetFileName(input);
			file.open(file_name);
			std::cout << "Файл успешно отктрыт." << std::endl;
			break;
		}
		catch (std::exception&)
		{
			std::cout << "Ошибка доступа.\n" << "Хотите попробовать снова? 1 – Нет, 2 – Да" << std::endl;
			std::cout << "Ввод: ";
			int user_choice = CheckMenu(2);
			if (user_choice != restart)
				return text;
		}
	}

	std::string buff;

	while (true)
	{
		try
		{
			std::getline(file, buff);
			text += buff + "\n";
		}
		catch (const std::exception&)
		{
			break;
		}
	}
	return text;
}
