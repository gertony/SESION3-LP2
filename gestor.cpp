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

    cout<<"\nTiempo restante:"<<endl;
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

    CrearProyecto proyecto1("Robot que hace delivery");
    AgregarComentario comentario1("Es un robot que hace delivery, primero con una aplicacion eliges el producto que quieres y el robot te lo lleva");
    
    AlmacenarProyectos almacenProyec;
    almacenProyec.agregarProyecto(proyecto1.crearProyecto());
    AlmacenarComentarios almacenComen;
    almacenComen.agregarComentario(comentario1.agregarComentario());
    almacenProyec.mostrarProyectos();
    almacenComen.mostrarComentarios();
    return 0;
}
