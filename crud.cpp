#include <iostream>
#include <string>
#include <vector>
#include "crud.h"
#include "busqueda.h"
#include "corporacion.h"
using namespace std;

//Proposito: Agrega de forma interactiva una nueva estructura Corporacion al final del vector.
//Parametro: corporaciones - Vector destino modificado por referencia.
//Retorno: Ninguno.
void crearCorporacion(vector<Corporacion> &corporaciones){
	Corporacion c;
	string comparacodigo;
	cout<<"Ingrese el ID del cliente: ";
	cin>>c.id;
	cin.ignore();
	cout<<"Ingrese el nombre del cliente: ";
	getline(cin,c.nombre);
	cout<<"Ingrese el tipo de identidad visual a crear (Digital/Analogica): ";
	getline(cin,c.tipo);
	cout<<"Â¿El Proyecto esta Acabado? (1=Finalizado, 0=Pendiente): ";
	cin>>c.acabado;
	cout<<"Correcciones que lleva el proyecto: ";
	cin>>c.correccion;
	cin.ignore();
	cout<<"Precio del proyecto (Fase inicial): ";
	cin>>c.precio;
	if(c.correccion>=3){
		c.precio=c.precio+(c.precio*0.20);
	}
	cout<<"Fecha de entrega del proyecto (Ingresarlo en formato AAAAMMDD Ej.'20260618'):  ";
	cin>>c.fecha;
	do{
		cout<<"Codigo alfanumerico del proyecto (Ej.Coca Cola = CC100): ";
		cin>>comparacodigo;
		cin.ignore();
		if(existeCodigo(comparacodigo,corporaciones)){
			cout<<"Codigo ya ingresado, intentelo nuevamente: \n";
		}
	}while(existeCodigo(comparacodigo,corporaciones));
	c.codigo=comparacodigo;
	corporaciones.push_back(c);
	cout<<"El cliente ha sido registrado correctamente"<<endl;
}

//Proposito: Modifica en memoria los atributos de un registro buscando por su ID numérico.
//Parametro: corporaciones - Vector fuente modificado por referencia.
//Retorno: Ninguno.
void modificarCorporacion(vector<Corporacion> &corporaciones) { 
    int idBuscado;
    cout << "Ingrese ID del cliente a modificar: ";
    cin >> idBuscado;
    cin.ignore(); // Limpieza de bafer necesaria para los getline siguientes
    
    for (size_t i = 0; i < corporaciones.size(); i++) {
        if (corporaciones[i].id == idBuscado) {
            cout << "\nCorporacion Encontrada\n";
            cout << "Nuevo nombre: ";
            getline(cin, corporaciones[i].nombre);
            cout << "Nueva identidad visual (Digital/Analogica): ";
            getline(cin, corporaciones[i].tipo);
            cout << "¿El Proyecto esta Acabado? (1=Finalizado, 0=Pendiente): ";
            int tempAcabado;
            cin >> tempAcabado; 
            
            corporaciones[i].acabado = (tempAcabado == 1);
            
            cout << "Correcciones: ";
            cin >> corporaciones[i].correccion;
            cout << "Nuevo precio: ";
            cin >> corporaciones[i].precio;
            cout << "Nueva fecha (Ingresarlo en formato AAAAMMDD Ej.'20260618'): ";
            cin >> corporaciones[i].fecha;
            
            cout << "\nLos datos del cliente han sido modificados\n";
            return;
        }
    }
    cout << "\nCliente no encontrado\n";
}

//Propósito: Suprime de forma física un registro del vector desplazando las posiciones.
//Parámetro: corporaciones - Vector modificado por referencia.
//Retorno: Ninguno.
void eliminarCorporacion(vector<Corporacion> &corporaciones){
	int idBuscado;
	cout << "Ingrese ID del cliente a modificar: ";
	cin>>idBuscado;
	for(int i=0; i<corporaciones.size(); i++){
		if(corporaciones[i].id==idBuscado){
			corporaciones.erase(corporaciones.begin()+i);
			cout<<"\nCliente eliminado correctamente\n";
			return;
		}
	}
	cout<<"\nCliente no encontrado\n";
}
