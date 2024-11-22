#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <vector>
#include "integrante.h"

using namespace std;

class Vehiculo {
public:
    string placa;
    string nombre;
    string marca;
    string color;
    string cilindrada;
    string anio;
    string integranteCedula;

    Vehiculo(string placa, string nombre, string marca, string color, string cilindrada, string anio, string integranteCedula);
    void mostrar(const vector<Integrante>& integrantes) const;
};

int buscarVehiculo(const vector<Vehiculo>& vehiculos, const string& placa);
void crearVehiculo(vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes);
void mostrarVehiculo(const vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes, const string& placa);
void listarVehiculos(const vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes);
void listarVehiculosIntegrante(const vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes, const string& cedula);
void actualizarVehiculo(vector<Vehiculo>& vehiculos, const vector<Integrante>& integrantes);
void eliminarVehiculo(vector<Vehiculo>& vehiculos);
void moduloVehiculos(vector<Vehiculo>& vehiculos, vector<Integrante>& integrantes);


#endif