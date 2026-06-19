#include <iostream>
#include <vector>
#include "intercalacion.h"
using namespace std;

//Proposito: Combina dos vectores ordenados en un tercer vector ordenado por fecha.
//Parametro: finalizado - Vector fuente 1, pendiente - Vector fuente 2, resultado - Vector destino.
//Retorno: Estructura ReporteIntercalacion con métricas de rendimiento cargadas.
ReporteIntercalacion intercalarClientes(const vector<Corporacion> &v1, 
                                        const vector<Corporacion> &v2, 
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
