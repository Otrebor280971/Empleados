// Programa creado por Roberto Castro Gomez y Angel Alenxander Baez Flores
#include <iostream>
#include "class.h" 
using namespace std;

int main() {
    Empleados emp;
    // Declarar variables |Roberto, Alexander|
    string nom;
    string ID; 
    double sal; 
    string password;
    int opcion;
    int i = 0; 
    // Arreglo de objetos con capacidad para 50 empleados |Roberto|
    Empleados base[50];
    // Solicita al usuario ingresar la contraseña |Alexander|
    cout << "Password: ";
    cin >> password;
    // Verifica si la contraseña ingresada es igual a "admin" |Roberto, Alexander|
    if (password == "admin") { 
        cout << "Bienvenido\n";
        do {
            // Despliegue del menu de opciones |Alexander|
            cout << "\nQue desea hacer\n1)Agregar  2)Consultar  3)Modificar  4)Eliminar  5)Sueldo  6)Salir\n";
            cin >> opcion;
            // Evalúa la opción ingresada por el usuario
            switch (opcion) { 
                // Llama al método asignado a la opcion |Roberto|
                case 1: {
                    cout << "Agregar empleado\n";
                    emp.agregar(base, i); 
                    break;
                }
                case 2: {
                    cout << "Consultar\n";
                    emp.consultar(base, i);
                    break;
                }
                case 3: {
                    cout << "Modificar\n";
                    emp.modificar(base, i);
                    break;
                }
                case 4: {
                    cout << "Eliminar\n";
                    emp.eliminar(base, i);
                    break;
                }
                case 5: {
                    cout << "Sueldo\n";
                    emp.sueldo(base, i);
                    break;
                }
            }
        // Repite el ciclo hasta que la opción sea 6 (Salir) |Alexander|
        } while (opcion != 6);
    // Muestra un mensaje si la contraseña es incorrecta |Roberto|
    } else {
        cout << "Intentelo de nuevo";
    }
    return 0;
}
