// Programa creado por Roberto Castro Gomez y Angel Alenxander Baez Flores
#include <iostream>
#include <cmath>
using namespace std;

// Definición de la clase |Roberto, Alexander|
class Empleados {
private:
    // Declaracion de los atributos
    string nombre;
    string ID;
    double salario;

public:
    // Constructores
    Empleados();
    Empleados(string nom, string ID, double sal);

    // Métodos
    string getNombre();
    string getID();
    double getSalario();

    void setNombre(string nom);
    void setID(string ID);
    void setSalario(double sal);
  
    int buscarEmpleado(string& cID, Empleados base[]); 
    void agregar(Empleados base[], int& i);
    void consultar(Empleados base[], int i);
    void modificar(Empleados base[], int i);
    void eliminar(Empleados base[], int& i);
    void sueldo(Empleados base[], int i);
};

// Constructor por defecto |Roberto|
Empleados::Empleados() {
    // Inicializa como vacia o 0
    nombre = " ";
    ID = " ";
    salario = 0;
}

// Constructor con parametros |Alexander|
Empleados::Empleados(string nom, string identifiacion, double sal) {
    // Inicializa con los parametros asignados
    nombre = nom;
    ID = identifiacion;
    salario = sal; 
}

// Metodos para obtener valores de los atributos |Roberto|
string Empleados::getNombre() {
    return nombre;
}

string Empleados::getID() {
    return ID;
}

double Empleados::getSalario() {
    return salario;
}

// Metodos para establecer valores a los atributos |Alexander|
void Empleados::setNombre(string nom) {
    nombre = nom;
}

void Empleados::setID(string identificacion) {
    ID = identificacion;
}

void Empleados::setSalario(double sal) {
    salario = sal;
}

// Metodo para buscar un empleado por ID |Roberto|
int Empleados::buscarEmpleado(string& cID, Empleados base[]) {
    for (int i = 0; i < 50; i++) {
        if (base[i].getID() == cID) {
            // Retorna la posición del empleado si se encuentra
            return i;
        }
    }
    // Retorna -1 si el empleado no se encuentra en el arreglo
    return -1;
}

// Método para agregar un empleado al arreglo |Alexander|
void Empleados::agregar(Empleados base[], int& i) {
    if (i < 50) {
        cout << "Nombre: ";
        cin >> nombre;
        cout << "ID: ";
        cin >> ID;
        // Crea un objeto Empleados y lo agrega al arreglo
        base[i] = Empleados(nombre, ID, 0); 
        i++;
    } else {
        cout << "No se pueden agregar más empleados. Límite alcanzado." << endl;
    }
}

// Método para consultar empleados |Roberto|
void Empleados::consultar(Empleados base[], int i) {
    int opcion;
    cout << "1)Consultar empleado  2)Consultar todo\n";
    cin >> opcion;
    switch (opcion) {
        case 1: {
            string cID;
            cout << "ID de empleado: ";
            cin >> cID;
            int pos = buscarEmpleado(cID, base);
            if (pos != -1) {
                cout << "Nombre: " << base[pos].getNombre() << " ID: " << base[pos].getID() << "\n";
            } else {
                cout << "Empleado no encontrado";
            }
            break;
        }
        case 2: {
            cout << "Consulta general\n";
            for (int j = 0; j < i; j++) {
                cout << "Nombre: " << base[j].getNombre() << " ID: " << base[j].getID() << "\n";
            }
            break;
        }
    }
}

// Método para modificar datos de un empleado |Roberto|
void Empleados::modificar(Empleados base[], int i) {
    string cID;
    string NID;
    string NNombre;
    cout << "ID del empleado: ";
    cin >> cID;
    int pos = buscarEmpleado(cID, base);
    if (pos != -1) {
        cout << "Nuevo nombre: ";
        cin >> NNombre;
        base[pos].setNombre(NNombre);
        cout << "Nuevo ID: ";
        cin >> NID;
        base[pos].setID(NID);
    } else {
        cout << "Empleado no encontrado";
    }
}

// Método para eliminar un empleado del arreglo |Roberto|
void Empleados::eliminar(Empleados base[], int& i) {
    string cID;
    cout << "ID del empleado: ";
    cin >> cID;
    int pos = buscarEmpleado(cID, base);
    if (pos != -1) {
        for (int j = pos; j < i - 1; j++) {
            // Elimina al empleado desplazando los elementos del arreglo
            base[j] = base[j + 1];
        }
        i--;
        cout << "Empleado borrado exitosamente";
    } else {
        cout << "Empleado no encontrado";
    }
}

// Método para calcular el sueldo de un empleado |Alexander|
void Empleados::sueldo(Empleados base[], int i) {
    string cID;
    double phe;
    double bo;
    int he;
    cout << "ID del empleado: ";
    cin >> cID;
    int pos = buscarEmpleado(cID, base);
    if (pos != -1) {
        cout << "Sueldo base: ";
        cin >> salario;
        cout << "Bonos: ";
        cin >> bo;
        cout << "Horas extra trabajadas: ";
        cin >> he;
        if (he != 0) {
            cout << "Sueldo por hora extra trabajada: ";
            cin >> phe;
            salario = salario + (he * phe) + bo;
            cout << salario;
        } else {
            salario += bo;
            cout << "El sueldo de " << base[pos].getNombre() << " es de " << salario;
        }
    } else {
        cout << "Empleado no encontrado";
    }
}