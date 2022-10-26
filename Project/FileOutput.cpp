#include "FileOutput.h"

void FileOutputResult(DialogFinder finder)
{
	system("cls");
	if (finder.GetCountOfDialogs() == 0)
	{
		std::cout << "�� ��� ������ �� ���� ������." << std::endl;
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
				std::cout << "���� ������� ������." << std::endl;

				std::cout << "������ " << i + 1 << " �������." << std::endl;

				file << finder.GetDialog(i);
				std::cout << "������ ����� " << i + 1 << " ������� ��������." << std::endl << std::endl;
				file.close();
			}
			break;
		}
		catch (std::exception&)
		{
			std::cout << "������ �������.\n" << "������ ����������� �����? 1 � ���, 2 � ��" << std::endl << std::endl;
			file.close();
			int user_choice = CheckMenu(2);
			if (user_choice != restart)
				return;
		}
	}
}
