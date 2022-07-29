#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

#define NUM_PEOP 1000
#define NUM_NAME 20
#define NUM_TELE 15
#define SZ_CAPA 3
#define STEP 2

enum meau
{
	QUIT,
	ADD,
	DELETE,
	FIND,
	EDIT,
	LIST,
	DELETEALL,
	SORTBYNAME
};


typedef struct PeoInfo
{
	char name[NUM_NAME];
	char tele[NUM_TELE];
} PeoInfo;

typedef struct Contact
{
	PeoInfo *date;
	int count;
	int capacity;
} Contact;

void show_meau();

void Add(Contact* book);

void InitBook(Contact* book);

void Find(Contact* book);

void Delete(Contact* book);

void List(Contact* book);

void Edit(Contact* book);

void DeleteAll(Contact* book);

void SortByName(Contact* book);

int Find_num(Contact* book);

void in_sz(Contact* book);

void FreeBook(Contact* book);

void SaveBook(Contact* book);
