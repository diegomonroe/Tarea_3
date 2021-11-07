#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "libro.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Lector
{
	vector <Libro*> coleccionLibros;
	ifstream archivoALeer;
	public:
		Lector(string nombreArchivo);
		~Lector();
		void leerArchivo();
		vector<Libro*> getColeccionLibros();
};

#endif
