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

    TEST(LecturaTest, Prueba_leerUnLibro) {

        Libro libroPrueba{ 15, "nombrePrueba","apellidoPrueba", "12345@prueba.com" };
        string esperada = "15 nombrePrueba apellidoPrueba 12345@prueba.com\n";

        ofstream archivoSalida("prueba.dat", ios::out | ios::binary);;
        archivoSalida.write((char*)&libroPrueba, sizeof(Libro));
        archivoSalida.close();

        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        Libro libroLeido = lector.ObtenerLibro(1);
        lector.cerrar();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << libroLeido.getID() << " ";
        streamSalidaEsperada << libroLeido.getNombre() << " ";
        streamSalidaEsperada << libroLeido.getApellido() << " ";
        streamSalidaEsperada << libroLeido.getCorreo() << endl;
        string actual = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(LecturaTest, Prueba_leerVariosLibros) {

        Libro libroPrueba1{ 15, "nombrePrueba1","apellPrueba1", "12345@prueba1.com" };
        string libro1 = "15 nombrePrueba1 apellPrueba1 12345@prueba1.com\n";

        Libro libroPrueba2{ 16, "nombrePrueba2","apellPrueba2", "12345@prueba2.com" };
        string libro2 = "16 nombrePrueba2 apellPrueba2 12345@prueba2.com\n";

        ostringstream streamEsperado;
        streamEsperado << libro1 << libro2;
        string esperado = streamEsperado.str();

        ofstream archivoSalida("prueba.dat", ios::out | ios::binary);;
        archivoSalida.write((char*)&libroPrueba1, sizeof(Libro));
        archivoSalida.write((char*)&libroPrueba2, sizeof(Libro));
        archivoSalida.close();

        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        lector.leerArchivoCompleto();
        lector.cerrar();

        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << lector;
        string actual = streamSalidaEsperada.str();

        EXPECT_EQ(esperado, actual);
    }
    TEST(LecturaTest, Prueba_ExcepcionLecturaLibroNoExiste) {
        Libro libroPrueba{ 15, "nombrePrueba","apellidoPrueba", "correoPrueba@prueba.com"};
        ofstream archivoSalida("prueba.dat", ios::out | ios::binary);;
        archivoSalida.write((char*)&libroPrueba, sizeof(Libro));
        archivoSalida.close();

        // Leer el libro de prueba
        LectorLibros lector{"prueba.dat"};
        EXPECT_THROW({
            Libro libroLeido = lector.ObtenerLibro(5);
            lector.cerrar();
            }, ExcepcionLibroNoExiste);
    }

    TEST(LecturaTest, Prueba_ExcepcionPersonaNoValida) {
        Libro libroPrueba{ 0, "nombrePrueba","apellidoPrueba", "correoPrueba@prueba.com" };
        ofstream archivoSalida("prueba.dat", ios::out | ios::binary);;
        archivoSalida.write((char*)&libroPrueba, sizeof(Libro));
        archivoSalida.close();

        // Leer el libro de prueba
        LectorLibros lector{ "prueba.dat" };
        EXPECT_THROW({
            Libro libroLeido = lector.ObtenerLibro(1);
            lector.cerrar();
            }, ExcepcionPersonaNoValida);
    }
}