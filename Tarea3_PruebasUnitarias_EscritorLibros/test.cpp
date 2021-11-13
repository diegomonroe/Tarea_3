#include "pch.h"
#include <string>
#include <sstream>

#include "../Tarea_3/escritorLibros.h"
#include "../Tarea_3/escritorLibros.cpp"
#include "../Tarea_3/lectorLibros.h"
#include "../Tarea_3/lectorLibros.cpp"
#include "../Tarea_3/libro.h"
#include "../Tarea_3/libro.cpp"
#include "../Tarea_3/excepcionLibroNoExiste.h"
#include "../Tarea_3/excepcionPersonaNoValida.h"

namespace {

    TEST(EscritorTest, Prueba_llenarArchivoSalida) {

        string archivoPrueba = "5 Diego Monroe 1234@prueba.com";
        istringstream stream(archivoPrueba);

        EscritorLibros escritor{ "prueba.dat" };
        escritor.llenarArchivoSalida(&stream);
        escritor.cerrar();

        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        Libro libroLeido = lector.ObtenerLibro(1);
        lector.cerrar();

        EXPECT_EQ("Diego", libroLeido.getNombre());
    }

    TEST(EscritorTest, Prueba_EscribirUnLibro) {

        Libro libroPrueba{ 15, "nombrePrueba","apellidoPrueba", "12345" };

        EscritorLibros escritor{ "prueba.dat" };
        escritor.agregarLibro(libroPrueba);
        escritor.cerrar();

        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        Libro libroLeido = lector.ObtenerLibro(1);
        lector.cerrar();

        EXPECT_EQ(libroLeido.getID(), libroPrueba.getID());
        EXPECT_EQ(libroLeido.getNombre(), libroPrueba.getNombre());
        EXPECT_EQ(libroLeido.getApellido(), libroPrueba.getApellido());
        EXPECT_EQ(libroLeido.getCorreo(), libroPrueba.getCorreo());
    }

    TEST(EscritorTest, Prueba_ExcepcionLecturaLibroNoExiste) {
        Libro libroPrueba{ 15, "nombrePrueba","apellidoPrueba", "correoPrueba@prueba.com" };
        EscritorLibros escritor{ "prueba.dat" };
        escritor.agregarLibro(libroPrueba);
        escritor.cerrar();

        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        EXPECT_THROW({
            Libro libroLeido = lector.ObtenerLibro(5);
            lector.cerrar();
            }, ExcepcionLibroNoExiste);
    }

    TEST(LectorTest, Prueba_ExcepcionPersonaNoValida) {
        Libro libroPrueba{ 0, "nombrePrueba","apellidoPrueba", "correoPrueba@prueba.com" };
        EscritorLibros escritor{ "prueba.dat" };
        escritor.agregarLibro(libroPrueba);
        escritor.cerrar();

        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        EXPECT_THROW({
            Libro libroLeido = lector.ObtenerLibro(1);
            lector.cerrar();
            }, ExcepcionPersonaNoValida);
    }
}