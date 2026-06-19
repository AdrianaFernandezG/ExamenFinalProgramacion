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
#include "pdf.h"
using namespace std;


//Proposito: Pausa el flujo de ejecución en la consola de comandos de Windows.
//Parametro: Ninguno.
//Retorno: Ninguno.
void pausa(){
	system("pause");
}

//Proposito: Limpia por completo la pantalla de la consola de comandos.
//Parametro: Ninguno.
//Retorno: Ninguno.
void limpiar(){
	system("cls");
}

//Proposito: Despliega la carátula formal con los datos del grupo y la asignatura.
//Parametro: Ninguno.
//Retorno: Ninguno.
void mostrarIntroduccion(){ 
    cout << "----------------------------------------------------------------------" << endl;
    cout << "                 Asignatura: Programacion I (SIS-112)                 " << endl;
    cout << "                            Gestion: 1/2026                           " << endl;
    cout << "                              Paralelo: 3                             " << endl;
    cout << "             Docente: Pamela Shirley Valenzuela Fernandez             " << endl;
    cout << "                          Titulo del Proyecto:                        " << endl;
    cout << "          SISTEMA DE GESTION DE PROYECTOS DE IDENTIDAD CORPORATIVA    " << endl;
    cout << "                     Area / Carrera: Diseno Digital                   " << endl;
    cout << "                        Integrantes del Grupo:                        " << endl;
    cout << "                     Santiago Gael Rojas Bejarano                     " << endl;
    cout << "                   Adriana Daniela Fernandez Gantier                  " << endl;
    cout << "                      Fecha de entrega: 18/06/2026                    " << endl;
    cout << "----------------------------------------------------------------------" << endl;

    cout << "\nPresione ENTER para iniciar...";
    cin.get(); 
}

//Proposito: Imprime en pantalla las opciones numéricas del menú principal.
//Parametro: Ninguno.
//Retorno: Ninguno.
void mostrarMenu(){
	cout << "\n=========================================" << endl;
    cout << "             MENU PRINCIPAL             " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar cliente" << endl;
    cout << "2. Lista de clientes" << endl;
    cout << "3. Modificar informacion del cliente" << endl;
    cout << "4. Eliminar cliente" << endl;
    cout << "5. Ordenar por fecha de entrega" << endl;
    cout << "6. Buscar cliente" << endl;
    cout << "7. Busqueda secuencial" << endl;
    cout << "8. Intercalar clientes" << endl;
    cout << "9. Exportar reporte a PDF" << endl;
    cout << "10. Salir" << endl;
    cout << "=========================================" << endl;
    
    cout << "Seleccione una opcion: ";
}

//Proposito: Despliega de forma gráfica y comparativa la eficiencia de las búsquedas.
//Parametro: compIterativa/compBinaria - Comparaciones, encIterativa - Éxito lineal, llamadasBinaria - Recursión, posBinaria - Celda hallada.
//Retorno: Ninguno.
void imprimirReporteEficienciaBusqueda(int compIterativa, bool encIterativa, int compBinaria, int llamadasBinaria, int posBinaria) {
    cout << "\n======================================================" << endl;
    cout << "        ESTADISTICAS DE RENDIMIENTO (BUSQUEDA)        " << endl;
    cout << "======================================================" << endl;
    cout << " [1] BUSQUEDA SECUENCIAL (ITERATIVA):" << endl;
    cout << "     - Comparaciones realizadas: " << compIterativa << endl;
    cout << "     - Estado: " << (encIterativa ? "Cliente Encontrado" : "No Encontrado") << endl;
    cout << "------------------------------------------------------" << endl;
    cout << " [2] BUSQUEDA BINARIA (RECURSIVA):" << endl;
    cout << "     - Comparaciones realizadas: " << compBinaria << endl;
    cout << "     - Llamadas recursivas:      " << llamadasBinaria << endl;
    cout << "     - Estado: " << (posBinaria != -1 ? "Cliente Encontrado" : "No Encontrado") << endl;
    cout << "======================================================" << endl;
    
    // Solo muestra la conclusión si el método que se eligió logró encontrar al cliente
    if (encIterativa || posBinaria != -1) {
        cout << " -> GANADOR POR EFICIENCIA EN ESTA OPERACION: ";
        if (posBinaria != -1) {
            cout << "Busqueda Binaria (Menor numero de evaluaciones gracias a la recursion)" << endl;
        } else {
            cout << "Busqueda Secuencial Iterativa" << endl;
        }
    }
    cout << "======================================================" << endl;
}

