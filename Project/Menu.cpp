#include "Menu.h"

int AscUserInputType()
{
	int variant;
	std::cout << "������� 1 ��� ����������� �����" << std::endl
		<< "������� 2 ��� ����� �� �����" << std::endl;
	variant = CheckMenu(2);
	return variant;
}

int AscOutputType()
{
	int variant;
	std::cout << "������� 1 ��� ����������� ������" << std::endl
		<< "������� 2 ��� ������ � �����" << std::endl;
	variant = CheckMenu(2);
	return variant;
}


int AscInitialDataSaveMenu()
{
	int variant;

		std::cout << "1 - ��������� �������� ������" << std::endl
		<< "2 - �� ��������� �������� ������" << std::endl;
	variant = CheckMenu(2);
	return variant;
}
