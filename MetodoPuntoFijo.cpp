#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
void metodo_puntofijo(); //el metodo funciona bien; Tiene que automatizarme intervalos y hacerme la funcion;
void barrido();
double funcionG(double); //funcion G que se debe modificar en base al problema
double derivada(double); //mas adelante lo configuramos.
double funcion(double); // funcion que usamos para barrido.
void evaluarfuncion();
void hacerevaluacion();
//este metodo sigue funcionando raro, Ya le agregue cant de iteraciones


int main(){
int a=10;
    while (a!=0)
    {   cout<<"Introduzca 0 para cerrar programa"<<endl;
        cout<<"Introduzca 1 si desea realizar el barrido "<<endl;
        cout<<"Introduzca 2 para calcular la raiz con el metodo"<<endl;
        cout<<"Introduzca 3 para evaluar funcion"<<endl;
        cout<<"introduzca 4 para hacer la evaluacion en intervalos"<<endl;
        cin>>a;
        switch (a)
        {
        case 1:
            barrido();
            break;
        case 2:
            metodo_puntofijo();
            break;
        case 0:
            cout<<"Finalizando programa"<<endl;
            break;
        case 3:
            evaluarfuncion();
            break;
        case 4:
            hacerevaluacion();
            break;
        default:    cout<<"No es valido el numero"<<endl;
            break;
        }
        
    }

system("pause");
return 0;
};
double funcion(double s){ //funcion a modificar para la derivada y que me encuentre el intervalo
    double rta;
    rta=exp(-s)-s;
    return rta;
}
double funcionG(double s){ //funcion a modificar para que me resuelva el metodo; es G(x)
    double rta;
    rta= exp(-s);

    return rta;
}
double derivada(double s){
 double h=1e-5;
 return (funcionG(s+h)- funcionG(s))/h;
}


void metodo_puntofijo(){
    double a,e,error,fa,c=0,i=0,cantidad;
    cout<<"introduzca a"<<endl;
    cin>>a;
    cout<<"introduzca el valor del error"<<endl;
    cin>>e;
    error=1;
    cout<<"introduzca la cantidad de iteraciones en la que desea realizar el metodo"<<endl;
    cin>>cantidad;
    while (error>e||cantidad>i)
    {   fa=funcionG(a);
        a=fa;
        error=fabs(a-c);
        c=a;
        i++;
    }
    if (cantidad<i)
    {
        cout<<"no se pudo realizar en esa cantidad de iteraciones"<<endl;
    }else
    {
        cout<<"la raiz mas proxima es: "<<c<<endl;
        cout<<"la cantidad de iteraciones fueron: "<<i<<endl;
    }
    
        
    
    system("pause");
}
void barrido(){ //sirve para hacer el recorrido y descubrir raices Y HAY QUE TENER CUIDADO CON LOS NUMEROS QUE TIRAN ERROR
    double a,b,intervalos,subintervalos,i,contador=0;
    cout<<"introduzca el valor minimo del dominio"<<endl;
    cin>>a;
    cout<<"introduzca el valor maximo del dominio"<<endl;
    cin>>b;
    for ( i = a; i <= b; i=i+0.1)
    {
        if (funcion(i) * funcion(a)<0 && contador==0)
        {
            contador++;
            cout<<"en el intervalo ["<<i-0.1<<","<<i+0.1<<"]"<<" hay una raiz"<<endl;
            a=i;
        }else if (funcion(i)*funcion(a)<0 && contador!=0)
        {
            cout<<" en el intervalo ["<<i-0.1<<","<<i+0.1<<"] hay otra raiz"<<endl;
            a=i;
        }
        
    }
}
void evaluarfuncion(){
    double a,b,fa,fb,fda,fdb;
    cout<<"ingrese el intervalo a"<<endl;
    cin>>a;
    cout<<"ingrese el intervalo b"<<endl;
    cin>>b;
    fa=funcionG(a);
    fb=funcionG(b);
    fda=derivada(a);
    fdb=derivada(b);
    if (fa>a&&fa<b)
    {
        cout<<"verifica"<<endl;
    }   else
    {
        cout<<"no verifica"<<endl;
    }
    
    if (fb>a&&fb<b)
    {
        cout<<"verifica"<<endl;
    }else
    {
        cout<<"no verifica"<<endl;
    }
    if (fda>fdb)
    {
        if (fabs(fda)<=1)
        {
            cout<<"verifica"<<endl;
        }else
        {
            cout<<"no verifica"<<endl;
        }
        
        
    }else
    {
        if (fabs(fdb)<=1)
        {
            cout<<"verifica"<<endl;
        }else
        {
            cout<<"no verifica"<<endl;
        }
        
        
    }
    cout<<fa<<endl;
    cout<<fb<<endl;
    cout<<fdb<<endl;
    cout<<fda<<endl;
}
void hacerevaluacion(){
    double a,b,intervalos;
    cout<<"introduzca el valor en el que desea evaluar la funcion"<<endl;
    cin>>a;
    cout<<"introduzca en donde quiere dejar de evaluar"<<endl;
    cin>>b;
    cout<<"introduzca en intervalos de cuantos numeros desea evaluarla"<<endl;
    cin>>intervalos;
    for (double i = a; i < b; i=i+intervalos)
    {
        cout<<" funcion valuada en: "<<i<<" es igual a: "<<funcion(i)<<endl;
    }

}

/*double acos(double x) Calcula el arco coseno de x.
double asin(double x) Calcula el arco seno de x.
double atan(double x) Devuelve el arco tangente en radianes.
double atan2(double y, double x) Calcula el arco tangente de las dos variables x e y. Es similar a calcular el arco tangente de y / x, excepto en que los signos de ambos argumentos son usados para determinar el cuadrante del resultado.
double ceil(double x) Redondea x hacia arriba al entero más cercano.
double cos(double x) devuelve el coseno de x, donde x está dado en radianes.
double cosh(double x) Devuelve el coseno hiperbólico de x.
double exp(double x) Devuelve el valor de e (la base de los logaritmos naturales) elevado a la potencia x.
double fabs(double x) Devuelve el valor absoluto del número en punto flotante x.
double floor(double x) Redondea x hacia abajo al entero más cercano.
double fmod(double x, double y)Calcula el resto de la división de x entre y. El valor devuelto es x – n * y, donde n es el cociente de x / y.
double frexp(double x, int *exp) Se emplea para dividir el número x en una fracción normalizada y un exponente que se guarda en exp $x=res \times 2^{exp}$.
long int labs(long int j) Calcula el valor absoluto de un entero largo.
double ldexp(double x, int exp) Devuelve el resultado de multiplicar el número x por 2 elevado a exp (inversa de frexp).
double log(double x); Devuelve el logaritmo neperiano de x.
double log10(double x) Devuelve el logaritmo decimal de x.
double modf(double x, double *iptr) Divide el argumento x en una parte entera y una parte fraccional. La parte entera se guarda en iptr.
double pow(double x, double y) Devuelve el valor de x elevado a y.
double sin(double x) Devuelve el seno de x.
double sinh(double x) Regresa el seno hiperbólico de x.
double sqrt(double x) Devuelve la raíz cuadrada no negativa de x.
double tan(double x) Devuelve la tangente de x.
double tanh(double x) Devuelve la tangente hiperbólica de x.*/