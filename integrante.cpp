#include "integrante.h"
#include <iostream>
#include <limits>

using namespace std;


Integrante::Integrante(string cedula, string nombre, string telefono) : cedula(cedula), nombre(nombre), telefono(telefono) {}

void Integrante::mostrar() const{
    cout << "Cédula: " << this->cedula
         << " Nombre: " << this->nombre
         << " Teléfono: " << this->telefono<<endl;
}

int buscarIntegrante(const vector<Integrante>& integrantes, const string& cedula) {
    for (int i = 0; i < integrantes.size(); i++) {
        if (integrantes[i].cedula == cedula) {
            return i;
        }
    }
    return -1;
}

void crearIntegrante(vector<Integrante>& integrantes) {
    string cedula, nombre, telefono;
    cout << "Digite cédula del integrante: ";
    cin >> cedula;
    cout << "Digite nombre del integrante: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpiar el buffer
    getline(cin, nombre);
    cout << "Digite telefono del integrante: ";
    cin >> telefono;

    if (buscarIntegrante(integrantes, cedula) == -1) {
        integrantes.push_back(Integrante(cedula, nombre, telefono));
        cout << "Integrante creado exitosamente\n";
    } else {
        cout << "Error: Ya existe un integrante con esa cédula\n";
    }
    cout << "Presione enter para continuar..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void mostrarIntegrante(const vector<Integrante>& integrantes, const string& cedula) {
    int indice = buscarIntegrante(integrantes, cedula);
    if (indice != -1) {
        integrantes[indice].mostrar();
    } else {
        cout << "No existe ningún integrante con la cédula ingresada\n";
    }
    cout << "Presione enter para continuar..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void listarIntegrantes(const vector<Integrante>& integrantes) {
    if (integrantes.empty()) {
        cout << "No hay integrantes registrados\n";
    } else {
        for (const auto& integrante : integrantes) {
            integrante.mostrar();
        }
    }
    cout << "Presione enter para continuar..."<<endl;
    cin.get();
}

void actualizarIntegrante(vector<Integrante>& integrantes) {
    string cedula, nombre, telefono;
    cout << "Digite la cédula del integrante a modificar: ";
    cin >> cedula;

    int indice = buscarIntegrante(integrantes, cedula);

    if (indice == -1) {
        cout << "No se encontró un integrante con la cedula ingresada\n";
        return;
    }
    int opcion = -1;
    while (opcion != 3) {
      	system("cls");
        cout << "¿Que dato desea actualizar?\n";
        cout << "1. Nombre\n";
        cout << "2. Teléfono\n";
        cout << "3. Salir\n";
        cin >> opcion;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
      		    system("cls");
                cout << "Digite nuevo nombre del integrante: ";
                getline(cin, nombre);
                integrantes[indice].nombre = nombre;
                cout << "Nombre actualizado exitosamente\n";
                cout << "Presione enter para continuar..."<<endl;
                cin.get();
                break;
            case 2:
      		    system("cls");
                cout << "Digite nuevo teléfono del integrante: ";
                getline(cin, telefono);
                integrantes[indice].telefono = telefono;
                cout << "Telefono actualizado exitosamente\n";
                cout << "Presione enter para continuar..."<<endl;
                cin.get();
                break;
            case 3:
      		    system("cls");
                break;
            default:
      	        system("cls");
                cout << "Opción no válida\n";
                cout << "Presione enter para continuar..."<<endl;
                cin.get();
        }
    }
}


void moduloIntegrantes(vector<Integrante>& integrantes) {
    int opcion = -1;
    while (opcion != 5) {
        cout << "-- Módulo integrantes --\n";
        cout << "1. Crear integrante\n";
        cout << "2. Mostrar integrante\n";
        cout << "3. Listar integrantes\n";
        cout << "4. Modificar integrante\n";
        cout << "5. Volver al menú principal\n";
        cout << "Digite una opción para comenzar ";
        cin >> opcion;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (opcion) {
            case 1:
      	        system("cls");
                crearIntegrante(integrantes);
      	        system("cls");
                break;
            case 2: {
      	        system("cls");
    			string cedula;
                cout << "Digite cedula del integrante a mostrar: ";
                cin >> cedula;
                mostrarIntegrante(integrantes, cedula);
      	        system("cls");
                break;
              }
            case 3:
      	        system("cls");
                listarIntegrantes(integrantes);
      	        system("cls");
                break;
            case 4:
      	        system("cls");
                actualizarIntegrante(integrantes);
      	        system("cls");
                break;
            case 5:
      	        system("cls");
                cout << "Volviendo al menú principal\n";
                break;
            default:
      	        system("cls");
                cout << "Opción no válida\n";
                opcion = -1;
                cout << "Presione enter para continuar..."<<endl;
                cin.get();
      	        system("cls");
        }
    }
}