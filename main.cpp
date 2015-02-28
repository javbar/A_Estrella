#include "Grafo.h"

int main()
{
	Grafo G;
	G.printGrafo();
	G.dijkstraAlgorithm(&G.city[0], &G.city[5]);

	cin.get();
	return 0;
}
