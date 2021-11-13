#ifndef ESCRITORLIBROS_H
#define ESCRITORLIBROS_H

#include "../../Compartido/libro.h"

#include <fstream>
#include <string>

class EscritorLibros {

    ofstream archivoSalida;

    public:
    EscritorLibros(string nombre);
    void llenarArchivoSalida(istream *archivoEntrada);
    void agregarLibro(Libro &libro);
    void cerrar();
};

#endif