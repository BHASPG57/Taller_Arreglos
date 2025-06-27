#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// --------------------- 1. Ordenamiento ---------------------
void ordenarVector(vector<int>& vec, bool ascendente) {
    if (ascendente)
        sort(vec.begin(), vec.end());
    else
        sort(vec.rbegin(), vec.rend());
}

// --------------------- 2. Elementos Repetidos ---------------------
void contarRepetidos(const vector<int>& vec) {
    vector<bool> contado(vec.size(), false);
    for (size_t i = 0; i < vec.size(); i++) {
        if (!contado[i]) {
            int count = 1;
            for (size_t j = i + 1; j < vec.size(); j++) {
                if (vec[i] == vec[j]) {
                    count++;
                    contado[j] = true;
                }
            }
            if (count > 1) {
                cout << "Elemento " << vec[i] << " repetido " << count << " veces\n";
            }
        }
    }
}

// --------------------- 3. Matriz Temperaturas ---------------------
const int FILAS = 5;
const int COLUMNAS = 7;
void llenarMatriz(float matriz[FILAS][COLUMNAS]) {
    srand(time(0));
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLUMNAS; j++)
            matriz[i][j] = 5.0 + static_cast<float>(rand()) / RAND_MAX * (18.0 - 5.0);
}

void mostrarMatriz(float matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++)
            cout << fixed << setprecision(2) << matriz[i][j] << "\t";
        cout << endl;
    }
}

void temperaturaExtrema(float matriz[FILAS][COLUMNAS], bool maximo) {
    float temp = matriz[0][0];
    int fila = 0, col = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if ((maximo && matriz[i][j] > temp) || (!maximo && matriz[i][j] < temp)) {
                temp = matriz[i][j];
                fila = i;
                col = j;
            }
        }
    }
    cout << (maximo ? "Máxima" : "Mínima") << " temperatura: " << temp
         << " (Semana " << fila + 1 << ", Día " << col + 1 << ")\n";
}

void temperaturaMaxSemana(float matriz[FILAS][COLUMNAS], int semana) {
    if (semana < 1 || semana > FILAS) {
        cout << "Semana inválida.\n";
        return;
    }
    float temp = matriz[semana - 1][0];
    for (int j = 1; j < COLUMNAS; j++)
        temp = max(temp, matriz[semana - 1][j]);
    cout << "Temperatura más alta en la semana " << semana << ": " << temp << "\n";
}

// --------------------- 4. Determinante ---------------------
float determinante2x2(float matriz[2][2]) {
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
}

float determinante3x3(float matriz[3][3]) {
    return matriz[0][0]*(matriz[1][1]*matriz[2][2] - matriz[1][2]*matriz[2][1]) -
           matriz[0][1]*(matriz[1][0]*matriz[2][2] - matriz[1][2]*matriz[2][0]) +
           matriz[0][2]*(matriz[1][0]*matriz[2][1] - matriz[1][1]*matriz[2][0]);
}

// --------------------- 5. Tablas de Multiplicar ---------------------
void tablasMultiplicar() {
    int tabla[10][10];
    cout << "Matriz original:\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabla[i][j] = j + 1;
            cout << tabla[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nTablas de multiplicar:\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabla[i][j] = (i + 1) * (j + 1);
            cout << tabla[i][j] << "\t";
        }
        cout << endl;
    }
}

// --------------------- Menú Principal ---------------------
void menu() {
    int opcion;
    vector<int> vec = {4, 7, 2, 4, 5, 2, 8}; // ejemplo de vector
    float matrizTemp[FILAS][COLUMNAS];
    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Ordenar vector\n";
        cout << "2. Contar elementos repetidos\n";
        cout << "3. Análisis de matriz de temperaturas\n";
        cout << "4. Calcular determinante (2x2 o 3x3)\n";
        cout << "5. Tablas de multiplicar\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                ordenarVector(vec, true);
                cout << "Orden ascendente: ";
                for (int v : vec) cout << v << " ";
                cout << endl;
                ordenarVector(vec, false);
                cout << "Orden descendente: ";
                for (int v : vec) cout << v << " ";
                cout << endl;
                break;
            case 2:
                contarRepetidos(vec);
                break;
            case 3:
                llenarMatriz(matrizTemp);
                mostrarMatriz(matrizTemp);
                temperaturaExtrema(matrizTemp, true);
                temperaturaExtrema(matrizTemp, false);
                int semana;
                cout << "Ingrese la semana (1-5): ";
                cin >> semana;
                temperaturaMaxSemana(matrizTemp, semana);
                break;
            case 4:
                int tam;
                cout << "¿Tamaño de la matriz (2 o 3)? ";
                cin >> tam;
                if (tam == 2) {
                    float mat2[2][2];
                    cout << "Ingrese los elementos 2x2:\n";
                    for (int i = 0; i < 2; i++)
                        for (int j = 0; j < 2; j++)
                            cin >> mat2[i][j];
                    cout << "Determinante: " << determinante2x2(mat2) << endl;
                } else if (tam == 3) {
                    float mat3[3][3];
                    cout << "Ingrese los elementos 3x3:\n";
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            cin >> mat3[i][j];
                    cout << "Determinante: " << determinante3x3(mat3) << endl;
                } else {
                    cout << "Tamaño no soportado.\n";
                }
                break;
            case 5:
                tablasMultiplicar();
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

// --------------------- Programa Principal ---------------------
int main() {
    menu();
    return 0;
}
