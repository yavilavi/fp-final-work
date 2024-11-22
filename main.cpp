#include <cstdlib>
#include <iostream>
#include <vector>
#include "integrante.h"
#include "vehiculo.h"
#include <conio.h>

using namespace std;

int main() {
    vector<Integrante> integrantes;
    vector<Vehiculo> vehiculos;
    setlocale(LC_ALL, "es_ES.UTF-8");

    integrantes.push_back({"111", "Integrante 1", "1111111"});
    integrantes.push_back({"222", "Integrante 2", "2222222"});

    vehiculos.push_back({"AAA111", "Vehiculo integrante 1", "Marca 1", "azul", "300", "2024", "111"});
    vehiculos.push_back({"AAA222", "Vehiculo integrante 2", "Marca 2", "verde", "200", "2024", "222"});

    int opcion = -1;
    while (opcion != 3) {
        cout << "-- Club de moteros Colombia Enduro --\n";
        cout << "-- Menu principal --\n";
        cout << "1. Integrantes\n";
        cout << "2. Vehiculos\n";
        cout << "3. Salir\n";
        cout << "Digite una opción para iniciar un módulo: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
      	        system("cls");
                moduloIntegrantes(integrantes);
      	        system("cls");
            break;
            case 2:
      	        system("cls");
                moduloVehiculos(vehiculos, integrantes);
      	        system("cls");
            break;
            case 3:
      	        system("cls");
                cout << "Cerrando el programa...\n";
            break;
            default:
      	        system("cls");
                cout << "Opción no válida\n";
                cout << "Presione enter para continuar..."<<endl;
                getch();
      	        system("cls");
        }
    }
    return 0;
}