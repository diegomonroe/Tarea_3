#include "Lector.h"
#include <sstream>
#include <iostream>
#include <fstream>
Lector::Lector()
{
}

Lector::~Lector()
{
    for (Libro* libro : this->coleccionLibros) {
        delete libro;
    }
}

vector<Libro*> Lector::leerArchivo(string nombreArchivo)
{
    //std::istringstream archivoEntrada{ nombreArchivo };
    ifstream archivoEntrada(nombreArchivo, ifstream::in);
    if (!archivoEntrada.is_open())
    {
        cerr << "Error leyendo archivo: " << nombreArchivo << endl;
        exit;
    }
    // Leer línea por línea 
    string linea{ "" };
    int id{ 0 };
    string nombre{ "" };
    string apellido{ "" };
    string correo{ "" };


    while (getline(archivoEntrada, linea)) {

        try
        {
            // Procesamos la línea
            istringstream streamEntradaPersonas(linea);

            id = 0;
            nombre = "";
            apellido = "";
            correo = "";

            streamEntradaPersonas >> id >> nombre >> apellido >> correo;

            // Revisar si línea es válida
            if (id == 0)
            {
                string error = "Error en línea \"" + linea + "\". ID no puede ser cero.";
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
    return this->coleccionLibros;
}