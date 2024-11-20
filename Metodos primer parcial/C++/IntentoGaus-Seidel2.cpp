#include <iostream>
#include <vector>
#include <cmath>
// Ejercicios 1 , 2, 3, 4, 5 funcionan.

using namespace std;
void cargarmatriz(vector <vector<double>> &matriz, int tamaño,vector<double> &b){
    matriz.resize(tamaño, vector<double>(tamaño));
    b.resize(tamaño);

    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz.size(); j++)
        {
            cout<<"introduzca el valor que esta en la fila "<<i+1<<" columna "<<j+1<<endl;
            cin>>matriz[i][j];
        }
        cout<<"ingrese el valor de B"<<endl;
        cin>>b[i];

    }

}
//Funcion que me hace la matriz una matriz dominante.
void HacerDominante(vector <vector<double>> &matriz, int tamaño,vector<double> &b){
    for (int i = 0; i < matriz.size(); i++)
    {   double elementodiagonal = fabs(matriz[i][i]);
        double suma=0.0;

        for (int j = 0; j < matriz.size(); j++)
        {
            if (i!=j)
            {
              suma+=fabs(matriz[i][j]);  
            }
        }
         if (elementodiagonal <= suma) {
            int mejorFila = i;
            for (int k = i + 1; k < matriz.size(); k++) {
                double suma2 = 0.0;
                double diagonalelemento=fabs(matriz[k][i]);
                for (int z= 0; z <matriz.size(); z++) {
                    if (i != z) {
                        suma2 += fabs(matriz[k][z]);
                    }
                }

                if (diagonalelemento > suma2) {
                    swap(matriz[i],matriz[k]);
                    swap(b[i],b[k]);
                }
            }
        
        
    }
}
} //HASTA ACA VA BIEN

vector <double> MetodoGauss_Seidel(vector <vector<double>> &matriz, int tamaño,vector<double> &b, double e){
vector<double> X(matriz.size(),0.0);
vector<double> Xvieja(matriz.size(),0.0);
vector<vector<double>> matrizampliada(matriz.size(),vector <double>(matriz.size()+1));
 for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            matrizampliada[i][j] = matriz[i][j];
        }
        matrizampliada[i][tamaño] = b[i]; // Añadir el elemento correspondiente de b como última columna
    }
bool s=true;
while (s==true) //el WHILE TIENE MAS SENTIDO AFUERA
   {
        double suma=0.0;
        for (int i = 0; i < matrizampliada.size(); i++) //ESTE FOR LO HAGO PARA QUE ME RECORRA LA MATRIZ Y ME CALCULE LAS X
    {
      suma = 0;
      for (int j = 0; j < matrizampliada.size(); j++)
      {
        if (j != i)
        {
          suma += matrizampliada[i][j] * X[j];
        }
      }
      Xvieja[i] = X[i]; //ALMACENO LAS X EN EL "GUARDO" EN FORMA DE MATRIZ PARA QUE PUEDA USARLO DESPUES (IDEA VALEN)
      X[i] = (matrizampliada[i][matrizampliada.size()] - suma) / matrizampliada[i][i]; //OBTENGO X
    }
    for (int i = 0; i < matrizampliada.size(); i++)
    {
        if (fabs(X[i]-Xvieja[i])>e) //CUANDO REALIZO EL CALCULO DEL ERROR ES CON LAS MATRICES Y EL FOR
        {
            s= true;
        }else
        {
            s=false;
        }
        
        
    }

   }





    return X;
}




int main(){
    int tamaño;
    cout<<"introduzca el tamaño de la matriz"<<endl;
    cin>>tamaño;

    vector<vector<double>> matriz(tamaño, vector<double>(tamaño)); //Declaro vector matriz
    vector<double> B(tamaño); //matriz detras del igual

    cargarmatriz(matriz,tamaño,B);
    
    cout<<"se muestra la matriz ampliada"<<endl;
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            cout<<"["<<matriz[i][j]<<"]";
        }
        cout<<"["<<B[i]<<"]"<<endl;
    }
    HacerDominante(matriz,tamaño,B);
    cout<<"se muestra la matriz acomodada de forma dominante"<<endl;
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            cout<<"["<<matriz[i][j]<<"]";
        }
        cout<<"["<<B[i]<<"]"<<endl;
    }
    cout<<"introduzca el valor de tolerancia que desee"<<endl;
    double e;
    cin>>e;
    vector<double>Xresultado;
    Xresultado=MetodoGauss_Seidel(matriz,tamaño,B,e);
    cout<<"se muestran los resultados: "<<endl;
    for (int i = 0; i < tamaño; i++)
    {
        cout<<"X("<<i+1<<")="<<Xresultado[i]<<endl;
    }
    





    system("pause");
    return 0;
}