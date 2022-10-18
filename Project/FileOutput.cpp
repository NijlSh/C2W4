#include "FileOutput.h"

void FileOutputResult(DialogFinder finder)
{
	system("cls");
	if (finder.GetCountOfDialogs() == 0)
	{
		std::cout << "Не был найден ни один диалог." << std::endl;
		return;
	}

	std::string file_name = "";
	std::ofstream file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	while (true) {
		try
		{

			file_name = GetFileName(input);
			file.open(file_name);
			std::cout << "Файл успешно открыт." << std::endl;

			for (int i = 0; i < finder.GetCountOfDialogs(); i++)
			{
				std::cout << "Запись " << i + 1 << "диалога." << std::endl;

				file << finder.GetDialog(i);
				std::cout << "Диалог номер " << i + 1 << "успешно записана." << std::endl;
			}
			break;
		}
		catch (std::exception&)
		{
			std::cout << "Ошибка доступа.\n" << "Хотите попробовать снова? 1 – Нет, 2 – Да" << std::endl;
			std::cout << "Ввод: ";
			int user_choice = CheckMenu(2);
			if (user_choice != restart)
				return;
		}
	}
	std::cout << std::endl;
	file.close();
}
