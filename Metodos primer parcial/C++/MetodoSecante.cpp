#include <iostream>
#include <cmath>
using namespace std;
void metodo_secante(); //el metodo funciona bien; Tiene que automatizarme intervalos y hacerme la funcion;
void barrido(); //hace el barrido
double funcion(double); // funcion que usamos para derivar.
void hacerevaluacion();
//ya le agregue control de iteraciones.


int main(){
int a=10;
    while (a!=0)
    {   cout<<"Introduzca 0 para finalizar el programa"<<endl;
        cout<<"Introduzca 1 si desea realizar el barrido "<<endl;
        cout<<"Introduzca 2 para calcular la raiz con el metodo"<<endl;
        cout<<"Introduzca 4 para hacer la evaluacion"<<endl;
        cin>>a;
        switch (a)
        {
        case 1:
            barrido();
            break;
        case 2:
            metodo_secante();
            break;
        case 0:
            cout<<"Finalizando programa"<<endl;
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

void metodo_secante(){
    double a,b ,fa,fb,error=1,e,c,i=0,cantidad;
    cout<<"introduzca el inicio del intervalo en el que desee analizar"<<endl;
    cin>>a; //para este metodo tengo que aproxima a un valor muy proximo del intervalo.
    cout<<"introduzca el final del intervalo"<<endl;
    cin>>b;
    cout<<"introduzca el error o tolerancia"<<endl;
    cin>>e;
    cout<<"introduzca la cantidad de interacciones en la que desea realizar el metodo"<<endl;
    cin>>cantidad;
    while (error>e||cantidad>i)
    {   if (i==0||i==1)
        {   fa=funcion(a);
            fb=funcion(b);
            a=b-((fb*(a-b))/(fa-fb));
        }else if (i>1)
        {   
            fa=funcion(a);
            fb=funcion(b);
            b=a;
            a=b-((fa*(b-a))/(fb-fa)); 
            error=fabs(b-a);
        }
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

void barrido(){ //sirve para hacer el recorrido y descubrir raices
    double a,b,i,contador=0;
    cout<<"introduzca el valor minimo del dominio"<<endl;
    cin>>a;
    cout<<"introduzca el valor maximo del dominio"<<endl;
    cin>>b;
    for ( i = a; i < b; i=i+0.1) //HAY QUE TENER CUIDADO CON LOS NUMEROS QUE NO EXISTEN
    {
        if (funcion(i) * funcion(a)<0 && contador==0)
        {
            contador++;
            cout<<"en el intervalo ["<<i-1
            <<","<<i<<"]"<<" hay una raiz"<<endl;
            a=i;
        }else if (funcion(i)*funcion(a)<0 && contador!=0)
        {
            cout<<" en el intervalo ["<<i-1<<","<<i<<"] hay otra raiz"<<endl;
            a=i;
        }
        
        
    }
}
double funcion(double s){ //funcion que modificamos en base al ejercicio.
    double rta;
    rta=-23.33+79.35*s-88.09*pow(s,2)+41.6*pow(s,3)-8.68*pow(s,4)+0.658*pow(s,5);
    return rta;
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