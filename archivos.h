#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <string>
#include <fstream>
#include <vector>
#include "corporacion.h"
using namespace std;

//===Leer una Linea del CSV===
bool leerCorporacion(ifstream &archivo, Corporacion &c);
//===Cargar las corporaciones del CSV===
void cargarCorporacion(const string &nombreArchivo, vector<Corporacion> &corporaciones);
//===Guardar las corporaciones en CSV===
void guardarCorporacion(const string &nombreArchivo, const vector<Corporacion> &corporaciones);
//===Separa los datos en finalizado.csv y pendiente.csv===
void separarYGuardarPorEstado(const vector<Corporacion> &corporaciones);

#endif
