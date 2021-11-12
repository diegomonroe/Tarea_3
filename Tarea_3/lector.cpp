#include "Lector.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "excepcionNoSePuedeAbrirArchivo.h"
Lector::Lector(string nombreArchivo)
{
    archivoALeer.open(nombreArchivo);

    if (!archivoALeer.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo(nombreArchivo);
    }
}

Lector::~Lector()
{
    for (Libro* libro : this->coleccionLibros) {
        delete libro;
    }
}

void Lector::leerArchivo()
{
    
    // Leer l�nea por l�nea 
    string linea{ "" };
    int id{ 0 };
    string nombre{ "" };
    string apellido{ "" };
    string correo{ "" };


    while (getline(this->archivoALeer, linea)) {

        try
        {
            // Procesamos la l�nea
            istringstream streamEntradaPersonas(linea);

            id = 0;
            nombre = "";
            apellido = "";
            correo = "";

            streamEntradaPersonas >> id >> nombre >> apellido >> correo;

            // Revisar si l�nea es v�lida
            if (id == 0)
            {
                string error = "Error en l�nea \"" + linea + "\". ID no puede ser cero.";
                throw error;
            }
            Libro* nuevoLibro = new Libro(id, nombre, apellido, correo);
            coleccionLibros.push_back(nuevoLibro);
        }
        catch (string& excepcion)
        {
            cerr << excepcion << endl;
        }
    }
}

vector<Libro*> Lector::getColeccionLibros()
{
    return this->coleccionLibros;
}
