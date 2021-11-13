#ifndef LECTOR_LIBROS_H
#define LECTOR_LIBROS_H


#include "../../Compartido/libro.h"

#include <string>
#include <fstream>

using namespace std;

class LectorLibros {

    ifstream archivoEntrada;

    public:
    LectorLibros(string nombreArchivo);
    Libro ObtenerLibro(int idLibro);
    void cerrar();
};

#endif