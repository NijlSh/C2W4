#include "ConsoleOutput.h"

void ConsoleOutput(DialogFinder finder)
{
	system("cls");
	if (finder.GetCountOfDialogs() == 0)
	{
		std::cout << "Не было найдено ни одного диалога." << std::endl;
		std::cout << std::endl;
		return;
	}

	for (int i = 0; i < finder.GetCountOfDialogs();i++)
	{
		std::cout << "Диалог номер " << i + 1 << std::endl;
		std::cout << finder.GetDialog(i) << std::endl;

	}
}
