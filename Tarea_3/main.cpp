#include <iostream>
#include <fstream>

#include "libro.h"
#include "escritorLibros.h"
#include "lectorLibros.h"
#include "excepcionLibroNoExiste.h"
#include "excepcionNoSePuedeAbrirArchivo.h"
#include "excepcionPersonaNoValida.h"

using namespace std; 

int main() {
    try
    {
        ifstream streamEntrada("personas.txt", ifstream::in);
        if (!streamEntrada.is_open())
        {
            throw ExcepcionNoSePuedeAbrirArchivo("personas.txt");
        }
        
        EscritorLibros archivoSalida {"libros.dat"};
        archivoSalida.llenarArchivoSalida(&streamEntrada);
        archivoSalida.cerrar();
    
    
        LectorLibros archivoEntrada{"libros.dat"};
        int numeroLibro = 1;
        Libro libro = archivoEntrada.ObtenerLibro(numeroLibro);
        archivoEntrada.cerrar();

        cout << "Empleado #" << numeroLibro << " " << libro.getNombre() << endl;
    }
    catch (const ExcepcionLibroNoExiste& excepcion)
    {
        cerr << "Error leyendo el libro solicitado. " << excepcion.what() << '\n';
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