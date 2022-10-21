#include "DialogFinder.h"

void DialogFinder::FindDialogs()
{
	std::string tempDialog;
	bool isDialog = false;
	bool isIncorrectLine = false;
	int count = 0;

	for (int i = 1; i < static_cast<int>(text.size()); i++)
	{
		if (text[i - 1] == '\n' && (text[i] == '—' || text[i] == '–' || text[i] == '-') && text[i + 1] == ' ')
		{	
			if (!((text[i + 2] == '\n' || text[i + 2] == ' ')))
			{
				isDialog = true;
				count++;
			}
			else
				isIncorrectLine = false;
		}

		if (isDialog)
			tempDialog += text[i];

		if ((text[i] == '\n' && text[i + 1] != '—' && text[i + 1] != '–' && text[i + 1] != '-') || !isIncorrectLine)
		{
			isDialog = false;
			isIncorrectLine = false;
			if (count > 1) 
			{
				count = 0;
				dialogs.push_back(tempDialog);
				tempDialog.clear();
			}
			else 
			{
				count = 0;
				tempDialog.clear();
			}
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

