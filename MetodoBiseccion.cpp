#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double funcion(double x);

double metodoBiseccion(double a, double b, double error);

int main() {

    double a, b, error;

    cout << "METODO DE BISECCION" << endl;
    cout << "Ingrese el intervalo inicial [a,b]:\n ";
    cout<<"a: ";
    cin >> a;
    cout<<"b: ";
    cin >> b;
    cout << "Ingrese el error tolerable:\n ";
    cin >> error;

    double raiz;

    raiz = metodoBiseccion(a, b, error);
    if (raiz != -1) {
        cout << "La raiz de la funcion es: " << raiz << endl;
    }

}

double funcion(double x) {

   return std::exp(-x) - x;
   //return -0,874*x*x+1,750*x+2,627;
   //return -23,330+79,350*x-88,1*x*x+41,600*x*x*x-8,6800*x*x*x*x+0,658*x*x*x*x*x;
}

double metodoBiseccion(double a, double b, double error) {

    if (funcion(a) * funcion(b) >= 0) {
        cout << "No hay raices en dicho intervalo" << endl;
        return -1;
    }
    double c;
    while ((b - a) >= error) {
        c = (a + b) / 2;

        if (funcion(c) == 0){
            break;
        }
        if (funcion(c) * funcion(a) < 0){
            b = c;
        }else{
            a = c;
        }
    }
    return c;
}
