#ifndef INTEGRANTE_H
#define INTEGRANTE_H

#include <string>
#include <vector>

using namespace std;

class Integrante {
public:
    string cedula;
    string nombre;
    string telefono;

    Integrante(string cedula, string nombre, string telefono);
    void mostrar() const;
};


int buscarIntegrante(const vector<Integrante>& integrantes, const string& cedula);
void crearIntegrante(vector<Integrante>& integrantes);
void mostrarIntegrante(const vector<Integrante>& integrantes, const string& cedula);
void listarIntegrantes(const vector<Integrante>& integrantes);
void actualizarIntegrante(vector<Integrante>& integrantes);
void moduloIntegrantes(vector<Integrante>& integrantes);


#endif