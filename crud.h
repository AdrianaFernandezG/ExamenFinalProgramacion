#ifndef CRUD_H
#define CRUD_H
#include <vector>
#include "corporacion.h"
using namespace std;

//===Prototipos CRUD===
void crearCorporacion(vector<Corporacion> &corporaciones);
void modificarCorporacion(vector<Corporacion> &corporaciones);
void eliminarCorporacion(vector<Corporacion> &corporaciones);

#endif
