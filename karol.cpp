#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPSILON = 1e-3; // Tolerancia para el criterio de parada

/// Definir la matriz y el vector B
const vector<vector<double>> matriz = {
    //EJ1
    /*
    {3, -0.1,-0.2},
    {0.1, 7,-0.3},
    {0.3, -0.2, 10}
    */
    //EJ2
    /*
    {10, -3, 6},
    {1, 8, -2},
    {-2, 4, -9}
    */
    //EJ3
    /*
    {1, 7, -3},
    {4, -4, 9},
    {12, -1, 3}
    */
    //EJ4
    
    {2.00, -9.00, 7.10},
    {9.01, 3.20, 2.05},
    {18.04, 6.10, 4.10}
    
    //EJ5
    /*
    {5, 4, 0},
    {0, 12, 2},
    {4, -3, 7},
    */
};
// Definir los vectores B correspondientes
const vector<double> B = {
    // EJ1
    /*
    7.85, 19.30, 71.40
    */
    // EJ2
    /*
    24.5, -9, -50
    */
    // EJ3
    /*
    -51, 61, 8
    */
    // EJ4

    6.00, 4.20, 8.10
    
    // EJ5
    /*
    25,36, 3
    */
};
bool isDiagonallyDominantRelative(const vector<vector<double>>& A, double threshold = 1.0) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        double diagonalElement = fabs(A[i][i]);
        double maxElement = 0.0;

        // Encontrar el máximo valor absoluto en la fila (excluyendo el elemento diagonal)
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                maxElement = max(maxElement, fabs(A[i][j]));
            }
        }

        // Verificar la condición de dominancia relativa
        if (diagonalElement < threshold * maxElement) {
            return false;
        }
    }

    return true;
}

// Función para intercambiar filas en la matriz A y el vector b
void swapRows(vector<vector<double>>& A, vector<double>& b, int row1, int row2) {
    swap(A[row1], A[row2]);
    swap(b[row1], b[row2]);
}

// Función para asegurar que la matriz sea diagonalmente dominante
void makeMatrixDiagonallyDominant(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        // Verificar si la fila i es dominante
        double diagonalElement = fabs(A[i][i]);
        double sumOfOthers = 0.0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                sumOfOthers += fabs(A[i][j]);
            }
        }

        // Si no es dominante, buscar una fila que pueda ser intercambiada
        if (diagonalElement <= sumOfOthers) {
            bool found = false;
            for (int k = i + 1; k < n; ++k) {
                // Verificar si la fila k puede ser intercambiada
                double diagonalElementK = fabs(A[k][i]);
                double sumOfOthersK = 0.0;
                for (int l = 0; l < n; ++l) {
                    if (i != l) {
                        sumOfOthersK += fabs(A[k][l]);
                    }
                }

                if (diagonalElementK > sumOfOthersK) {
                    // Intercambiar la fila i con la fila k
                    swapRows(A, b, i, k);
                    found = true;
                    break;
                }
            }

            // Si no se encontró una fila adecuada, la matriz no puede ser diagonalmente dominante
            if (!found) {
                throw runtime_error("No se puede hacer la matriz diagonalmente dominante.");
            }
        }
    }
}

// Función para resolver el sistema de ecuaciones usando el método de Gauss-Seidel
vector<double> gaussSeidel(const vector<vector<double>>& A, const vector<double>& B, int maxIter) {
    int n = A.size();
    vector<double> X(n, 0.0); // Inicialización del vector de incógnitas
    vector<double> X_old(n, 0.0); // Vector para almacenar los valores anteriores

    for (int iter = 0; iter < maxIter; ++iter) {
        // Guardar los valores actuales para comparar después
        X_old = X;

        for (int i = 0; i < n; ++i) {
            double sum1 = 0.0;
            double sum2 = 0.0;

            // Suma de los productos de la fila actual antes de la incógnita
            for (int j = 0; j < i; ++j) {
                sum1 += A[i][j] * X[j];
            }

            // Suma de los productos de la fila actual después de la incógnita
            for (int j = i + 1; j < n; ++j) {
                sum2 += A[i][j] * X_old[j];
            }

            // Actualización de la incógnita
            X[i] = (B[i] - sum1 - sum2) / A[i][i];
        }

        // Calcular el error asociado a esta iteración
        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error = max(error, fabs(X[i] - X_old[i]));
        }

        // Mostrar los valores del vector X y el error en esta iteración
        cout << "Iteración " << iter + 1 << ":" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "X" << i + 1 << " = " << X[i] << endl;
        }
        cout << "Error = " << error << endl << endl;

        // Verificar el criterio de parada
        if (error < EPSILON) break;
    }

    return X;
}

// Función para comprobar la solución
bool checkSolution(const vector<vector<double>>& A, const vector<double>& B, const vector<double>& X) {
    int n = A.size();
    vector<double> AX(n, 0.0);

    // Calcular A * X
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            AX[i] += A[i][j] * X[j];
        }
    }

    // Comparar A * X con B
    for (int i = 0; i < n; ++i) {
        if (fabs(AX[i] - B[i]) > EPSILON) {
            return false; // La solución no es correcta
        }
    }

    return true; // La solución es correcta
}

int main() {
    // Copiar la matriz y el vector B para no modificar los originales
    vector<vector<double>> A = matriz;
    vector<double> B_mod = B;

    // Número máximo de iteraciones
    int maxIter = 25;

    // Verificar si la matriz es diagonalmente dominante
    if (!isDiagonallyDominantRelative(A)) {
        cout << "La matriz no es diagonalmente dominante." << endl;
        cout << "Haciendo la matriz diagonalmente dominante..." << endl;

        try {
            makeMatrixDiagonallyDominant(A, B_mod);
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            return 1;
        }

        cout << "La matriz ha sido modificada." << endl;
    }
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            cout<<"["<<A[i][j]<<"]";
        }
        cout<<"["<<B_mod[i]<<"]"<<endl;
    }


    // Llamada a la función de Gauss-Seidel
    vector<double> X = gaussSeidel(A, B_mod, maxIter);

    // Mostrar el resultado final
    cout << "Resultado final del sistema de ecuaciones:" << endl;
    for (size_t i = 0; i < X.size(); ++i) {
        cout << "X" << i + 1 << " = " << X[i] << endl;
    }

    // Verificar la solución
    if (checkSolution(matriz, B, X)) {
        cout << "La solución es correcta." << endl;
    } else {
        cout << "La solución no es correcta." << endl;
    }

    return 0;
}


