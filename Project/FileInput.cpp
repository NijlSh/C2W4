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
			std::cout << "���� ������� �������." << std::endl;
			break;
		}
		catch (std::exception&)
		{
			std::cout << "������ �������.\n" << "������ ����������� �����? 1 � ���, 2 � ��" << std::endl;
			std::cout << "����: ";
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
