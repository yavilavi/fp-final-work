#include <iostream>
#include "vehiculo.h"
#include "integrante.h"
#include <vector>
#include <limits>
#include <conio.h>

using namespace std;

std::string toUpperCase(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

Vehiculo::Vehiculo(string placa, string nombre, string marca, string color, string cilindrada, string anio, string integranteCedula)
    : placa(placa), nombre(nombre), marca(marca), color(color), cilindrada(cilindrada), anio(anio), integranteCedula(integranteCedula) {}

void Vehiculo::mostrar(const vector<Integrante>& integrantes) const{
    int indiceIntegrante = buscarIntegrante(integrantes, this->integranteCedula);
    cout << "Placa: " << this->placa
         << " Nombre: " << this->nombre
         << " Marca: " << this->marca
         << " Color: " << this->color
         << " Cilindraje: " << this->cilindrada
         << " Año: " << this->anio
         << " Integrante: " << integrantes[indiceIntegrante].nombre << " (Cédula: " << integrantes[indiceIntegrante].cedula << ")\n";
}

int buscarVehiculo(const vector<Vehiculo>& vehiculos, const string& placa) {
    for (size_t i = 0; i < vehiculos.size(); ++i) {
        if (vehiculos[i].placa == placa) {
            return i;
        }
    }
    return -1;
}

void crearVehiculo(vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes) {
    string placa, nombre, marca, color, cedula, cilindrada, anio;

    cout << "Digite cedula del dueño del vehiculo: ";
    cin >> cedula;

    int indiceIntegrante = buscarIntegrante(integrantes, cedula);
    if (indiceIntegrante == -1) {
        cout << "Error: No existe ningún integrante con la cédula ingresada\n";
        cout << "Presione enter para continuar..."<<endl;
        getch();
        return;
    }
    cout << "Digite placa del vehiculo: ";
    cin >> placa;
    if (buscarVehiculo(vehiculos, toUpperCase(placa)) != -1) {
        cout << "Error: Ya existe un vehiculo con esa placa.\n";
        cout << "Presione enter para continuar..."<<endl;
        getch();
        return;
    }
    cout << "Digite nombre personalizado para el vehículo: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombre);
    cout << "Digite marca del vehiculo: ";
    getline(cin, marca);
    cout << "Digite color del vehiculo: ";
    getline(cin, color);
    cout << "Digite cilindrada del vehiculo: ";
    cin >> cilindrada;
    cout << "Digite año del vehiculo: ";
    cin >> anio;
    vehiculos.push_back(Vehiculo(toUpperCase(placa), nombre, marca, color, cilindrada, anio, cedula));
    cout << "Vehiculo registrado exitosamente\n";
    cout << "Presione enter para continuar..."<<endl;
    getch();
}


void mostrarVehiculo(const vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes, const string& placa) {
    int indice = buscarVehiculo(vehiculos, toUpperCase(placa));
    if (indice != -1) {
        vehiculos[indice].mostrar(integrantes);
    } else {
        cout << "No existe ningún vehiculo con la placa ingresada\n";
    }
    cout << "Presione enter para continuar..."<<endl;
    getch();
}

void listarVehiculos(const vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes) {
    if (vehiculos.empty()) {
        cout << "No hay vehiculos registrados\n";
        return;
    }

    for (const auto& vehiculo : vehiculos) {
        vehiculo.mostrar(integrantes);
    }
    cout << "Presione enter para continuar..."<<endl;
    getch();
}


void listarVehiculosIntegrante(const vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes, const string& cedula) {
    int totalVehiculosIntegrante = 0;
    int indiceIntegrante = buscarIntegrante(integrantes, cedula);
    if (indiceIntegrante == -1) {
        cout << "Error: No existe ningún integrante con la cédula ingresada\n";
        cout << "Presione enter para continuar..."<<endl;
        getch();
        return;
    }

    for (const auto& vehiculo : vehiculos) {
        if (vehiculo.integranteCedula == cedula) {
            vehiculo.mostrar(integrantes);
            totalVehiculosIntegrante++;
        }
    }
    if (totalVehiculosIntegrante == 0) {
        cout << "El integrante no tiene vehículos asociados.\n";
    }
    cout << "Presione enter para continuar..."<<endl;
    getch();
}


void actualizarVehiculo(vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes) {
    string placa;
    cout << "Digite la placa del vehiculo a modificar: ";
    cin >> placa;

    int indice = buscarVehiculo(vehiculos, toUpperCase(placa));
    if (indice == -1) {
        cout << "No se encontró un vehículo con la placa ingresada\n";
        cout << "Presione enter para continuar..."<<endl;
        getch();
        return;
    }

    int opcion = -1;
    while (opcion != 7) {
        system("cls");
        cout << "¿Que dato desea actualizar?\n";
        cout << "1. Nombre\n";
        cout << "2. Marca\n";
        cout << "3. Color\n";
        cout << "4. Cilindrada\n";
        cout << "5. Año\n";
        cout << "6. Integrante\n";
        cout << "7. Salir\n";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                cout << "Digite nuevo nombre personalizado del vehiculo: ";
                getline(cin, vehiculos[indice].nombre);
                cout << "Presione enter para continuar..."<<endl;
                getch();
                break;
            case 2:
                cout << "Digite nueva marca del vehiculo: ";
                getline(cin, vehiculos[indice].marca);
                cout << "Presione enter para continuar..."<<endl;
                getch();
                break;
            case 3:
                cout << "Digite nuevo color del vehiculo: ";
                getline(cin, vehiculos[indice].color);
                cout << "Presione enter para continuar..."<<endl;
                getch();
                break;
            case 4:
                cout << "Digite nueva cilindrada del vehiculo: ";
                cin >> vehiculos[indice].cilindrada;
                cout << "Presione enter para continuar..."<<endl;
                getch();
                break;
            case 5:
                cout << "Digite nuevo año del vehiculo: ";
                cin >> vehiculos[indice].anio;
                cout << "Presione enter para continuar..."<<endl;
                getch();
                break;
            case 6: {
                string cedula;
                cout << "Digite cedula del nuevo dueño del vehiculo: ";
                cin >> cedula;
                if (buscarIntegrante(integrantes, cedula) != -1) {
                    vehiculos[indice].integranteCedula = cedula;
                } else {
                    cout << "No existe un integrante con ese número de cédula.\n";
                }
                cout << "Presione enter para continuar..."<<endl;
                getch();
                break;
            }
            case 7:
      		    system("cls");
                break;
            default:
      	        system("cls");
                cout << "Opción no válida\n";
                cout << "Presione enter para continuar..."<<endl;
                getch();
        }
    }
}