//Proposito: Imprime los resultados estadísticos del ordenamiento Burbuja.
//Parametro: rep - Estructura ReporteOrdenacion con las métricas de control.
//Retorno: Ninguno.
void imprimirReporteBurbuja(const ReporteOrdenacion &rep) {
    cout << "\n======================================================" << endl;
    cout << "      ESTADISTICAS: BUBBLE SORT OPTIMIZADO            " << endl;
    cout << "======================================================" << endl;
    cout << "Numero de comparaciones: " << rep.comparaciones << endl;
    cout << "Numero de intercambios: " << rep.intercambios << endl;
    cout << "------------------------------------------------------" << endl;
}

//Proposito: Imprime los resultados estadísticos del proceso de Intercalación.
//Parametro: rep - Estructura ReporteIntercalacion con las métricas de control.
//Retorno: Ninguno.
void imprimirReporteIntercalacion(const ReporteIntercalacion &rep) {
    cout << "\n======================================================" << endl;
    cout << "      ESTADISTICAS: METODO DE INTERCALACION           " << endl;
    cout << "======================================================" << endl;
    cout << "Numero de comparaciones: " << rep.comparaciones << endl;
    cout << "Numero de inserciones:     " << rep.inserciones << endl;
    cout << "------------------------------------------------------" << endl;
}

