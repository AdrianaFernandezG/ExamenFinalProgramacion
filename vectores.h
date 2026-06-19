#ifndef VECTORES_H
#define VECTORES_H
#include <vector>
#include "corporacion.h"

//===Muestra un solo cliente con un formato limpio===
void mostrarCorporacion(const Corporacion &c);
//===Muestra un vector completo de corporaciones===
void mostrarVectorCorporaciones(const std::vector<Corporacion> &corporaciones);
//===Menu que pregunta al usuario si desea revisar los archivos Finalizados o Pendientes===
int seleccionarEstadoProyecto();
int seleccionarTipoBusqueda();
#endif
