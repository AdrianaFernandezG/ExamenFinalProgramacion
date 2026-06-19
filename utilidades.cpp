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

void pausa(){
	system("pause");
}

void limpiar(){
	system("cls");
}

//===Introduccion del Proyecto===
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

//===Menu Principal===
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
    cout << "7. Intercalar clientes" << endl;
    cout << "8. Exportar reporte a PDF" << endl;
    cout << "9. Salir" << endl;
    cout << "=========================================" << endl;
    
    cout << "Seleccione una opcion: ";
}

void imprimirReporteEficienciaBusqueda(int compIterativa, bool encIterativa, int compBinaria, int llamadasBinaria, int posBinaria) {
    cout << "\n======================================================" << endl;
    cout << "               REPORTE DE EFICIENCIA                  " << endl;
    cout << "======================================================" << endl;
    cout << " Busqueda secuencial (Iterativa):\n";
    cout << "   Comparaciones efectuadas: " << compIterativa << endl;
    cout << "   Resultado de operacion:   " << (encIterativa ? "Encontrado" : "No encontrado") << endl;
    cout << "\n Busqueda binaria (Recursiva):\n";
    cout << "   Comparaciones efectuadas: " << compBinaria << endl;
    cout << "   Llamadas recursivas:      " << llamadasBinaria << endl;
    cout << "   Resultado de operacion:   " << (posBinaria != -1 ? "Encontrado" : "No encontrado") << endl;
    cout << "------------------------------------------------------" << endl;
    
    cout << " Conclusion: ";
    if (compIterativa < compBinaria) {
        cout << "La Busqueda Secuencial fue mas eficiente para este caso.\n";
    } else if (compIterativa > compBinaria) {
        cout << "La Busqueda Binaria fue mas eficiente para este caso.\n";
    } else {
        cout << "Ambos metodos requirieron la misma cantidad de comparaciones.\n";
    }
    cout << "======================================================\n" << endl;
}

//Imprime los resultados del ordenamiento Burbuja
void imprimirReporteBurbuja(const ReporteOrdenacion &rep) {
    cout << "\n======================================================" << endl;
    cout << "      ESTADISTICAS: BUBBLE SORT OPTIMIZADO            " << endl;
    cout << "======================================================" << endl;
    cout << "Numero de comparaciones: " << rep.comparaciones << endl;
    cout << "Numero de intercambios: " << rep.intercambios << endl;
    cout << "------------------------------------------------------" << endl;
}

//Imprime los resultados de la Intercalación
void imprimirReporteIntercalacion(const ReporteIntercalacion &rep) {
    cout << "\n======================================================" << endl;
    cout << "      ESTADISTICAS: METODO DE INTERCALACION           " << endl;
    cout << "======================================================" << endl;
    cout << "Numero de comparaciones: " << rep.comparaciones << endl;
    cout << "Numero de inserciones:     " << rep.inserciones << endl;
    cout << "------------------------------------------------------" << endl;
}

