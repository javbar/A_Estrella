#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include<iostream>
using namespace std;

class City
{
	public:
		int ID;
		char name[50];
		int numAdy;
		bool visited;

		City()
		{
			numAdy = 0;
			visited = false;
		}

		~City(){}

		void printCity();
};

void City::printCity()
{
	cout << ID << " " << name << endl;
}

#endif
