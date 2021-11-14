#include <iostream>

#include "lectorLibros.h"
#include "../Excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "../Excepciones/excepcionPersonaNoValida.h"
#include "../Excepciones/excepcionLibroNoExiste.h"

LectorLibros::LectorLibros(string nombreArchivo) {

    archivoEntrada.open(nombreArchivo, ios::in | ios::binary);

    if (!archivoEntrada.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo(nombreArchivo + " en lector libros.");
    }
}

LectorLibros::~LectorLibros()
{
    for (Libro* libro : this->coleccionLibros) {
        delete libro;
    }
}

Libro LectorLibros::ObtenerLibro(int idLibro) {

    Libro libroLeido;

    long posicionLibro = sizeof(Libro) * (idLibro-1);

    archivoEntrada.seekg(0, ios::end);

    long tamanoArchivo = archivoEntrada.tellg();

    if (posicionLibro >= tamanoArchivo || posicionLibro<0)
    {
        throw  ExcepcionLibroNoExiste();
    }

    archivoEntrada.seekg(posicionLibro);
    archivoEntrada.read((char*)&libroLeido, sizeof(Libro));

    if (libroLeido.getID() == 0) {
        throw ExcepcionPersonaNoValida();
    }

    return libroLeido;
}

void LectorLibros::leerArchivoCompleto()
{
    long tamanoLibro = sizeof(Libro);
    archivoEntrada.seekg(0, ios::end);
    long tamanoArchivo = archivoEntrada.tellg();

    int iterador = 0;
    while (iterador< tamanoArchivo) {
        Libro *libroLeido = new Libro();;
        archivoEntrada.seekg(iterador);
        archivoEntrada.read((char*)libroLeido, sizeof(Libro));
        coleccionLibros.push_back(libroLeido);
        iterador += tamanoLibro;
    }
}

void LectorLibros::cerrar() {
    archivoEntrada.close();
}

ostream& operator<<(std::ostream& o, const LectorLibros& lector)
{
    for (Libro* libro : lector.coleccionLibros) {
        o << libro->getID() << " ";
        o << libro->getNombre() << " ";
        o << libro->getApellido() << " ";
        o << libro->getCorreo() << endl;
    }
    return o;
}
