#include "TextInput.h"

std::string InputText()
{
    system("cls");
    std::cout << "����: ";
    std::string text;
    while (true)
    {
        std::string buffer = "";
        std::getline(std::cin, buffer);
		if (buffer.empty()) 
		{
			if (text.empty()) 
			{
				std::cout << "������� ������� �����: ";
				continue;
			}
			break;
		}
        text += buffer + "\n";

    }
    return text;
}
