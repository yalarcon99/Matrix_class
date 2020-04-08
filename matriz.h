#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <math.h>
using namespace std;

float deter(float,float,float,float);
class matriz {
public:
    matriz(int = 0, int = 0);
    matriz(const matriz& orig);
    virtual ~matriz();
    void getMatriz() const;
    void setMatriz();
    int operator==(const matriz &) const;
    int operator!=(const matriz &a) const
    {
        return !(*this == a);
    }
    const matriz &operator=(const matriz &);
    matriz operator+(const matriz &) const;
    matriz operator-(const matriz &) const;
    matriz operator*(const matriz &) const;
    matriz operator/(const matriz &) const;
    matriz operator^(int);
    matriz inv2();
    matriz trn();
    matriz dot(float);
    matriz inv3();
private:
    float **Matrix;
    int filas, columnas;
};

#endif /* MATRIZ_H */

