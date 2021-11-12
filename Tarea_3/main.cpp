#include <iostream>
#include <fstream>

#include "libro.h"
#include "escritorLibros.h"
#include "lectorLibros.h"
#include "string.h"
#include "excepcionLibroNoExiste.h"
#include "excepcionNoSePuedeAbrirArchivo.h"

using namespace std; 

int main() {
    try
    {
        EscritorLibros archivoSalida {"libros.dat"};
        //archivoSalida.llenarArchivoSalida("personas.txt");
        archivoSalida.cerrar();
    
    
        LectorLibros archivoEntrada{"libros.dat"};
        int numeroLibro = 1;
        Libro libro = archivoEntrada.ObtenerLibro(numeroLibro);
        archivoEntrada.cerrar();

        cout << "Empleado #" << numeroLibro << " " << libro.getNombre() << endl;
    }
    catch (const ExcepcionLibroNoExiste& excepcion)
    {
        std::cerr << "Error leyendo el libro solicitado. " << excepcion.what() << '\n';
    }
    catch (const ExcepcionNoSePuedeAbrirArchivo& excepcion)
    {
        std::cerr << "Error abriendo: " << excepcion.what() << '\n';
    }
    catch(const exception& excepcion)
    {
        std::cerr << "Catch en main de la excepción desconocida: " << excepcion.what() << '\n';
    }

    return 0;

}