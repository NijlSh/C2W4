#include <windows.h>

#include <iostream>

#include "Menu.h"
#include "DialogFinder.h"
#include "FileInput.h"
#include "FileOutput.h"
#include "TextInput.h"
#include "SaveInitialData.h"
#include "ConsoleOutput.h"
#include "Check.h"

enum class Type
{
	console = 1,
	file,
	end_program
};

enum class Answer
{
	Yes = 1,
	No
};


int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);  
	setlocale(LC_CTYPE, "RU");  

	std::cout << "Контрольная работа №2, вариант 5, сделано студентом группы 415 Шарашидзе Н.Л." << std::endl;
	std::cout << "Выделить в заданном тексте все диалоги (начинающиеся с новой строки и символа «тире»)." << std::endl;
	std::cout << "Сохранить диалоги в отдельных текстовых файлах." << std::endl;
	std::cout << "Реплика в диалоге голжна начинаться со среднего тире и пробела после него" << std::endl;

	std::string text;

	while (true)
	{
		Type input = static_cast<Type>(AscUserInputType());
		switch (input)
		{
		case Type::console:
			text = InputText();
			break;
		case Type::file:
			text = FileInput();
			break;
		case Type::end_program:
			exit(0);
		}

		if (text.empty()) 
		{
			std::cout << std::endl << "Файл пуст." << std::endl;
			system("pause");
			system("cls");
			continue;
		}
		DialogFinder finder(text);

		finder.FindDialogs();

		if (static_cast<Answer>(AscInitialDataSaveMenu()) == Answer::Yes)
			SaveInitialData(text);


		Type output = static_cast<Type>(AscOutputType());
		switch (output)
		{
		case Type::console:
			ConsoleOutput(finder);
			break;
		case Type::file:
			FileOutputResult(finder);
		}
		std::cout << "Закончить программу?\n1 - Да\n2 - Нет" << std::endl;
		Answer end_program = static_cast<Answer>(CheckMenu(2));
		if (end_program == Answer::Yes)
			return 0;
		system("cls");
	}
}