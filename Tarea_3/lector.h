#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "libro.h"
#include <string>
#include <vector>
using namespace std;


class Lector
{
	vector <Libro*> coleccionLibros;
	public:
		Lector();
		~Lector();
		vector<Libro*> leerArchivo(string nombreArchivo);
};

#endif
