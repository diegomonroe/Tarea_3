#ifndef LECTOR_LIBROS_H
#define LECTOR_LIBROS_H


#include "../Compartido/libro.h"

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class LectorLibros {

    
    ifstream archivoEntrada;

    vector <Libro*> coleccionLibros;

    public:
    LectorLibros(string nombreArchivo);
    ~LectorLibros();
    Libro ObtenerLibro(int idLibro);
    void leerArchivoCompleto();
    void cerrar();
    
    friend ostream& operator << (std::ostream& o, const LectorLibros& lector);
};

#endif