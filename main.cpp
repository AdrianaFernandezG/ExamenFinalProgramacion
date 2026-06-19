#include <iostream>
#include <vector>
#include <string>
#include "corporacion.h"
#include "crud.h"
#include "archivos.h"
#include "ordenacion.h"
#include "busqueda.h"
#include "intercalacion.h"
#include "utilidades.h"
#include "vectores.h"
using namespace std;

//Propósito: Punto de entrada principal que inicializa y arranca la ejecución del sistema.
//Parámetro: Ninguno.
//Retorno: Entero 0 como señal de finalización exitosa del programa.
int main(){
    mostrarIntroduccion(); // Despliega carátula
    opcionesMenu();        // Entra al bucle lógico del menú principal
    return 0;              // Fin del ciclo de vida de la app
}
