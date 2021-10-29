#include "escritorLibros.h"

EscritorLibros::EscritorLibros(std::string nombre) {
    this->nombreArchivo = nombre;
}

void EscritorLibros::llenarArchivoSalida()
{
    Lector lectorArchivoEntrada;
    vector<Libro*> coleccionLibros = lectorArchivoEntrada.leerArchivo("personas.txt");
    for (Libro* libro : coleccionLibros) {
        AgregarLibro(*libro);
    }
}

void EscritorLibros::AgregarLibro(Libro libro)
{

}
