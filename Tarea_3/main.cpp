#include <iostream>
#include <fstream>

#include "libro.h"
#include "escritorLibros.h"
#include "lectorLibros.h"
#include "string.h"

using namespace std;

int main() {

    EscritorLibros archivoSalida {"libros.dat"};
    archivoSalida.llenarArchivoSalida("personas.txt");
    archivoSalida.cerrar();
    

    LectorLibros archivoEntrada{ "libros.dat" };
    int numeroLibro = 15;
    Libro libro = archivoEntrada.ObtenerLibro(numeroLibro-1);
    archivoEntrada.cerrar();

    cout << "Empleado #" << numeroLibro << " " << libro.getNombre() << endl;

    return 0;

}