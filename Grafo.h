#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "City.h"
#include "List.h"

class Grafo
{
public:
	List data;
	City *city;
	int cityN;

	Grafo();
	~Grafo();

	void printGrafo();
	void connectCities();
	void dijkstraAlgorithm(City *origin, City *destination);
};

Grafo::Grafo()
{
	city = new City[50];
	cityN = 0;
	connectCities();
}

Grafo::~Grafo()
{
	delete[] city;
}

void Grafo::connectCities()
{
	/********************* CREAR CIUDADES COMO "NODOS" ************************/
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

	/********************* CONTAR ADYACENCIAS ************************/
	for (int i = 0; i < cityN; i++)
	{
		actual = data.first;

		while (actual != NULL)
		{
			if (strcmp(city[i].name, actual->origin) == 0)
				city[i].numAdy++;

			if (strcmp(city[i].name, actual->destiny) == 0)
				city[i].numAdy++;

			actual = actual->next;
		}
	}

	/********************* ASIGNACION DE MEMORIA A ADYACENCIAS ************************/
	for (int i = 0; i < cityN; i++)
		city[i].adyacent = new City*[city[i].numAdy];

	/********************* CONEXIONES ENTRE ADYACENCIAS ************************/
	actual = data.first;
	int ID;

	for (int i = 0; i < cityN; i++)
		city[i].numAdy = 0;

	while (actual != NULL)
	{
		for (int i = 0; i < cityN; i++)
		{
			if (strcmp(city[i].name, actual->origin) == 0)
			{
				for (int j = 0; j < cityN; j++)
					if (strcmp(city[j].name, actual->destiny) == 0)
						ID = j;

				city[i].adyacent[city[i].numAdy++] = &city[ID];
				city[ID].adyacent[city[ID].numAdy++] = &city[i];
			}
		}
		actual = actual->next;
	}

}

void Grafo::printGrafo()
{
	data.printList();

	for (int i = 0; i < cityN; i++)
		city[i].printCity();
}

void Grafo::dijkstraAlgorithm(City *origin, City *destination)
{
	City *actual;
	int newDistance;
	origin->distance = 0;

	for (int i = 0; i < origin->numAdy; i++)
	{
		newDistance = data.getCosto(origin->name, origin->adyacent[i]->name);
		newDistance += origin->distance;

		if (newDistance < origin->adyacent[i]->distance)
			origin->adyacent[i]->distance = newDistance;

		cout << origin->adyacent[i]->distance << endl;

		newDistance = 0;
	}
}

#endif
