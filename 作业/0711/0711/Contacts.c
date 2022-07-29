#include "Contacts.h"

void show_meau()
{
	printf("***** 1.Add         2.Delete    *****\n");
	printf("***** 3.Find        4.Edit      *****\n");
	printf("***** 5.List        6.DeleteAll *****\n");
	printf("***** 7.SortByName  0.Quit      *****\n");
}

void LoadBook(Contact* book)
{
	FILE* fpload = fopen("Book.txt", "r");
	if (fpload == NULL)
	{
		perror("fpload");
		return;
	}
	int i = 0;
	for (i = 0; fread(book->date + i, sizeof(PeoInfo), 1, fpload) == 1; i++)
	{
		book->count++;
		if (book->count == book->capacity)
		{
			in_sz(book);
		}
	}
	fclose(fpload);
	fpload = NULL;
}


void InitBook(Contact* book)
{
	book->capacity = SZ_CAPA;
	book->date = (PeoInfo*)calloc(book->capacity, sizeof(PeoInfo));
	if (book->date == NULL)
	{
		printf("InitBook::%s\n", strerror(errno));
		return;
	}
	book->count = 0;
	LoadBook(book);
}

void in_sz(Contact* book)
{
	PeoInfo* ptr = (PeoInfo*)realloc(book->date, sizeof(PeoInfo) * (book->capacity + STEP));
	if (ptr == NULL)
	{
		printf("in_sz::%s\n", strerror(errno));
		return;
	}
	book->date = ptr;
	book->capacity += STEP;
	printf("Increase capacity successful.\n");
}

void Add(Contact* book)
{
	if (book->count == book->capacity)
	{
		in_sz(book);
	}
	printf("Please enter in name:");
	scanf("%s", (book->date[book->count]).name);
	printf("Please enter phone number:");
	scanf("%s", (book->date[book->count]).tele);
	(book->count)++;
}

void Find(Contact* book)
{
	assert(book);
	int key = Find_num(book);
	if (key == -1)
	{
		printf("No find it.\n");
		return;
	}
	printf("Find it.\n");
	printf("%s\t%s\n", "Name", "Telenumber");
	printf("%s\t%s\n", book->date[key].name, book->date[key].tele);
}

int Find_num(Contact* book)
{
	assert(book);
	printf("Please enter the name of the person:");
	char s[20] = "0";
	scanf("%s", s);
	int i = 0;
	int key = 1;
	for (i = 0; i < book->count; i++)
	{
		key = strcmp(s, book->date[i].name);
		if (key == 0)
		{
			return i;
		}
	}
	return -1;
}


void Delete(Contact* book)
{
	int ret = Find_num(book);
	int i = 0;
	for (i = ret; i < book->count - 1; i++)
	{
		book->date[i] = book->date[i + 1];
	}
	(book->count)--;
}

void List(Contact* book)
{
	printf("%s\t%s\n", "Name", "Telenumber");
	int i = 0;
	for (i = 0; i < book->count; i++)
	{
		printf("%s\t%s\n", book->date[i].name, book->date[i].tele);
	}
}

void Edit(Contact* book)
{
	assert(book);
	int ret = Find_num(book);
	printf("***** 1.Edit Name   *****\n");
	printf("***** 2.Edit Number *****\n");
	int q = 0;
	scanf("%d", &q);
	switch (q)
	{
	case 1:
		printf("Please enter new name:");
		scanf("%s", book->date[ret].name);
		break;
	case 2:
		printf("Please enter new number:");
		scanf("%s", book->date[ret].tele);
		break;
	}
	printf("Edit successful.\n");
}

void DeleteAll(Contact* book)
{
	printf("Are you sure delete all?(Y/N)");
	getchar();
	char a = '0';
	scanf("%c", &a);
	if (a == 'Y' || a == 'y')
	{
		InitBook(book);
	}
}

int comparByName(const void* elem1, const void* elem2)
{
	assert(elem1 && elem2);
	return strcmp(((PeoInfo*)elem1)->name, ((PeoInfo*)elem2)->name);
}

void SortByName(Contact* book)
{
	qsort(book->date, book->count, sizeof(PeoInfo), comparByName);
	printf("Sort successful.\n");
}

void FreeBook(Contact* book)
{
	assert(book);
	free(book->date);
	book->date = NULL;
}

void SaveBook(Contact* book)
{
	FILE* fpsave = fopen("Book.txt", "w");
	if (fpsave == NULL)
	{
		perror("fpsave");
		return;
	}
	fwrite(book->date, sizeof(PeoInfo), book->count, fpsave);
	fclose(fpsave);
	fpsave = NULL;
}