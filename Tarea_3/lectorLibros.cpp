#include <iostream>

#include "lectorLibros.h"
#include "excepcionLibroNoExiste.h"
#include "excepcionNoSePuedeAbrirArchivo.h"

LectorLibros::LectorLibros(string nombreArchivo) {

    archivoEntrada.open(nombreArchivo, ios::in | ios::binary);

    if (!archivoEntrada.is_open())
    {
        throw new ExcepcionNoSePuedeAbrirArchivo();
    }

}

Libro LectorLibros::ObtenerLibro(int idLibro) {

    Libro libroLeido;

    // Posición del libro número idLibro
    long posicionLibro = sizeof(Libro) * (idLibro);

    archivoEntrada.seekg(0, ios::end);
    long fileSize = archivoEntrada.tellg();

    // Vamos a caer afuera?
    if (posicionLibro > fileSize)
    {
        throw new ExcepcionLibroNoExiste();
    }

    archivoEntrada.seekg(posicionLibro);
    archivoEntrada.read((char*)&libroLeido, sizeof(Libro));

    return libroLeido;
}

void LectorLibros::cerrar() {
    archivoEntrada.close();
}