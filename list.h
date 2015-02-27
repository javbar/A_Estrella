#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Alumno
{
	int ID;
	char *name;
	float parcial_1, parcial_2, final;
	struct Alumno *next;
};

typedef struct Alumno Student;

struct Lista
{
	Student *first;
	Student *last;
	int size;
};

typedef struct Lista List;

void createList(List *list)
{
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
}

int insertFirstStudent(List *list, int ID, char *name, float parcial_1, float parcial_2)
{
	Student *newStudent;

	if ((newStudent = (Student*)malloc(sizeof(Student))) == NULL)
		return -1;

	if ((newStudent->name = (char*)malloc(50*sizeof(char))) == NULL)
		return -1;

	newStudent->ID = ID;
	strcpy(newStudent->name, name);
	newStudent->parcial_1 = parcial_1;
	newStudent->parcial_2 = parcial_2;
	newStudent->final = (parcial_1+parcial_2)/2;

	newStudent->next = NULL;
	list->first = newStudent;
	list->last = newStudent;
	list->size++;

	return 0;
}

int insertAtTop(List *list, int ID, char *name, float parcial_1, float parcial_2)
{
	Student *newStudent;

	if ((newStudent = (Student*)malloc(sizeof(Student))) == NULL)
		return -1;

	if ((newStudent->name = (char*)malloc(50 * sizeof(char))) == NULL)
		return -1;

	newStudent->ID = ID;
	strcpy(newStudent->name, name);
	newStudent->parcial_1 = parcial_1;
	newStudent->parcial_2 = parcial_2;
	newStudent->final = (parcial_1 + parcial_2) / 2;

	newStudent->next = list->first;
	list->first = newStudent;
	list->size++;
	return 0;
}

int insertAtBottom(List *list, Student *actual, int ID, char *name, float parcial_1, float parcial_2)
{
	Student *newStudent;

	if ((newStudent = (Student*)malloc(sizeof(Student))) == NULL)
		return -1;

	if ((newStudent->name = (char*)malloc(50 * sizeof(char))) == NULL)
		return -1;

	newStudent->ID = ID;
	strcpy(newStudent->name, name);
	newStudent->parcial_1 = parcial_1;
	newStudent->parcial_2 = parcial_2;
	newStudent->final = (parcial_1 + parcial_2) / 2;

	actual->next = newStudent;
	newStudent->next = NULL;
	list->last = newStudent;
	list->size++;
	return 0;
}

int insertAtPosition(List *list, int ID, char *name, float parcial_1, float parcial_2, int position)
{
	if (list->size < 2)
		return -1;

	if (position < 1 || position >= list->size)
		return -1;

	Student *actual, *newStudent;
	int i;

	if ((newStudent = (Student*)malloc(sizeof(Student))) == NULL)
		return -1;

	if ((newStudent->name = (char*)malloc(50 * sizeof(char))) == NULL)
		return -1;

	actual = list->first;

	for (i = 1; i<position; i++)
		actual = actual->next;

	if (actual->next == NULL)
		return -1;

	newStudent->ID = ID;
	strcpy(newStudent->name, name);
	newStudent->parcial_1 = parcial_1;
	newStudent->parcial_2 = parcial_2;
	newStudent->final = (parcial_1 + parcial_2) / 2;

	newStudent->next = actual->next;
	actual->next = newStudent;
	list->size++;

	return 0;
}

int deleteAtPosition(List *list, int position)
{
	if (list->size < 1 || position < 1 || position >= list->size)
		return -1;

	Student *actual, *deleteStudent;
	int i;

	actual = list->first;

	for (i = 1; i<position; i++)
		actual = actual->next;

	deleteStudent = actual->next;
	actual->next = actual->next->next;

	if (actual->next == NULL)
		list->last = actual;

	free(deleteStudent->name);
	free(deleteStudent);

	list->size--;

	return 0;
}

int deleteTop(List *list)
{
	if (list->size == 0)
		return -1;

	Student *deleteStudent;
	deleteStudent = list->first;
	list->first = list->first->next;

	if (list->size == 1)
		list->last = NULL;

	free(deleteStudent->name);
	free(deleteStudent);
	list->size--;
	return 0;
}

void deleteList(List *list)
{
	while (list->size > 0)
		deleteTop(list);
}

void printList(List *list)
{
	Student *actual;

	actual = list->first;

	while (actual != NULL)
	{
		printf("\nID: %d\nAlumno: %s\nCalificacion Primer Parcial: %f\nCalificacion Segundo Parcial: %f\nCalificacion Final: %f\n", actual->ID, actual->name, actual->parcial_1, actual->parcial_2, actual->final);
		actual = actual->next;
	}
}
