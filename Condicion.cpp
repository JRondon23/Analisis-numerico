#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//ESTA FINALIZADO
//SI EN LA DIAGONAL PRINCIPAL HAY 0 NO SE PUEDE OBTENER INVERSA
void cargarmatriz(vector <vector<double>> &matriz, int tamaño){
    matriz.resize(tamaño, vector<double>(tamaño));

    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz.size(); j++)
        {
            cout<<"introduzca el valor que esta en la fila "<<i+1<<" columna "<<j+1<<endl;
            cin>>matriz[i][j];
        }
        cout<<"ingrese el valor de B"<<endl;

    }

}
void Reducir(vector <vector<double>> &matriz, int tamaño, vector<vector<double>> &matrizI){


    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz.size(); j++)
        {
            if (i!=j)
            {
                matrizI[i][j]=0;
            }
        }
        matrizI[i][i]=1;
        
    }
    for (int i = 0; i < tamaño; i++) {
        double diagElem = matriz[i][i];
        if (diagElem == 0) {
            cout << "Error: Elemento diagonal es cero, la matriz no es invertible." << endl;
            return;
        }
        // Normalizar la fila
        for (int j = 0; j < tamaño; j++) {
            matriz[i][j] /= diagElem;
            matrizI[i][j] /= diagElem;
        }
        // Hacer ceros en la columna i de otras filas
        for (int k = 0; k < tamaño; k++) {
            if (k != i) {
                double factor = matriz[k][i];
                for (int j = 0; j < tamaño; j++) {
                    matriz[k][j] -= factor * matriz[i][j];
                    matrizI[k][j] -= factor * matrizI[i][j];
                }
            }
        }
    }
}
void CalcularCondicion(vector <vector<double>> &matriz, int tamaño, vector<vector<double>> &matrizI,int &condicion){
    double resultadoM [tamaño];
    double resultadototalM=0.0;

    for (int i = 0; i < matriz.size(); i++)
    {   resultadoM[i]={0.0};
        for (int j = 0; j < matriz.size(); j++)
        {
            resultadoM[i]+=fabs(matriz[j][i]);
        }
        if (resultadoM[i]>resultadototalM)
        {
            resultadototalM=resultadoM[i];
        }
    }
    double resultadoMI [tamaño];
    double resultadototalMI=0.0;

    for (int i = 0; i < matriz.size(); i++)
    {   resultadoMI[i]={0.0};
        for (int j = 0; j < matriz.size(); j++)
        {
            resultadoMI[i]+=fabs(matrizI[j][i]);
        }
        if (resultadoMI[i]>resultadototalMI)
        {
            resultadototalMI=resultadoMI[i];
        }
    }
    cout<<"Resultado de la Norma de la Matriz: "<<resultadototalM<<endl;
    cout<<"Resultado de la Norma de la Matriz Inversa: "<<resultadototalMI<<endl;
    condicion= floor(log10 (fabs(resultadototalM*resultadototalMI)));
}







int main(){
int tamaño;
cout<<"introduzca el tamaño de la matriz"<<endl;
cin>>tamaño;
vector<vector<double>> matrizA(tamaño,vector <double>(tamaño));
vector<vector<double>> matrizCopia(tamaño,vector <double>(tamaño));
cargarmatriz(matrizA,tamaño);
matrizCopia=matrizA;

for (int i = 0; i < matrizA.size(); i++)
{
    for (int j = 0; j < matrizA.size(); j++)
    {
        cout<<"["<<matrizA[i][j]<<"]";
    }
    cout<<endl;
}
vector<vector<double>> matrizInversa(tamaño,vector <double>(tamaño));
Reducir(matrizA,tamaño,matrizInversa);
cout<<"se muestra la inversa de la matriz"<<endl;
for (int i = 0; i < matrizA.size(); i++)
{
    for (int j = 0; j < matrizA.size(); j++)
    {
        cout<<"["<<matrizInversa[i][j]<<"]";
    }
    cout<<endl;
}
int condicion=0;
CalcularCondicion(matrizCopia,tamaño,matrizInversa,condicion);
cout<<"El numero P es: "<<condicion<<endl;
double error; //ME HABIA OLVIDADO EL DOUBLE
cout<<"introduzca el error con el que esta trabajando"<<endl;
cin>>error;
int t=floor(log10(abs(error)))*-1;//PORQUE KAROL LE SUMA 1????
int n=t-condicion;
cout<<"el valor de N es: "<<fabs(n)<<endl;




system("pause");
return 0;
}