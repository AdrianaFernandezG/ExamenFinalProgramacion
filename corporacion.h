#ifndef CORPORACION_H
#define CORPORACION_H
#include <string>
using namespace std;

//===Creacion de la Estructura de los Registros sobre Proyectos de Identidad Corporativa===
struct Corporacion {
    int id;             // Numero identificador de la empresa
    string nombre;      // Nombre de la empresa
    string tipo;        // Identidad visual digital o analogica
    bool acabado;       // Estado del proyecto: true = Finalizado, false = Pendiente
    int correccion;     // Cantidad de correcciones realizadas
    double precio;      // Precio actual
    string codigo;  	//Codigo alfanumerico de busqueda de proyectos
    string fecha;		//Fecha del pedido del proyecto
};

struct ReporteOrdenacion {
    int comparaciones;
    int intercambios;
};

struct ReporteIntercalacion {
    int comparaciones;
    int inserciones;
};
#endif
