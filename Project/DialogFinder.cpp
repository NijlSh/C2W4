#include "DialogFinder.h"

void DialogFinder::FindDialogs()
{
	std::string tempDialog;
	bool is_dialog = false;
	bool is_incorrectLine = false;
	unsigned int count = 0;

	for (size_t i = 1; i < text.size(); i++)
	{
		if (text[i - 1] == '\n' && text[i] == '—' && text[i + 1] == ' ')
		{	
			if (!(text[i + 2] == '\n' || text[i + 2] == ' '))
			{
				count++;
				is_dialog = true;
			}
			else
				is_incorrectLine = true;
		}

		if (is_dialog)
			tempDialog += text[i];

		if ((text[i] == '\n' && text[i + 1] != '—') || is_incorrectLine)
		{
			is_dialog = false;
			is_incorrectLine = false;
			if (count > 1) 
			{
				dialogs.push_back(tempDialog);
			}
			count = 0;
			tempDialog.clear();
		}
	}
}

std::string DialogFinder::GetDialog(int number)
{
	if (number > static_cast<int>(dialogs.size()))
		return 0;
	return dialogs[number];
}

std::vector<std::string> DialogFinder::GetVector()
{
	return dialogs;
}

int DialogFinder::GetCountOfDialogs()
{
	return static_cast<int>(dialogs.size());
}

