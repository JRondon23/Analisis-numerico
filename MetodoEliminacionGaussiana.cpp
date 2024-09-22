#include <iostream>
#include <cmath>
using namespace std;

//ESTE VA COMO PIÑA; ME QUEDARIA PROBARLA EN MATRICES MAS GRANDES.
// Ejercicios: 1, 2, 3, 4, 5 van


int main(){ 
    int tamaño=0,c;
    double m;
    cout<<"ingrese el tamaño de la matriz cuadrada ampliada"<<endl;
    cin>>tamaño;
    c=tamaño+1;
    double arreglo[tamaño][c];
    //cargar matriz
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c; j++)
        {
                cout<<"ingrese el valor que va en la posicion ["<<i<<","<<j<<"]"<<endl;
                cin>>arreglo[i][j];
            
        }
        
    }
    //nos acomoda la matriz para que no haya 0 en la principal
     double arreglo2[tamaño][c];
   for (int i = 0; i < tamaño; i++) {
        if (arreglo[i][i] == 0) {
            if (i < tamaño - 1) {
                // hace el intercambio
                for (int j = 0; j < c; j++) {
                    arreglo2[i][j] = arreglo[i][j];
                    arreglo[i][j] = arreglo[i + 1][j];
                    arreglo[i + 1][j] = arreglo2[i][j];
                }
            }
        }
    }
    //mostrar matriz.
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arreglo[i][j]<<" ";
        }
        cout<<endl;
    }

    //Intentar reducirla
     for (int i = 1; i < tamaño; i++) {
        for (int j = 0; j < i; j++) {
                m = arreglo[i][j] / arreglo[j][j];
                
                // Restar m veces la fila j de la fila i
                for (int k = 0; k < c; k++) {
                    arreglo[i][k] -= m * arreglo[j][k];
                }
        }
    }
    cout<<"----------------"<<endl;
    cout<<"Se muestra la matriz ya triangulada"<<endl;
    cout<<"----------------"<<endl;
    //mostrar matriz ya reducida
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arreglo[i][j]<<" ";
        }
        cout<<endl;
        
 }
    
    //calcular raices
  double resultados[tamaño];
  for (int i = tamaño - 1; i >= 0; i--) //ESTE FOR LO RECORRE AL REVES
  {
    double suma = 0;
    for (int j = c - 2; j > i; j--)
    {
      suma += arreglo[i][j] * resultados[j];
    }
    resultados[i] = (arreglo[i][c - 1] - suma) / arreglo[i][i];
  }

  //mostrar raices
    for (int i = 0; i < tamaño; i++)
    {
        cout<<"X ("<<i+1<<"): "<<resultados[i]<<endl;
    }
    

    system("pause");
    return 0;
}
















/*for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arreglo[i][j]<<" ";
        }
        cout<<endl;
        
 }*/