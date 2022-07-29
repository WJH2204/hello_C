#include "Contacts.h"

int main()
{
	int input = 0;
	Contact book;
	InitBook(&book);

	do
	{
		show_meau();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Add(&book);
			break;
		case DELETE:
			Delete(&book);
			break;
		case FIND:
			Find(&book);
			break;
		case EDIT:
			Edit(&book);
			break;
		case LIST:
			List(&book);
			break;
		case DELETEALL:
			DeleteAll(&book);
			break;
		case SORTBYNAME:
			SortByName(&book);
			break;
		case QUIT:
			SaveBook(&book);
			FreeBook(&book);
			printf("Quit.\n");
			break;
		default:
			printf("Input errors, please re-enter");
		}
	} while (input);
	return 0;
}