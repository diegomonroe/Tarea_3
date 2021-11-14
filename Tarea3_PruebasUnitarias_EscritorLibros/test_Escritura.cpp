#include "pch.h"
#include <string>
#include <sstream>

#include "../Tarea3_EscritorLibros/escritorLibros.h"
#include "../Tarea3_EscritorLibros/escritorLibros.cpp"

#include "../Compartido/libro.h"
#include "../Compartido/libro.cpp"
#include "../Excepciones/excepcionLibroNoExiste.h"
#include "../Excepciones/excepcionPersonaNoValida.h"

namespace {
    TEST(EscritorTest, Prueba_llenarArchivoSalida) {

        string esperada = "15 nombrePrueba apellidoPrueba 12345@prueba.com\n";
        istringstream stream(esperada);

        EscritorLibros escritor{ "prueba.dat" };
        escritor.llenarArchivoSalida(&stream);
        escritor.cerrar();

        ifstream archivoEntrada("prueba.dat", ios::in | ios::binary);
        
        Libro libroLeido;
        archivoEntrada.read((char*)&libroLeido, sizeof(Libro));
        
        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << libroLeido.getID() << " ";
        streamSalidaEsperada << libroLeido.getNombre() << " ";
        streamSalidaEsperada << libroLeido.getApellido() << " ";
        streamSalidaEsperada << libroLeido.getCorreo() << endl;
        string actual = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(EscritorTest, Prueba_AgregarLibro) {


        Libro libroPrueba{ 15, "nombrePrueba","apellidoPrueba", "12345@prueba.com" };
        string esperada = "15 nombrePrueba apellidoPrueba 12345@prueba.com\n";

        EscritorLibros escritor{ "prueba.dat" };
        escritor.agregarLibro(libroPrueba);
        escritor.cerrar();

        ifstream archivoEntrada("prueba.dat", ios::in | ios::binary);
        
        Libro libroLeido;
        archivoEntrada.read((char*)&libroLeido, sizeof(Libro));
        
        ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << libroLeido.getID() << " ";
        streamSalidaEsperada << libroLeido.getNombre() << " ";
        streamSalidaEsperada << libroLeido.getApellido() << " ";
        streamSalidaEsperada << libroLeido.getCorreo() << endl;
        string actual = streamSalidaEsperada.str();


        EXPECT_EQ(esperada, actual);
        
    }

    TEST(EscritorTest, Prueba_EscribirUnLibroDesdeStream) {

        ostringstream streamEntradaEsperada{};
        streamEntradaEsperada << 10 << " ";
        streamEntradaEsperada << "nombrePrueba1" << " ";
        streamEntradaEsperada << "apellPrueba1" << " ";
        streamEntradaEsperada << "12345@prueba1.com" << endl;
        string esperada = streamEntradaEsperada.str();
        
        istringstream stream(esperada);
        EscritorLibros escritor{ "prueba.dat" };
        escritor.llenarArchivoSalida(&stream);
        escritor.cerrar();

        ifstream archivoEntrada("prueba.dat", ios::in | ios::binary);
        Libro libroLeido;
        ostringstream streamSalidaEsperada{};

        archivoEntrada.read((char*)&libroLeido, sizeof(Libro));
        streamSalidaEsperada << libroLeido.getID() << " ";
        streamSalidaEsperada << libroLeido.getNombre() << " ";
        streamSalidaEsperada << libroLeido.getApellido() << " ";
        streamSalidaEsperada << libroLeido.getCorreo() << endl;
        
        
        archivoEntrada.close();
        string actual = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(EscritorTest, Prueba_EscribirVariosLibroDesdeStream) {

        ostringstream streamEntradaEsperada{};
        streamEntradaEsperada << 10 << " ";
        streamEntradaEsperada << "nombrePrueba1" << " ";
        streamEntradaEsperada << "apellPrueba1" << " ";
        streamEntradaEsperada << "12345@prueba1.com" << endl;
        streamEntradaEsperada << 11 << " ";
        streamEntradaEsperada << "nombrePrueba2" << " ";
        streamEntradaEsperada << "apellPrueba2" << " ";
        streamEntradaEsperada << "12345@prueba2.com" << endl;
        string esperada = streamEntradaEsperada.str();

        istringstream stream(esperada);
        EscritorLibros *escritor = new EscritorLibros( "prueba.dat" );
        escritor->llenarArchivoSalida(&stream);
        escritor->cerrar();

        ifstream archivoEntrada("prueba.dat", ios::in | ios::binary);
        Libro libroLeido;
        ostringstream streamSalidaEsperada{};

        while (archivoEntrada.tellg() < 84*2) {
            archivoEntrada.read((char*)&libroLeido, sizeof(Libro));
            streamSalidaEsperada << libroLeido.getID() << " ";
            streamSalidaEsperada << libroLeido.getNombre() << " ";
            streamSalidaEsperada << libroLeido.getApellido() << " ";
            streamSalidaEsperada << libroLeido.getCorreo() << endl;
        }


        string actual = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }
}