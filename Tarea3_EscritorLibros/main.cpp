#include <iostream>
#include <fstream>

#include "escritorLibros.h"
#include "../Compartido/libro.h"
#include "../Compartido/libro.cpp"

#include "../Excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "../Excepciones/excepcionPersonaNoValida.h"

using namespace std; 

int main() {
    try
    {
        ifstream streamEntrada("personas.txt", ifstream::in);
        if (!streamEntrada.is_open())
        {
            throw ExcepcionNoSePuedeAbrirArchivo("personas.txt");
        }
        
        EscritorLibros archivoSalida {"personas.dat"};
        archivoSalida.llenarArchivoSalida(&streamEntrada);
        archivoSalida.cerrar();
   
    }
    catch (const ExcepcionNoSePuedeAbrirArchivo& excepcion)
    {
        cerr << "Error abriendo: " << excepcion.what() << '\n';
    }
    catch (const ExcepcionPersonaNoValida& excepcion)
    {
        cerr << excepcion.what() << '\n';
    }
    catch(const exception& excepcion)
    {
        cerr << "Catch en main de la excepción desconocida: " << excepcion.what() << '\n';
    }

    return 0;

}