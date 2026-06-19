#include <iostream>
#include <vector>
#include "ordenacion.h"
using namespace std;

//Propósito: Ordena el vector por fecha usando el algoritmo Burbuja optimizado.
//Parámetro: corporaciones - Vector de estructuras modificado por referencia.
//Retorno: Estructura ReporteOrdenacion con los contadores de rendimiento.
ReporteOrdenacion ordenarVector(vector<Corporacion> &corporaciones){
    ReporteOrdenacion rep;
    rep.comparaciones = 0;
    rep.intercambios = 0;
    
    if (corporaciones.empty()) return rep; //Nos retorna 0 si no hay nada
    
    size_t n = corporaciones.size();
    bool intercambiado;
    
    for (size_t i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (size_t j = 0; j < n - i - 1; j++) {
            rep.comparaciones++; // Conteo de comparación
            
            if (corporaciones[j].fecha > corporaciones[j + 1].fecha) {
                Corporacion aux = corporaciones[j];
                corporaciones[j] = corporaciones[j + 1];
                corporaciones[j + 1] = aux;
                
                rep.intercambios++; // Conteo de intercambio
                intercambiado = true;
            }
        }
        if (!intercambiado) break; // Si ya está ordenado, optimiza saliendo antes
    }
    return rep; // Retorno multiple
}
