#include <iostream>
#include <vector>
#include "intercalacion.h"
using namespace std;

// ===Intercalacion de Dos Vectores Ordenados===
ReporteIntercalacion intercalarClientes(const vector<Corporacion> &finalizado, 
                                        const vector<Corporacion> &pendiente, 
                                          vector<Corporacion> &resultado){
	ReporteIntercalacion rep;
	    rep.comparaciones = 0;
	    rep.inserciones = 0;
	    
	    // Limpiamos el vector de destino por seguridad
	    resultado.clear();
	    size_t i = 0, j = 0;
	    
	    //Comparamos ambos vectores
	    while (i < v1.size() && j < v2.size()) {
	        rep.comparaciones++; // Contamos la comparación de control
	        
	        if (v1[i].fecha <= v2[j].fecha) {
	            resultado.push_back(v1[i]);
	            rep.inserciones++; // Conteo de inserciones
	            i++;
	        } else {
	            resultado.push_back(v2[j]);
	            rep.inserciones++; // Conteo de inserciones
	            j++;
	        }
	    }
	    
	    // Vaciamos los datos restantes de finalizados (si quedaron)
	    while (i < v1.size()) {
	        resultado.push_back(v1[i]);
	        rep.inserciones++;
	        i++;
	    }
	    
	    // Vaciamos los datos restantes de pendientes (si quedaron)
	    while (j < v2.size()) {
	        resultado.push_back(v2[j]);
	        rep.inserciones++;
	        j++;
	    }
	    
	    return rep; // Retorno multiple
	}
