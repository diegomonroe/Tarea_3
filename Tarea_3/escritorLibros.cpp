#include "escritorLibros.h"

#include <iostream>
EscritorLibros::EscritorLibros(std::string nombre) {
    //this->nombreArchivo = nombre;
    archivoSalida.open(nombre, ios::out | ios::binary);

    if (!archivoSalida.is_open())
    {
        cerr << "No se pudo abrir archivo libros.dat para escribir los datos";
        return;
    }
}

void EscritorLibros::llenarArchivoSalida()
{
    Lector lectorArchivoEntrada;
    vector<Libro*> coleccionLibros = lectorArchivoEntrada.leerArchivo("personas.txt");
    
    // Ejemplo 1: Escribir archivo
    // 
    //archivoSalida.close();
    for (Libro* libro : coleccionLibros) {
        
        agregarLibro(*libro);
    }

    archivoSalida.close();
}

void EscritorLibros::agregarLibro(Libro &libro)
{
    archivoSalida.write((char*)&libro, sizeof(Libro));
}

void EscritorLibros::cerrar()
{
    archivoSalida.close();
}
