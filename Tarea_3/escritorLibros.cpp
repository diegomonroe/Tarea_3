#include "escritorLibros.h"

#include <iostream>
EscritorLibros::EscritorLibros(string nombre) {

    archivoSalida.open(nombre, ios::out | ios::binary);

    if (!archivoSalida.is_open())
    {
        cerr << "No se pudo abrir archivo libros.dat para escribir los datos";
        return;
    }
}

void EscritorLibros::llenarArchivoSalida(string nombreArchivoEntrada)
{
    Lector lectorArchivoEntrada;
    vector<Libro*> coleccionLibros = lectorArchivoEntrada.leerArchivo(nombreArchivoEntrada);
 
    for (Libro* libro : coleccionLibros) {
        
        agregarLibro(*libro);
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
