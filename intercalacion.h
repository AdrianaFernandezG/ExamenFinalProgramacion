#ifndef INTERCALACION_H
#define INTERCALACION_H
#include <vector>
#include "corporacion.h"
using namespace std;

//===Prototipo de intercalacion===
ReporteIntercalacion intercalarClientes(const vector<Corporacion> &v1, 
                                        const vector<Corporacion> &v2, 
                                        vector<Corporacion> &resultado);

#endif
