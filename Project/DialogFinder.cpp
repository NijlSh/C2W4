#include "DialogFinder.h"

void DialogFinder::FindDialogs()
{
	std::string tempDialog;
	bool isDialog = false;
	int count = 0;

	for (int i = 1; i < static_cast<int>(text.size()); i++)
	{
		if (text[i - 1] == '\n' && text[i] == '–' && text [i + 1] == ' ')
		{
			isDialog = true;
			count++;
		}

		if (isDialog)
			tempDialog += text[i];

		if (text[i] == '\n' && text[i + 1] != '–')
		{
			isDialog = false;
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

