#ifndef EscritorLibros_H
#define EscritorLibros_H

#include <string>
#include "libro.h"
#include "lector.h"
#include <fstream>
class EscritorLibros {

    ofstream archivoSalida;

    public:
    EscritorLibros(string nombre);
    
    void llenarArchivoSalida(string archivoEntrada);
    void agregarLibro(Libro &libro);
    void cerrar();

};

#endif