//Proposito: Controla el flujo principal del programa, interactuando con los vectores y archivos.
//Parametro: Ninguno.
//Retorno: Ninguno.
void opcionesMenu(){
	vector<Corporacion> corporaciones;

    //Cargamos los clientes desde el archivo
    cargarCorporacion("clientes.csv", corporaciones);
    if(corporaciones.empty()){
    corporaciones = {
        {1, "Coca Cola", "Digital", true, 2, 2000, "CC100", "20260115"},
        {2, "Pepsi", "Analogica", false, 1, 2000, "PP200", "20260220"},
        {3, "Nestle", "Digital", true, 3, 6000, "NS300", "20260310"},
        {4, "Zara", "Analogica", false, 0, 3000, "ZR400", "20260405"},
        {5, "Samsung", "Digital", true, 4, 8000, "SM500", "20260425"},
        {6, "Apple", "Digital", true, 2, 9000, "AP600", "20260512"},
        {7, "Microsoft", "Digital", false, 5, 8500, "MS700", "20260530"},
        {8, "Google", "Digital", true, 1, 9500, "GG800", "20260602"},
        {9, "Amazon", "Analogica", false, 2, 7000, "AM900", "20260614"},
        {10, "Tesla", "Digital", true, 0, 7500, "TS1000", "20260618"}
    };
}

// Genera o sincroniza archivos iniciales por si ya existen datos en clientes.csv
    separarYGuardarPorEstado(corporaciones);
    
    ReporteOrdenacion historialBurbuja = {0, 0}; // Estructura de métricas burbuja
    ReporteIntercalacion historialIntercalacion = {0, 0}; // Estructura de métricas intercalación
    bool ejecucionAnalisis = false; // Para saber si se corrieron algoritmos
    
    int opcion;
    do {
        limpiar();
		mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
        //===Crear Cliente===
        case 1:
            crearCorporacion(corporaciones);
            guardarCorporacion("clientes.csv", corporaciones);
    		separarYGuardarPorEstado(corporaciones); // Genera finalizado.csv y pendiente.csv
            pausa();
			break;
            
        //===Listar Clientes con filtro de seleccion===
        case 2:{
            int estadoProyecto = seleccionarEstadoProyecto();
            vector<Corporacion> tempLista;
            
            if (estadoProyecto == 1) {
                cargarCorporacion("finalizado.csv", tempLista);
                cout << "\n===PROYECTOS FINALIZADOS===";
            } else {
                cargarCorporacion("pendiente.csv", tempLista);
                cout << "\n===PROYECTOS PENDIENTES===";
            }
            mostrarVectorCorporaciones(tempLista);
            pausa();
			break;
        }

        //===Modificar Cliente===
        case 3:
            modificarCorporacion(corporaciones);
            guardarCorporacion("clientes.csv", corporaciones);
            separarYGuardarPorEstado(corporaciones);
            pausa();
			break;

        //===Eliminar Cliente===
        case 4:
            eliminarCorporacion(corporaciones);
            guardarCorporacion("clientes.csv", corporaciones);
            separarYGuardarPorEstado(corporaciones);
            pausa();
			break;

        //===Ordenar Clientes===
        case 5:
            ordenarVector(corporaciones);
            guardarCorporacion("clientes.csv", corporaciones);
            separarYGuardarPorEstado(corporaciones);
            cout << "\nClientes ordenados por precio correctamente.\n";
            pausa();
			break;

        //===Busqueda Binaria===
        case 6: {
            limpiar();
            int seleccion = seleccionarTipoBusqueda(); // 1. Binaria, 2. Secuencial
            int estadoProyecto = seleccionarEstadoProyecto(); // 1. Finalizados, 2. Pendientes
            
            vector<Corporacion> tempBusqueda;
            if (estadoProyecto == 1) {
                cargarCorporacion("finalizado.csv", tempBusqueda);
            } else {
                cargarCorporacion("pendiente.csv", tempBusqueda);
            }

            if(tempBusqueda.empty()) {
                cout << "\n[!] No hay registros en la categoria seleccionada.\n";
                pausa();
                limpiar();
                break;
            }

            // Limpiamos el buffer antes de capturar la cadena de texto
            cin.ignore(); 
            string codigoBuscado;
            cout << "\nIngrese el codigo alfanumerico del cliente a buscar (Ej. CC100): ";
            getline(cin, codigoBuscado);

            // Inicializamos todas las variables para evitar basura de memoria
            int compBinaria = 0;
            int compIterativa = 0;
            int llamadasBinaria = 0;
            int posBinaria = -1;
            bool encIterativa = false;
            Corporacion c;

            // === EJECUCIÓN CONDICIONAL SEGÚN LA SELECCIÓN ===
            if (seleccion == 1) {
                // Obligatorio ordenar por CÓDIGO antes de la búsqueda binaria
                ordenarPorCodigoParaBusqueda(tempBusqueda);
                posBinaria = busquedaBinariaCorporacion(tempBusqueda, 0, tempBusqueda.size() - 1, codigoBuscado, compBinaria, llamadasBinaria);
                
                if(posBinaria != -1) {
                    cout << "\n======================================================" << endl;
                    cout << "===       CLIENTE ENCONTRADO (BUSQUEDA BINARIA)    ===" << endl;
                    cout << "======================================================" << endl;
                    mostrarCorporacion(tempBusqueda[posBinaria]);
                } else {
                    cout << "\n[!] Cliente no encontrado en esta seccion.\n";
                }
            }
            else {
                // Búsqueda Secuencial Iterativa
                encIterativa = buscarClientePorCodigo(codigoBuscado, tempBusqueda, c, compIterativa);
                
                if(encIterativa) {
                    cout << "\n======================================================" << endl;
                    cout << "===     CLIENTE ENCONTRADO (BUSQUEDA ITERATIVA)    ===" << endl;
                    cout << "======================================================" << endl;
                    mostrarCorporacion(c); // Muestra el cliente guardado en 'c'
                } else {
                    cout << "\n[!] Cliente no encontrado en esta seccion.\n";
                }
            }
            
            pausa();
            limpiar();

            // === LLAMADO A LA FUNCIÓN DE INFORME DE RENDIMIENTO ===
            // Pasamos todas las variables requeridas por el prototipo de utilidades.h
            imprimirReporteEficienciaBusqueda(compIterativa, encIterativa, compBinaria, llamadasBinaria, posBinaria);
            
            pausa();
            limpiar();
            break;
        }
        //===Busqueda secuencial==
        case 7: {
			Corporacion c;
			int estadoProyecto = seleccionarEstadoProyecto(); // Pregunta al usuario usando vectores.h
            vector<Corporacion> tempBusqueda;
            
            if (estadoProyecto == 1) {
                cargarCorporacion("finalizado.csv", tempBusqueda);
            } else {
                cargarCorporacion("pendiente.csv", tempBusqueda);
            }

            if(tempBusqueda.empty()) {
                cout << "\nNo hay registros en la categoria seleccionada.\n";
                pausa();
				break;
            }

            string codigoBuscado;
            cout << "\nIngrese el codigo alfanumerico del cliente a buscar: ";
            getline(cin,codigoBuscado);

            // Ejecucion de busqueda pasando el ID entero corregido
            int comparacionIterativa = 0; 
			bool posicion = buscarClientePorCodigo(codigoBuscado, tempBusqueda, c, comparacionIterativa);
			if(buscarClientePorCodigo(codigoBuscado,tempBusqueda,c, comparacionIterativa)){
                cout << "\n===CLIENTE ENCONTRADO===" << endl;
                mostrarCorporacion(c);
            } else {
                cout << "\nCliente no encontrado en esta seccion.\n";
            }
            pausa();
			break;
		}

        //===Intercalacion===
        case 8: {
            vector<Corporacion> finalizados;
            vector<Corporacion> pendientes;
            vector<Corporacion> resultadoUnificado;

            cargarCorporacion("finalizado.csv", finalizados);
            cargarCorporacion("pendiente.csv", pendientes);

            ReporteOrdenacion repFin = ordenarVector(finalizados);
            ReporteOrdenacion repPen = ordenarVector(pendientes);
            
            // Acumulamos en las variables en el historial
            historialBurbuja.comparaciones += (repFin.comparaciones + repPen.comparaciones);
            historialBurbuja.intercambios += (repFin.intercambios + repPen.intercambios);

            ReporteIntercalacion tempInter = intercalarClientes(finalizados, pendientes, resultadoUnificado);
            historialIntercalacion.comparaciones += tempInter.comparaciones;
            historialIntercalacion.inserciones += tempInter.inserciones;

            guardarCorporacion("resultado.csv", resultadoUnificado);
            
            // Mostramos los reportes del procesamiento actual
            imprimirReporteBurbuja(historialBurbuja);
            imprimirReporteIntercalacion(historialIntercalacion);
            
            ejecucionAnalisis = true; // Marcamos que ya hay datos para comparar al salir
            cout << "\n===ARCHIVO UNIFICADO===";
            cout << "\nEl reporte final se mostrara al salir del sistema.\n";
            
            pausa();
            break;
        }
        
        case 9: {
            limpiar();
            cout << ">>> GENERANDO REPORTE EXPORTABLE EN FORMATO PDF <<<\n";
            generarReportePDFSimplificado();
            pausa();
            break;
        }

        //===Salir===
        case 10:
        	limpiar();
            cout << "\n======================================================" << endl;
            cout << "          CERRANDO SISTEMA DE GESTION CORPORATIVA      " << endl;
            cout << "======================================================" << endl;
            
            if (ejecucionAnalisis) {
                cout << "\nREPORTE COMPARATIVO DE EFICIENCIA <<<" << endl;
                cout << " Total Comparaciones Burbuja:       " << historialBurbuja.comparaciones << endl;
                cout << " Total Comparaciones Intercalacion: " << historialIntercalacion.comparaciones << endl;
                cout << "------------------------------------------------------" << endl;
                
                if (historialIntercalacion.comparaciones < historialBurbuja.comparaciones) {
                    cout << "El metodo de INTERCALACION fue el MAS EFICIENTE\n";
                } else if (historialBurbuja.comparaciones < historialIntercalacion.comparaciones) {
                    cout << "El algoritmo BUBBLE SORT fue el MAS EFICIENTE\n";
                } else {
                    cout << "Ambos algoritmos tuvieron exactamente la misma eficiencia.\n";
                }
            } else {
                cout << "\nNo se realizaron pruebas de ordenamiento.\n";
            }
            cout << "\nSaliendo del sistema...\n";
            pausa();
			break;

        //===Opcion Invalida===
        default:
            cout << "\nOpcion invalida.\n";
        }
    } while(opcion != 9);
}
