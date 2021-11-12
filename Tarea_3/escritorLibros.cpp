#include "escritorLibros.h"
#include "excepcionNoSePuedeAbrirArchivo.h"
#include <iostream>
EscritorLibros::EscritorLibros(string nombreArchivo) {

    archivoSalida.open(nombreArchivo, ios::out | ios::binary);

    if (!archivoSalida.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo(nombreArchivo + " en escritor libros");
    }
}

void EscritorLibros::llenarArchivoSalida(string nombreArchivoEntrada)
{
    Lector *lectorArchivoEntrada = new Lector(nombreArchivoEntrada);
    lectorArchivoEntrada->leerArchivo();
    vector<Libro*> coleccionLibros = lectorArchivoEntrada->getColeccionLibros();
 
    for (Libro* libro : coleccionLibros) {
        
        agregarLibro(*libro);
    }
    delete lectorArchivoEntrada;
}

void EscritorLibros::agregarLibro(Libro &libro)
{
    archivoSalida.write((char*)&libro, sizeof(Libro));
}

void EscritorLibros::cerrar()
{
    archivoSalida.close();
}
