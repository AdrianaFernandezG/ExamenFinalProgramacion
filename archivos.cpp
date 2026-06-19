#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "archivos.h"
using namespace std;

//=========Leer una linea del csv=========
bool leerCorporacion(ifstream &archivo, Corporacion &c) {
    string linea;
    if (!getline(archivo, linea)) {
        return false;
    }
    
    stringstream ss(linea);
    string idStr, acabadoStr, correccionStr, precioStr, fechaStr;
    
    getline(ss, idStr, ';');
    getline(ss, c.nombre, ';');
    getline(ss, c.tipo, ';');
    getline(ss, acabadoStr, ';');
    getline(ss, correccionStr, ';');
    getline(ss, precioStr, ';');
    getline(ss, c.codigo, ';');
    getline(ss, fechaStr, ';');
    
    // Convertimos las cadenas a numeros usando stringstream (compatible con todo)
    stringstream conversionId(idStr);
    conversionId >> c.id;
    
    stringstream conversionCorreccion(correccionStr);
    conversionCorreccion >> c.correccion;
    
    stringstream conversionPrecio(precioStr);
    conversionPrecio >> c.precio;
    
    stringstream conversionFecha(fechaStr);
    conversionPrecio >> c.fecha;
    
    // Evaluamos el estado del proyecto
    if (acabadoStr == "true" || acabadoStr == "1") {
        c.acabado = true;
    } else {
        c.acabado = false;
    }
    
    return true;
}

//===Cargar los Clientes del csv===
void cargarCorporacion(const string &nombreArchivo, vector<Corporacion> &corporaciones){
	ifstream archivo(nombreArchivo.c_str());
	
	if(!archivo) {
		return;
	}
	
	Corporacion temp; //valor temporal de la empresa
	while(leerCorporacion(archivo,temp)){
		corporaciones.push_back(temp);
	}
	archivo.close();
}

//===Guardar los Clientes en CSB===
void guardarCorporacion(const string &nombreArchivo, const vector<Corporacion> &corporaciones){
	ofstream archivo(nombreArchivo.c_str());
	if(!archivo){
		cout<<"Error al crear el archivo";
		return;
	}
	
	for(int i=0; i<corporaciones.size();i++){
		
		archivo<<corporaciones[i].id<<";"
			   <<corporaciones[i].nombre<<";"
			   <<corporaciones[i].tipo<<";"
			   <<corporaciones[i].acabado<<";"
			   <<corporaciones[i].correccion<<";"
			   <<corporaciones[i].precio<<";"
			   <<corporaciones[i].codigo<<";"
			   <<corporaciones[i].fecha
			   <<endl;
	}
	archivo.close();
}

//===Separacion de datos por acabado===
void separarYGuardarPorEstado(const vector<Corporacion> &corporaciones){
    ofstream archivoFinalizados("finalizado.csv");
    ofstream archivoPendientes("pendiente.csv");

    if (!archivoFinalizados || !archivoPendientes) {
        cout << "Error al crear los archivos de estado." << endl;
        return;
    }

    for (size_t i = 0; i < corporaciones.size(); i++) {
        if (corporaciones[i].acabado) {
            archivoFinalizados << corporaciones[i].id << ";"
                               << corporaciones[i].nombre << ";"
                               << corporaciones[i].tipo << ";"
                               << corporaciones[i].acabado << ";"
                               << corporaciones[i].correccion << ";"
                               << corporaciones[i].precio << ";"
							   << corporaciones[i].codigo << ";"
							   << corporaciones[i].fecha
							   << endl;
        } else {
            archivoPendientes << corporaciones[i].id << ";"
                              << corporaciones[i].nombre << ";"
                              << corporaciones[i].tipo << ";"
                              << corporaciones[i].acabado << ";"
                              << corporaciones[i].correccion << ";"
                              << corporaciones[i].precio << ";"
							  << corporaciones[i].codigo << ";"
							  << corporaciones[i].fecha
							  << endl;
        }
    }
    archivoFinalizados.close();
    archivoPendientes.close();
}
