#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include<iostream>
using namespace std;

class City
{
	public:
		int ID;
		char *name;
		int numAdy, distance;
		City **adyacent;
		bool visited;

		City()
		{
			numAdy = 0;
			distance = 1000000;
			visited = false;
			name = new char[50];
		}

		~City()
		{
			delete[] name;
		}

		void printCity();
};

void City::printCity()
{
	cout << "Nombre de la Ciudad: " << name << endl << "Ciudades Vecinas: " << endl;

	for (int i = 0; i < numAdy; i++)
		cout << "->" << adyacent[i]->name << endl;

	cout << endl;
}

#endif
