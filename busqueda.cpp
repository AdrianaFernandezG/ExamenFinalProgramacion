#include <iostream>
#include <vector>
#include "corporacion.h"
#include "busqueda.h"
using namespace std;

// === Búsqueda Binaria Recursiva ===
int busquedaBinariaCorporacion(const vector<Corporacion> &corporaciones,
                               int inicio,
                               int fin, 
                               const string codigoBuscado,
                               int &comparacion,
                               int &llamada){
    llamada++;
    // Condición Base
    if (inicio <= fin){
        int medio = inicio + (fin - inicio) / 2;
        
        comparacion++; // Conteo de comparación
        // Posición central
        if(corporaciones[medio].codigo == codigoBuscado){
            return medio;
        }
        
        if(codigoBuscado < corporaciones[medio].codigo){
            return busquedaBinariaCorporacion(corporaciones,
                                              inicio,
                                              medio - 1,
                                              codigoBuscado, 
                                              comparacion,
                                              llamada);
        }
        return busquedaBinariaCorporacion(corporaciones,
                                          medio + 1,
                                          fin,
                                          codigoBuscado, 
                                          comparacion,
                                          llamada);
    }
    return -1;    
}

// === Búsqueda Secuencial / Iterativa ===
bool buscarClientePorCodigo(string codigoBuscado, const vector<Corporacion> &corporaciones, Corporacion &c, int &comparacion) {
    for (size_t i = 0; i < corporaciones.size(); i++) {
        comparacion++;
        if (corporaciones[i].codigo == codigoBuscado) {
            c = corporaciones[i];
            return true;
        }
    }
    return false;
}

// === Búsqueda secuencial para verificar si el código ya existe (Validación de duplicados) ===
bool existeCodigo(string codigoBuscado, const vector<Corporacion> &corporaciones) {
    for (size_t i = 0; i < corporaciones.size(); i++) {
        if (corporaciones[i].codigo == codigoBuscado) {
            return true;
        }
    }
    return false;
}

// === Ordenamiento burbuja exclusivo por CÓDIGO para la Búsqueda Binaria ===
void ordenarPorCodigoParaBusqueda(vector<Corporacion> &vectorTemporal) {
    if (vectorTemporal.empty()) return;
    size_t n = vectorTemporal.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (vectorTemporal[j].codigo > vectorTemporal[j + 1].codigo) {
                Corporacion aux = vectorTemporal[j];
                vectorTemporal[j] = vectorTemporal[j + 1];
                vectorTemporal[j + 1] = aux;
            }
        }
    }
}