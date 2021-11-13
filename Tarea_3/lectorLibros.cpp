#include <iostream>

#include "lectorLibros.h"
#include "excepcionLibroNoExiste.h"
#include "excepcionNoSePuedeAbrirArchivo.h"
#include "excepcionPersonaNoValida.h"

LectorLibros::LectorLibros(string nombreArchivo) {

    archivoEntrada.open(nombreArchivo, ios::in | ios::binary);

    if (!archivoEntrada.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo(nombreArchivo + " en lector libros.");
    }
}

Libro LectorLibros::ObtenerLibro(int idLibro) {

    Libro libroLeido;

    long posicionLibro = sizeof(Libro) * (idLibro-1);

    archivoEntrada.seekg(0, ios::end);

    long fileSize = archivoEntrada.tellg();

    if (posicionLibro >= fileSize || posicionLibro<0)
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

void LectorLibros::cerrar() {
    archivoEntrada.close();
}