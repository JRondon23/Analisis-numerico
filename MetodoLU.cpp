#include <iostream>
#include <cmath>
using namespace std;

//ESTE VA COMO PIÑA; ME QUEDARIA PROBARLA EN MATRICES MAS GRANDES.
//ejercicios 1, 2, 3, 4, 5 funcionan

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
    double U[tamaño][c];
    //igualo la matriz U a la A
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c; j++)
        {
            U[i][j]=arreglo[i][j];
        }
        
    }
    //OBTENER LA MATRIZ U Y OBTENGO  LOS M
    double mguardado[tamaño*(tamaño-1)];
    int tamañom=0;
     for (int i = 1; i < tamaño; i++) {
        for (int j = 0; j < i; j++) {
                m = U[i][j] / U[j][j];
                mguardado[tamañom++]=m;
                // Restar m veces la fila j de la fila i
                for (int k = 0; k < c; k++) {
                    U[i][k] -= m * U[j][k];
                }
        }
    }
    //MOSTRAR LOS M
    cout<<"-------------------"<<endl;
    cout<<"los M guardados son: "<<endl;
    for (int i = 0; i < tamañom; i++)
    {
        cout<<mguardado[i]<<endl;
    }
    //OBTENER MATRIZ L
    int l=0;
    double L[tamaño][c];
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c; j++)
        {
            L[i][j]=arreglo[i][j];
        }
        
    }
    

    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c-1; j++)
        {
            if (i==j)
            {
                L[i][j]=1;
            }else if (i<j)
            {
                L[i][j]=0;
            }else if (i>j)
            {
                L[i][j]=mguardado[l++];
            }    
        }
        
    }
    /*Ya tenemos a L y a U Nos queda aplicar el metodo para obtener x e y*/
    //OBTENEMOS Y
    double y[tamaño];
    for (int i = 0; i < tamaño; i++)
  {
    double suma = 0;
    for (int j = 0; j < i; j++)
    {
      suma += L[i][j] * y[j];
    }
    y[i] = (L[i][c - 1] - suma) / L[i][i];
  }
    //Le cambio a U los ultimos 4
    for (int i = 0; i < tamaño; i++)
    {
        U[i][c-1]=y[i];
    } 
    //calcular raices X
  double x[tamaño];
  for (int i = tamaño - 1; i >= 0; i--) //ESTE FOR LO RECORRE AL REVES
  {
    double suma2 = 0;
    for (int j = c - 2; j > i; j--)
    {
      suma2 += U[i][j] * x[j];
    }
    x[i] = (U[i][c - 1] - suma2) / U[i][i];
  }
    //Muestro todas las matrices.
    cout<<"----------------"<<endl;
    cout<<"Se muestra A:"<<endl;
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<"["<<arreglo[i][j]<<"]";
        }
        cout<<endl;
    }
    cout<<"----------"<<endl;
    cout<<"Se muestra U: "<<endl;
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c-1; j++)
        {
            cout<<"["<<U[i][j]<<"]";
        }
        cout<<endl;
    }
    cout<<"------------"<<endl;
    cout<<"Se muestra L:"<<endl;
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < c-1; j++)
        {
            cout<<"["<<L[i][j]<<"]";
        }
        cout<<endl;
    }   
    cout<<"----------------"<<endl;
    cout<<"Se muestran las RTAS"<<endl;
    cout<<"---------------"<<endl;
    cout<<"Se Muestran los Y"<<endl;
    for (int i = 0; i < tamaño; i++)
    {
        cout<<"Y ("<<i+1<<"): "<<y[i]<<endl;
    }
    cout<<"---------------"<<endl;
    cout<<"Se Muestran los X"<<endl;

    for (int i = 0; i < tamaño; i++)
    {
        cout<<"X ("<<i+1<<"): "<<x[i]<<endl;
    }
    

    

    system("pause");
    return 0;
}