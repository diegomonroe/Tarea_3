# Tarea_3

El proyecto se realizó con Visual Studio 2019, en Windows.

Para lograr correr las pruebas en VS 2019, se agregó tanto los .cpp, como los .h, ya que fue la unica solución para correr las pruebas.

/*Si aparece un error de inclusión de (#include "gtest/gtest.h") en el pch.h , la forma en la que lo soluciono es:

-Borrar el Proyecto pruebas unitarias -Crear nuevo proyecto Google Test y enlazarlo con el proyecto Tarea -Agregar archivo existente y seleccionar archivo test.cpp.

Y con eso soluciono el problema de inclusión.*/


Especificación de requerimientos:
Se requieren dos aplicaciones:
- La primera aplicación debe leer un archivo de personas y escribir un archivo binario con
la información utilizando el siguiente formato por cada persona:
Nombre del campo Tipo Tamaño
ID Entero (int)
Nombre String 15
Apellido String 15
Correo String 50
- El archivo a escribir debe ser binario y llamarse personas.dat
- La segunda aplicación debe de poder leer del archivo binario personas.dat y poder
satisfacer los siguientes requerimientos
- Debe de poder leer la persona en cualquier posición dentro del archivo sin
recorrer secuencialmente el archivo.
- Debe de poder manejar las siguientes excepciones:
- Excepción de que el archivo no se pudo abrir
- Excepción de que la persona solicitada no es válida
- Se puede revisar si el ID es 0 después de leer
- Excepción si no se pudo leer una persona
- Si el archivo tiene 15 personas y se pidió la persona 20, por
ejemplo.
