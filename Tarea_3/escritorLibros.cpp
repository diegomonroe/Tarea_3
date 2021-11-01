#include "escritorLibros.h"
#include <fstream>
#include <iostream>
EscritorLibros::EscritorLibros(std::string nombre) {
    this->nombreArchivo = nombre;
}

void EscritorLibros::llenarArchivoSalida()
{
    Lector lectorArchivoEntrada;
    vector<Libro*> coleccionLibros = lectorArchivoEntrada.leerArchivo("personas.txt");
    
    // Ejemplo 1: Escribir archivo
    ofstream archivoSalida;

    archivoSalida.open(this->nombreArchivo, ios::out|ios::binary);

    if (!archivoSalida.is_open())
    {
        cerr << "No se pudo abrir archivo libros.dat para escribir los datos";
        return;
    }

    
    //archivoSalida.close();
    for (Libro* libro : coleccionLibros) {
        archivoSalida.write((char*)&libro, sizeof(Libro));
        //AgregarLibro(*libro);
    }

    archivoSalida.close();
}

void EscritorLibros::AgregarLibro(Libro libro)
{
    
}
