#ifndef BUSQUEDA_H
#define BUSQUEDA_H
#include <vector>
#include <string>
#include "corporacion.h"
using namespace std;

// === Búsqueda Binaria Recursiva con Contadores ===
int busquedaBinariaCorporacion(const vector<Corporacion> &corporaciones,
                               int inicio,
                               int fin, 
                               const string codigoBuscado,
                               int &comparacion,
                               int &llamada);

// === Búsqueda Secuencial Iterativa con Contador ===
bool buscarClientePorCodigo(string codigoBuscado, const vector<Corporacion> &corporaciones, Corporacion &c, int &comparacion);

// === Búsqueda Secuencial para Validación de Duplicados ===
bool existeCodigo(string codigoBuscado, const vector<Corporacion> &corporaciones);
void ordenarPorCodigoParaBusqueda(vector<Corporacion> &vectorTemporal);
#endif
