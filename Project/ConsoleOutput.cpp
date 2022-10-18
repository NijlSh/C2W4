#include "ConsoleOutput.h"

void ConsoleOutput(DialogFinder finder)
{
	system("cls");
	if (finder.GetCountOfDialogs() == 0)
	{
		std::cout << "�� ���� ������� �� ������ �������." << std::endl;
		std::cout << std::endl;
		return;
	}

	for (int i = 0; i < finder.GetCountOfDialogs();i++)
	{
		std::cout << "������ ����� " << i + 1 << std::endl;
		std::cout << finder.GetDialog(i) << std::endl;

	}
}
