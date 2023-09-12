#include <iostream>
#include <cmath>
using namespace std;

//  para calcular el factorial de un número
unsigned long long Factorial(int num) {
    unsigned long long factorial_ = 1;
    for (int i = 1; i <= num; i++) {
        factorial_ *= i;
    }
    return factorial_;
}

//calculo combinaciones
unsigned long long Combinacion(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Valor no válido
    }
    
    return Factorial(n) / (Factorial(n - k) * Factorial(k));
}

//expansión del binomio //
void expansion_bionomio(int combinacion_, int coeficiente1, int coeficiente2, char literal1, char literal2) {
    for (int i = 0; i <= combinacion_; ++i) {
        unsigned long long expansion = Combinacion(combinacion_, i);
        cout << expansion << " * " << "(" << coeficiente1 << literal1 << ")^" << (combinacion_ - i) << " * " << "(" << coeficiente2 << literal2 << ")^" << i;
        
        // Si i es menor, seguirá poniendo el +, pero si i es igual que el exponente, se acaba la operación
        if (i < combinacion_) {
            cout << " + ";
        } else {
            cout << endl;
        }
        
    } 
}

int main() {
    int combinacion;
    int coeficiente1_, coeficiente2_;
    char literal1_, literal2_;
    //exponentes de los literales//
    int combinacion1, combinacion2;

    cout << "Ingresa el exponente del binomio: ";
    cin >> combinacion;

    cout << "\nIngrese el primer coeficiente: ";
    cin >> coeficiente1_;
    
    cout << "Ingrese el primer literal del coeficiente: ";
    cin >> literal1_;
    
    cout << "Ingrese el exponente de la primera literal: ";
    cin >> combinacion1;
    
    cout << "\nIngrese el segundo coeficiente: ";
    cin >> coeficiente2_;
    
    cout << "Ingrese el segundo literal del coeficiente: ";
    cin >> literal2_;  
    
    cout << "Ingrese el exponente de la segunda literal: ";
    cin >> combinacion2; 

    cout << "(" << coeficiente1_ << literal1_ << " + " << coeficiente2_ << literal2_ << ")^" << combinacion << endl;

    expansion_bionomio(combinacion, coeficiente1_, coeficiente2_, literal1_, literal2_);

    //resutado de toda la operación
    cout << "Resultado: ";
    for (int i = 0; i <= combinacion; ++i) {
        unsigned long long expansion = Combinacion(combinacion, i);
        int coeficiente = expansion * pow(coeficiente1_, combinacion - i) * pow(coeficiente2_, i);
        if (coeficiente != 0) {
            if (i > 0) {
                cout << " + ";
            }
            cout << coeficiente;
            
            //literal 1 
            if (combinacion - i > 0) {
                cout << literal1_;
                if (combinacion - i > 1) {
                    cout << "^" << (combinacion - i);
                }
            }

            //literal 2 nada, nada//
            
            if (i > 0) {
                cout << literal2_;
                if (i > 1) {
                    cout << "^" << i;
                }
            }
            cout << " ";
        }
    }
    cout << endl;

    
    return 0;
}
