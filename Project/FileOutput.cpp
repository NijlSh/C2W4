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
			for (int i = 0; i < finder.GetCountOfDialogs(); i++)
			{
				file_name = GetFileName(output);
				file.open(file_name);
				std::cout << "Файл успешно открыт." << std::endl;

				std::cout << "Запись " << i + 1 << " диалога." << std::endl;

				file << finder.GetDialog(i);
				std::cout << "Диалог номер " << i + 1 << " успешно записана." << std::endl << std::endl;
				file.close();
			}
			break;
		}
		catch (std::exception&)
		{
			std::cout << "Ошибка доступа.\n" << "Хотите попробовать снова? 1 – Нет, 2 – Да" << std::endl << std::endl;
			file.close();
			int user_choice = CheckMenu(2);
			if (user_choice != restart)
				return;
		}
	}
}
