#ifndef UTILIDADES_H
#define UTILIDADES_H

//===Prototipos de utilidades===
void pausa();
void limpiar();
void mostrarIntroduccion();
void mostrarMenu();
void opcionesMenu();
void imprimirReporteEficienciaBusqueda(int compIterativa, bool encIterativa, int compBinaria, int llamadasBinaria, int posBinaria);
void imprimirReporteBurbuja(const ReporteOrdenacion &rep);
void imprimirReporteIntercalacion(const ReporteIntercalacion &rep);

#endif
