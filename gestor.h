#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tarea
{
private:
    string curso;
    int dia;
    int mes;

public:
    Tarea(string _curso, int _dia, int _mes) : curso(_curso), dia(_dia), mes(_mes) {}

    virtual void mostrar()
    {
        cout << "Curso: " << curso << endl;
        cout << "Fecha final: " << dia << "/" << mes << endl;
    }

    string getCurso() const { return curso; }
    int getDia() const { return dia; }
    int getMes() const { return mes; }

    // En esta parte del codigo podemos ver que la clase tarea tiene un metodo virtual
    // que es utilizado por la clase AlmacenTareas para mostrar todas las tareas almacenadas.
    // Al tener el método virtual en la clase base, cualquier clase que herede de la clase Tarea puede sobrescribir el método "mostrar" y
    // modificar su comportamiento sin afectar a la funcionalidad de la clase AlmacenTareas.
    // Además se usa el const para evitar la modificación de los valores dia y mes de forma que se favorece
    // El cumplimiento de la regla de Abierto/Cerrado, además podemos ver que la clase tarea solo ejecuta acciones
    // relacionadas con la Tarea por lo que el principio de Responsabilidad unica se cumple.
};

class AlmacenTareas
{
private:
    vector<Tarea *> tareas;

public:
    void agregarTarea(Tarea *tarea)
    {
        tareas.push_back(tarea);
    }

    void mostrarTareas()
    {
        cout << "Todas las tareas que se tienen almacenadas son: " << endl;
        for (int i = 0; i < tareas.size(); i++)
        {
            cout << "Tarea " << i << ":" << endl;
            tareas[i]->mostrar();
        }
    }

    Tarea *getTarea(int i) const
    {
        return tareas[i];
    }
};
// En esta parte se puede apreciar que la clase AlmacenTareas utiliza un vector de punteros de tipo Tarea
// para almacenar todas las tareas, lo que permite agregar cualquier tipo de tarea que herede de la clase Tarea.
// Esto hace que la clase AlmacenTareas esté abierta a la extensión, ya que se pueden agregar nuevas clases de
// Tarea sin modificar la clase AlmacenTareas.

class CrearTarea
{
private:
    string curso;
    int dia;
    int mes;

public:
    CrearTarea(string _curso, int _dia, int _mes) : curso(_curso), dia(_dia), mes(_mes) {}
    Tarea *crearTarea()
    {
        return new Tarea(curso, dia, mes);
    }
};
// Aca podemos ver que tambien se aplica el Principio de responsabilidad única, ya que la clase CrearTarea se
// encarga única y exclusivamente de crear tareas de la misma forma que la clase AlmacenTareas
// Por otro lado podemos ver que el principio de inversion de dependencias se respeta, ya que las clases
// AlmacenTareas y CrearTareas no dependen de las clases Seguimineto y Tarea

class Seguimiento : public Tarea
{
private:
    int diaA;
    int mesA;

public:
    Seguimiento(string _curso, int _dia, int _mes, int _diaA, int _mesA) : Tarea(_curso, _dia, _mes), diaA(_diaA), mesA(_mesA) {}

    void mostrar() override
    {
        Tarea::mostrar();
        cout << "Dias restantes: " << diasRestantes() << endl;
    }

    int diasRestantes() const
    {
        int diaRestante = getDia() - diaA;
        int mesRestante = getMes() - mesA;

        if (mesRestante == 0)
        {
            return diaRestante;
        }
        else
        {
            int diasEnMes = 0;
            switch (getMes())
            {
            case 2:
                diasEnMes = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                diasEnMes = 30;
                break;
            default:
                diasEnMes = 31;
                break;
            }
            return diaRestante + diasEnMes * mesRestante;
        }
    }
};
// En esta última parte del codigo podemos ver como se respeta el Principio de sustitución de Liskov ya que
// La subclase Seguimiento es una extensión de la clase Tarea que añade una nueva funcionalidad, pero no altera
// el comportamiento de la clase base. El método mostrar() de la subclase Seguimiento reemplaza al método
// mostrar() de la clase base utilizando la palabra clave override, lo que indica que la implementación del
// método en la subclase es una sustitución válida de la implementación en la clase base.
class Proyecto
{
private:
    string proye;

public:
    Proyecto(string _proye) : proye(_proye) {}
    virtual void mostrarProyecto()
    {
        cout << "El proyecto tiene de nombre: " << proye << endl;
    }
    string getProyecto() const { return proye; }
};
class Comentario
{
private:
    string comentarios;

public:
    Comentario(string _comentarios) : comentarios(_comentarios) {}
    virtual void mostrarComentario()
    {
        cout << comentarios << endl;
    }
    string getComentario() const { return comentarios; }
};
class AlmacenarProyectos
{
private:
    vector<Proyecto *> proyectos;

public:
    void agregarProyecto(Proyecto*proyecto){
        proyectos.push_back(proyecto);
    }
    void mostrarProyectos()
    {
        cout << "Los proyectos que se tienen son:" << endl;
        for (int i = 0; i < proyectos.size(); i++)
        {
            cout << "Proyecto " << i << ":" << endl;
            proyectos[i]->mostrarProyecto();
        }
    }
    Proyecto *getProyectos(int i)
    {
        return proyectos[i];
    }
};
class AlmacenarComentarios
{
private:
    vector<Comentario *> comentarios;

public:
    void mostrarComentarios(){
        cout<<"Los comentarios que se tienen de los proyectos son:"<<endl;
        for (int i = 0; i < comentarios.size(); i++){
            cout<<"Comentario "<<i<<":"<<endl;
            comentarios[i]->mostrarComentario();
        }
    }
    void agregarComentario(Comentario*comentario){
        comentarios.push_back(comentario);
    }
    Comentario *getComentarios(int i)
    {
        return comentarios[i];
    }
};
class CrearProyecto
{
private:
    string proye;

public:
    CrearProyecto(string _proye) : proye(_proye) {}
    Proyecto *crearProyecto()
    {
        return new Proyecto(proye);
    }
};
class AgregarComentario
{
private:
    string comentario;

public:
    AgregarComentario(string _comentario) : comentario(_comentario) {}
    Comentario *agregarComentario()
    {
        return new Comentario(comentario);
    }
};
