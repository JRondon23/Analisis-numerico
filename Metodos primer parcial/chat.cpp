#include <iostream>
#include <cmath>
using namespace std;

// Definición de la función g(x) para el método de punto fijo
double funcionG(double x) {
    return (0.874 * pow(x, 2) - 2.627) / 1.750;
}

// Función para el método de punto fijo
void metodo_puntofijo(double valor_inicial, double tolerancia, int max_iteraciones) {
    double x0 = valor_inicial;
    double x1;
    int iteracion = 0;
    double error;

    do {
        x1 = funcionG(x0); // Aplicar la función g(x)
        error = fabs(x1 - x0); // Calcular el error
        x0 = x1; // Actualizar x0
        iteracion++;

        if (iteracion > max_iteraciones) {
            cout << "Número máximo de iteraciones alcanzado." << endl;
            break;
        }
    } while (error > tolerancia);

    cout << "Raíz aproximada encontrada: " << x1 << endl;
    cout << "Número de iteraciones: " << iteracion << endl;
}

int main() {
    double valor_inicial, tolerancia;
    int max_iteraciones;

    cout << "Introduzca el valor inicial: ";
    cin >> valor_inicial;
    cout << "Introduzca la tolerancia para el error: ";
    cin >> tolerancia;
    cout << "Introduzca el número máximo de iteraciones: ";
    cin >> max_iteraciones;

    metodo_puntofijo(valor_inicial, tolerancia, max_iteraciones);

    return 0;
}