void opcionesMenu(){
	vector<Corporacion> corporaciones;

    //Cargamos los clientes desde el archivo
    cargarCorporacion("clientes.csv", corporaciones);
    if(corporaciones.empty()){
		corporaciones = {
	    	{1, "Coca Cola", "Digital", true, 2, 2000, "CC100"},
	    	{2, "Pepsi", "Analogica", false, 1, 2000, "PP200"},
	    	{3, "Nestle", "Digital", true, 3, 6000, "NS300"},
	    	{4, "Zara", "Analogica", false, 0, 3000, "ZR400"},
	    	{5, "Samsung", "Digital", true, 4, 8000, "SM500"},
		    {6, "Apple", "Digital", true, 2, 9000, "AP600"},
		    {7, "Microsoft", "Digital", false, 5, 8500, "MS700"},
		    {8, "Google", "Digital", true, 1, 9500, "GG800"},
		    {9, "Amazon", "Analogica", false, 2, 7000, "AM900"},
		    {10, "Tesla", "Digital", true, 0, 7500, "TS1000"}
		};
	}

// Genera o sincroniza archivos iniciales por si ya existen datos en clientes.csv
    separarYGuardarPorEstado(corporaciones);
    
    ReporteOrdenacion historialBurbuja = {0, 0};
    ReporteIntercalacion historialIntercalacion = {0, 0};
    bool ejecucionAnalisis = false;
    
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
    		separarYGuardarPorEstado(corporaciones);
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
			int seleccion=seleccionarTipoBusqueda();
			int comparacionBinaria=0;
			int comparacionIterativa=0;
			int llamada,posicion;
			bool posicion2;
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
	        }
	
	        //Se hace el ordenamiento antes de la busqueda binaria
	        ordenarVector(tempBusqueda);
	            
	        string codigoBuscado;
	        cout << "\nIngrese el codigo alfanumerico del cliente a buscar: ";
	        getline(cin,codigoBuscado);
	
	        // Ejecución de búsqueda pasando el codigo alfanumerico
	        posicion2 = buscarClientePorCodigo(codigoBuscado, tempBusqueda, c, comparacionIterativa);
			posicion = busquedaBinariaCorporacion(tempBusqueda, 0, tempBusqueda.size()-1, codigoBuscado, comparacionBinaria, llamada);
			if(seleccion==1){
				if(posicion != -1) {
	            cout << "\n===CLIENTE ENCONTRADO===" << endl;
	            mostrarCorporacion(tempBusqueda[posicion]);
	        	} else {
	            cout << "\nCliente no encontrado en esta seccion.\n";
	            pausa();
	        	}
			}
			else{
				if(posicion2 != false) {
	            cout << "\n===CLIENTE ENCONTRADO===" << endl;
	            mostrarCorporacion(tempBusqueda[posicion]);
	        	} else {
	            cout << "\nCliente no encontrado en esta seccion.\n";
	            pausa();
	        	}
			}
			pausa();
			limpiar();
			cout << "\n=== REPORTE DE EFICIENCIA ===\n";
			cout << "Busqueda iterativa:\n";
			cout << "   Comparaciones: " << comparacionIterativa << endl;
			cout << "   Resultado: " << (posicion != -1 ? "Encontrado" : "No encontrado") << endl;
			cout << "\nBusqueda binaria recursiva:\n";
			cout << "   Comparaciones: " << comparacionBinaria << endl;
			cout << "   Llamadas: " << llamada << endl;
			cout << "   Resultado: " << (posicion2 != true ? "Encontrado" : "No encontrado") << endl;
			cout << "\nConclusion: ";
			if (comparacionIterativa < comparacionBinaria) {
			    cout << "Iterativa fue mas eficiente en comparaciones.\n";
			} else if (comparacionIterativa > comparacionBinaria) {
			    cout << "Busqueda Binaria fue mas eficiente en comparaciones.\n";
			} else {
			    cout << "Ambas tuvieron la misma eficiencia en comparaciones.\n";
			}
			pausa();
			break;
        }

        //===Intercalacion===
        case 7: {
            vector<Corporacion> finalizados;
            vector<Corporacion> pendientes;
            vector<Corporacion> resultadoUnificado;

            cargarCorporacion("finalizado.csv", finalizados);
            cargarCorporacion("pendiente.csv", pendientes);

            ReporteOrdenacion repFin = ordenarPorBurbujaOptimizado(finalizados);
            ReporteOrdenacion repPen = ordenarPorBurbujaOptimizado(pendientes);
            
            // Acumulamos en las variables en el historial
            historialBurbuja.comparaciones += (repFin.comparaciones + repPen.comparaciones);
            historialBurbuja.intercambios += (repFin.intercambios + repPen.intercambios);

            ReporteIntercalacion tempInter = intercalarVectoresContando(finalizados, pendientes, resultadoUnificado);
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
        
        case 8: {
            limpiar();
            cout << ">>> GENERANDO REPORTE EXPORTABLE EN FORMATO PDF <<<\n";
            generarReportePDFSimplificado();
            pausa();
            break;
        }

        //===Salir===
        case 9:
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
