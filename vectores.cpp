#include <iostream>
#include "vectores.h"
using namespace std;

//Proposito: Muestra en consola todos los campos de un objeto Corporacion individual.
//Parametro: c - Estructura constante tipo Corporacion enviada por referencia.
//Retorno: Ninguno (Imprime directamente en pantalla).
void mostrarCorporacion(const Corporacion &c) {
    cout << "ID: " << c.id << endl;
    cout << "Nombre: " << c.nombre << endl;
    cout << "Tipo de identidad: " << c.tipo << endl;
    cout << "Estado: " << (c.acabado ? "Finalizado" : "Pendiente") << endl;
    cout << "Correcciones: " << c.correccion << endl;
    cout << "Precio: " << c.precio << endl;
    cout << "codigo alfanumerico: " << c.codigo << endl;
    cout << "------------------------------------------------------" << endl;
}

//Proposito: Recorre y despliega en lista todos los elementos de un vector de corporaciones.
//Parametro: corporaciones - Vector constante con todos los registros.
//Retorno: Ninguno (Valida si está vacío o imprime el bucle).

void mostrarVectorCorporaciones(const vector<Corporacion> &corporaciones) {
    if (corporaciones.empty()) {
        cout << "\nNo existen registros en esta lista.\n"; // Control si no hay datos
        return;
    }
    
    cout << "\n======================================================" << endl;
    for (size_t i = 0; i < corporaciones.size(); i++) {
        cout << "Registro #" << i + 1 << endl;
        mostrarCorporacion(corporaciones[i]); // Llama a la función individual
    }
    cout << "======================================================" << endl;
}

//Proposito: Solicita y valida la selección del tipo de archivo (Finalizado/Pendiente).
//Parametro: Ninguno.
//Retorno: Entero que representa la opción seleccionada (1 o 2)
int seleccionarEstadoProyecto() {
    int seleccion;
    do {
        cout << "\n¿Con que tipo de proyecto desea trabajar?\n";
        cout << "1. Proyectos Finalizados" << endl;
        cout << "2. Proyectos Pendientes" << endl;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;
        cin.ignore(); // Limpia residuo del buffer
        if (seleccion != 1 && seleccion != 2) {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (seleccion != 1 && seleccion != 2); // Cicla hasta que sea válido
    return seleccion;
}

//Proposito: Solicita y valida el método de búsqueda deseado por el usuario.
//Parametro: Ninguno.
//Retorno: Entero con la elección del usuario (1 para Binaria, 2 para Secuencial).
int seleccionarTipoBusqueda(){
    int opcion;
    do {
        cout << "\n¿Con que tipo de busqueda desea trabajar?\n";
        cout << "1. Busqueda Binaria (Recursiva)" << endl;
        cout << "2. Busqueda Secuencial (Iterativa)" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpia el buffer
        if (opcion != 1 && opcion != 2) {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 1 && opcion != 2); // Controla entrada correcta
    return opcion;
}
