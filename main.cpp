#include "Grafo.h"
#include <stdlib.h>

int main()
{
	int option = 0;
	int cost = 0;
	char origen[50], destino[50];
	Grafo G;

	while (option != 3)
	{
		cout << "\tEXAMEN PARCIAL #1\nALGORITMOS Y ESTRUCTURAS DE DATOS \n  FECHA DE ENTREGA: 28/02/15\n\t  " << endl;
		cout << "   SHORTEST PATH ALGORITHM" << endl << endl;

		cout << "Elija una opcion:" << endl;
		cout << "1.- Encontrar ruta mas corta." << endl;
		cout << "2.- Agregar nueva ciudad." << endl;
		cout << "3.- Salir." << endl;

		cout << "Su eleccion: ";
		cin >> option;
		fflush(stdin);

		switch (option)
		{
		case 1:
			cout << "Ingrese origen: ";
			gets(origen);
			fflush(stdin);

			cout << "Ingrese destino: ";
			gets(destino);
			fflush(stdin);

			if (!G.searchValues(origen, destino))
				cout << "\nIntrodujo datos invalidos! Intente nuevamente..." << endl;
			break;

		case 2:
			cout << "Ingrese origen: ";
			gets(origen);
			fflush(stdin);

			if (G.cityExists(origen))
			{
				cout << "Ingrese Conexion: ";
				gets(destino);
				fflush(stdin);

				if (!G.connectionExists(origen, destino))
				{
					cout << "Ingrese Costo: ";
					cin >> cost;
					fflush(stdin);

					G.data.insertAtBottom(origen, destino, cost);
					G.updateCities();
				}

				else
				{
					cout << "Ya existe la conexion!" << endl;
				}
					
			}

			else
				cout << "No existe ciudad!" << endl;
						
			G.data.printList();
			break;

		case 3:
			cout << "\nHasta Luego!" << endl;
			break;

		default:
			cout << "\nError en la seleccion, intente nuevamente." << endl;
			break;
		}

		cout << "\nPresione cualquier tecla para continuar...";
		cin.get();
		
		if (option!=3)
			system("CLS");
	}

	return 0;
}
