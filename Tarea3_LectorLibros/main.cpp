#include <iostream>
#include <fstream>

#include "lectorLibros.h"

#include "../Compartido/libro.h"
#include "../Compartido/libro.cpp"

#include "../Excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "../Excepciones/excepcionPersonaNoValida.h"
#include "../Excepciones/excepcionLibroNoExiste.h"


using namespace std; 

int main() {
    try
    {    
        LectorLibros lector{ "personas.dat" };
        int numeroLibro = 1;
        Libro libro = lector.ObtenerLibro(numeroLibro);
        lector.leerArchivoCompleto();
        cout << lector;
        lector.cerrar();
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