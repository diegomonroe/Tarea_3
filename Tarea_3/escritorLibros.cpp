#include "escritorLibros.h"
#include "excepcionNoSePuedeAbrirArchivo.h"
#include "excepcionPersonaNoValida.h"

#include <iostream>
#include <sstream>

EscritorLibros::EscritorLibros(string nombreArchivo) {

    archivoSalida.open(nombreArchivo, ios::out | ios::binary);

    if (!archivoSalida.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo(nombreArchivo + " en escritor libros");
    }
}

void EscritorLibros::llenarArchivoSalida(istream *archivoEntrada)
{
    // Leer l�nea por l�nea 
    string linea{ "" };
    int id{ 0 };
    string nombre{ "" };
    string apellido{ "" };
    string correo{ "" };

    while (getline(*archivoEntrada, linea)) {
        
        // Procesamos la l�nea
        istringstream streamEntradaPersonas(linea);

        id = 0;
        nombre = "";
        apellido = "";
        correo = "";

        streamEntradaPersonas >> id >> nombre >> apellido >> correo;

        // Revisar si l�nea es v�lida
        try
        {
            if (id == 0)
            {
                throw ExcepcionPersonaNoValida();
            }
            Libro* nuevoLibro = new Libro(id, nombre, apellido, correo);
            agregarLibro(*nuevoLibro);
            delete nuevoLibro;
        }
        catch (const ExcepcionPersonaNoValida& excepcion)
        {
            cerr << excepcion.what() << '\n';
        }
    }
}

void EscritorLibros::agregarLibro(Libro &libro)
{
    archivoSalida.write((char*)&libro, sizeof(Libro));
}

void EscritorLibros::cerrar()
{
    archivoSalida.close();
}
