#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "City.h"
#include "List.h"

class Grafo
{
	public:
		List data;

		City city[50];
		int cityN;
		int **adyMatrix;

		Grafo();
		~Grafo();

		void printGrafo();
		void readCities();
};

Grafo::Grafo()
{
	cityN = 0;
	readCities();
}

Grafo::~Grafo()
{
	cityN = 0;
	readCities();

	for (int i = 0; i < cityN; i++)
		delete[] adyMatrix[i];

	delete[] adyMatrix;
}

void Grafo::readCities()
{
	/********************* ASIGNACION DE ID A LAS CIUDADES ************************/
	bool repeated;
	char name[50];
	Node *actual;

	actual = data.first;

	strcpy(city[cityN].name, actual->origin);
	city[cityN].ID = cityN;
	cityN++;

	while (actual != NULL)
	{
		repeated = false;
		strcpy(name, actual->origin);

		for (int i = 0; i < cityN; i++)
			if (strcmp(city[i].name, name) == 0)
			{
			repeated = true;
			break;
			}

		if (!repeated)
		{
			strcpy(city[cityN].name, name);
			city[cityN].ID = cityN;
			cityN++;
		}

		actual = actual->next;
	}

	actual = data.first;

	while (actual != NULL)
	{
		repeated = false;
		strcpy(name, actual->destiny);

		for (int i = 0; i < cityN; i++)
			if (strcmp(city[i].name, name) == 0)
			{
			repeated = true;
			break;
			}

		if (!repeated)
		{
			strcpy(city[cityN].name, name);
			city[cityN].ID = cityN;
			cityN++;
		}

		actual = actual->next;
	}

	/********************* WEADAS DE TRINI (Matriz de Adyacencia) ************************/
	char Ciudades[14][15] = { "Francia", "Mexico", "EUA", "Japon", "Inglaterra", "Grecia", "Alemania", "Colombia", "Argentina", "Rusia", "Espana", "Brasil", "Canada", "Suiza" };
	int x, y;

	adyMatrix = new int *[cityN];

	for (int i = 0; i<cityN; i++)
		adyMatrix[i] = new int[cityN];

	for (int i = 0; i<cityN; i++)
		for (int j = 0; j<cityN; j++)
			adyMatrix[i][j] = -1;

	actual = data.first;

	while (actual != NULL)
	{
		for (int i = 0; i<cityN; i++)
			if (!strcmp(actual->origin, city[i].name))
				x = i;

		for (int i = 0; i<cityN; i++)
			if (!strcmp(actual->destiny, city[i].name))
				y = i;

		adyMatrix[x][y] = actual->cost;
		adyMatrix[y][x] = actual->cost;

		actual = actual->next;
	}
}

void Grafo::printGrafo()
{
	data.printList();

	for (int i = 0; i < cityN; i++)
		city[i].printCity();

	for (int i = 0; i < cityN; i++)
	{
		for (int j = 0; j<cityN; j++)
			cout << setw(4) << adyMatrix[i][j] << " ";
		cout << endl;
	}
}

#endif
