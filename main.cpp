#include "matriz.h"

int main() {
    
    matriz A(3,3),B(3,1),C,D,E(2,2);; float e;
    A.setMatriz();
    /*
    B = A;
    cout << "\n|- IMPRIMIENDO LAS DOS MATRICES A = B -|\n";
    cout << "\nMatriz A: \n";
    A.getMatriz();
    C = A.trn();
    cout << "\nMatriz C (A transpuesta): \n";
    C.getMatriz();
    cout << "\nIngrese el escalar a multiplicar por la matriz C: \n";
    cin >> e;
    cout << "\nMatriz C * " << e <<": \n";
    D = C.dot(e);
    D.getMatriz();
    cout << "\nInversa de una matriz 2x2: \n";
    E.setMatriz();
    cout << "\nEsta es la matriz de 2x2 que digito: \n";
    E.getMatriz();
    cout << "\nLa inversa de la matriz es: \n";
    E = E.inv2();
    E.getMatriz();*/
    cout<<"\n\n";
    B.setMatriz();
    cout<<"\n\n";
    B.getMatriz();
    cout << "\n\n";
    C = A * B;
    C.getMatriz();
    return 0;
}



