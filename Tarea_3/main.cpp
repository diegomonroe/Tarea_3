#include <iostream>
#include <fstream>

#include "libro.h"
#include "escritorLibros.h"
#include "string.h"

using namespace std;

int main() {

    EscritorLibros archivoSalida {"libros.dat"};
    archivoSalida.llenarArchivoSalida();
    // Ejemplo 2: Leer archivo
    ifstream archivoEntrada;
    archivoEntrada.open("libros.dat", ios::in|ios::binary);

    if (!archivoEntrada.is_open())
    {
        cerr << "No se pudo abrir archivo libros.dat para leer los datos";
        return -1;
    }

    Libro libro1LeidoDeArchivo;
    Libro libro2LeidoDeArchivo;
    Libro libro3LeidoDeArchivo;

    //archivoEntrada.seekg(sizeof(Libro));
    archivoEntrada.read((char *) &libro1LeidoDeArchivo, sizeof(Libro));
    archivoEntrada.read((char *) &libro2LeidoDeArchivo, sizeof(Libro));
    archivoEntrada.read((char *) &libro3LeidoDeArchivo, sizeof(Libro));

    archivoEntrada.close();

    return 0;

}