#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> // Necesario para usar system()
#include "pdf.h"
#include "corporacion.h"
#include "archivos.h"
using namespace std;

//Proposito: Genera un reporte formateado guardándolo con extensión .pdf.
//Parametro: Ninguno.
//Retorno: Ninguno.
void generarReportePDFSimplificado() {
    vector<Corporacion> datosReporte;
    
    // Intentamos cargar el archivo consolidado de los procesos de intercalación/ordenación
    cargarCorporacion("resultado.csv", datosReporte);

    // Si está vacío, usamos la base de datos de clientes general por defecto
    if (datosReporte.empty()) {
        cargarCorporacion("clientes.csv", datosReporte);
    }

    if (datosReporte.empty()) {
        cout << "\n[!] Error: No existen datos cargados en el sistema para exportar el reporte.\n";
        return;
    }

    // Generamos el archivo de reporte preformateado directamente como archivo .pdf
    ofstream pdf("reporte_sistema.pdf");
    if (!pdf) {
        cout << "\n[!] Error crítico al crear el archivo PDF.\n";
        return;
    }

    // --- DISEÑO ESTÉTICO DEL ENCABEZADO ---
    pdf << "================================================================================\n";
    pdf << "              SISTEMA DE GESTION DE IDENTIDAD CORPORATIVA - SIS-112\n";
    pdf << "                     REPORTE EXPORTABLE DE DATOS PROCESADOS\n";
    pdf << "================================================================================\n";
    pdf << " Gestion Academica: 1/2026\n";
    pdf << " Total de Registros Exportados: " << datosReporte.size() << "\n";
    pdf << "--------------------------------------------------------------------------------\n\n";

    // --- ENCABEZADOS DE LA TABLA ---
    pdf << "ID   | CODIGO   | CLIENTE / EMPRESA            | TIPO         | PRECIO  | FECHA\n";
    pdf << "-----|----------|------------------------------|--------------|---------|----------\n";

    // --- RECORRIDO Y FORMATEO DE CADA REGISTRO ---
    for (size_t i = 0; i < datosReporte.size(); i++) {
        // Formatear ID
        pdf << datosReporte[i].id;
        if (datosReporte[i].id < 10) pdf << "    | ";
        else pdf << "   | ";

        // Formatear Código (Ancho de 8 espacios)
        string cod = datosReporte[i].codigo;
        if (cod.length() < 8) cod.append(8 - cod.length(), ' ');
        pdf << cod << " | ";

        // Formatear Nombre (Ancho de 28 espacios, recorta si es muy largo)
        string nom = datosReporte[i].nombre;
        if (nom.length() > 28) nom = nom.substr(0, 25) + "...";
        else nom.append(28 - nom.length(), ' ');
        pdf << nom << " | ";

        // Formatear Tipo (Ancho de 12 espacios)
        string tipo = datosReporte[i].tipo;
        if (tipo.length() < 12) tipo.append(12 - tipo.length(), ' ');
        pdf << tipo << " | ";

        // Formatear Precio
        pdf << "$" << datosReporte[i].precio;
        if (datosReporte[i].precio < 1000) pdf << "    | ";
        else pdf << "   | ";

        // Fecha de registro
        pdf << datosReporte[i].fecha << "\n";
    }

    pdf << "--------------------------------------------------------------------------------\n";
    pdf << "====================      FIN DEL REPORTE ESTRUCTURADO      ====================\n";
    
    pdf.close();

    cout << "\n=================================================================\n";
    cout << " [!] Exito: Reporte exportado como 'reporte_sistema.pdf'\n";
    cout << "=================================================================\n";

    // Abre el archivo PDF automáticamente en Windows usando el visor predeterminado del sistema
    #ifdef _WIN32
        system("start reporte_sistema.pdf");
    #endif
}
