#include "gestor.h"
#include <iostream>
using namespace std;
int main() {
    // Creamos las tareas y las almacenamos
    CrearTarea tarea1("Historia", 12, 4);
    CrearTarea tarea2("Sexo", 14, 4);
    CrearTarea tarea3("Mate", 12, 4);

    AlmacenTareas almacen;
    almacen.agregarTarea(tarea1.crearTarea());
    almacen.agregarTarea(tarea2.crearTarea());
    almacen.agregarTarea(tarea3.crearTarea());

    // Mostramos las tareas almacenadas
    almacen.mostrarTareas();

    // Creamos tareas de seguimiento a partir de las tareas almacenadas
    Tarea* tarea = almacen.getTarea(0);
    Seguimiento tareaSeguimiento1(tarea->getCurso(), tarea->getDia(), tarea->getMes(), 12, 4);

    tarea = almacen.getTarea(1);
    Seguimiento tareaSeguimiento2(tarea->getCurso(), tarea->getDia(), tarea->getMes(), 12, 4);

    tarea = almacen.getTarea(2);
    Seguimiento tareaSeguimiento3(tarea->getCurso(), tarea->getDia(), tarea->getMes(), 12, 4);

    // Mostramos las tareas de seguimiento
    tareaSeguimiento1.mostrar();
    tareaSeguimiento2.mostrar();
    tareaSeguimiento3.mostrar();

    return 0;
}
