#include "pch.h"
#include <string>
#include <sstream>

#include "../Tarea3_LectorLibros/lectorLibros.h"
#include "../Tarea3_LectorLibros/lectorLibros.cpp"
#include "../Compartido/libro.h"
#include "../Compartido/libro.cpp"

#include "../Excepciones/excepcionLibroNoExiste.h"
#include "../Excepciones/excepcionPersonaNoValida.h"

namespace {

    TEST(EscritorTest, Prueba_leerUnLibro) {

        
        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        Libro libroLeido = lector.ObtenerLibro(1);
        lector.cerrar();

        EXPECT_EQ(0, 0);
    }

    TEST(EscritorTest, Prueba_ExcepcionLecturaLibroNoExiste) {
        Libro libroPrueba{ 15, "nombrePrueba","apellidoPrueba", "correoPrueba@prueba.com"};
       
        // Leer el libro de prueba
        LectorLibros lector{"prueba.dat"};
        EXPECT_THROW({
            Libro libroLeido = lector.ObtenerLibro(5);
            lector.cerrar();
            }, ExcepcionLibroNoExiste);
    }

    TEST(LectorTest, Prueba_ExcepcionPersonaNoValida) {
       
        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        EXPECT_THROW({
            Libro libroLeido = lector.ObtenerLibro(1);
            lector.cerrar();
            }, ExcepcionPersonaNoValida);
    }
}