void eliminarVehiculo(vector<Vehiculo>& vehiculos) {
    string placa;
    cout << "Digite placa del vehículo a eliminar: ";
    cin >> placa;

    int indice = buscarVehiculo(vehiculos, toUpperCase(placa));
    if (indice == -1) {
        cout << "No se encontró un vehículo con la placa ingresada\n";
        return;
    }
    vehiculos.erase(vehiculos.begin() + indice);
    cout << "Vehículo eliminado exitosamente\n";
    cout << "Presione enter para continuar..."<<endl;
    getch();
}


void moduloVehiculos(vector<Vehiculo>& vehiculos, vector<Integrante>& integrantes) {
    int opcion = -1;
    while (opcion != 7) {
        cout << "-- Módulo vehículos --\n";
        cout << "1. Crear vehículo\n";
        cout << "2. Mostrar vehículo\n";
        cout << "3. Listar vehículos\n";
        cout << "4. Listar vehículos de un integrante\n";
        cout << "5. Modificar vehículo\n";
        cout << "6. Eliminar vehículo\n";
        cout << "7. Volver al menú principal\n";
        cout << "Digite una opción para comenzar ";
        cin >> opcion;

        switch (opcion) {
            case 1:
      	        system("cls");
                crearVehiculo(vehiculos, integrantes);
      	        system("cls");
                break;
            case 2: {
      	        system("cls");
                string placa;
                cout << "Digite placa del vehículo a mostrar: ";
                cin >> placa;
                mostrarVehiculo(vehiculos, integrantes, placa);
      	        system("cls");
                break;
            }
            case 3:
      	        system("cls");
                listarVehiculos(vehiculos, integrantes);
      	        system("cls");
                break;
            case 4: {
      	        system("cls");
                string cedula;
                cout << "Digite cedula del integrante que desea listar vehículos: ";
                cin >> cedula;
                listarVehiculosIntegrante(vehiculos, integrantes, cedula);
      	        system("cls");
                break;
            }
            case 5:
      	        system("cls");
                actualizarVehiculo(vehiculos, integrantes);
      	        system("cls");
                break;
            case 6:
      	        system("cls");
                eliminarVehiculo(vehiculos);
      	        system("cls");
                break;
            case 7:
      	        system("cls");
                cout << "Volviendo al menú principal\n";
                break;
            default:
      	        system("cls");
                cout << "Opción no válida\n";
                opcion = -1;
                cout << "Presione enter para continuar..."<<endl;
                getch();
      	        system("cls");
        }
    }
}