#include "matriz.h"

//Constructor
matriz::matriz(int f, int c) {
    filas = (f < 1 ? 1 : f);
    columnas = (c < 1 ? 1 : c);

    Matrix = new float*[filas];
    for (int i = 0; i < filas; i++)
        Matrix[i] = new float[columnas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            Matrix[i][j] = 0.0;
}

//Constructor de copia
matriz::matriz(const matriz& orig) {
    filas = orig.filas;
    columnas = orig.columnas;

    Matrix = new float*[filas];
    for (int i = 0; i < filas; i++)
        Matrix[i] = new float[columnas];

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            Matrix[i][j] = orig.Matrix[i][j];
}

//Destructor
matriz::~matriz() {
    for (int i = 0; i < filas; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
}

//Funcion getMatriz para imprimir la matriz resultante
void matriz::getMatriz() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << Matrix[i][j] << " ";
        cout << "\n";
    }
}

//Funcion setMatriz para establecer los valores de la matriz
void matriz::setMatriz() {
    cout << "\nFilas = " << filas;
    cout << "\nColumnas = " << columnas;

    cout << "\nEntrada de datos: ";

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            cout << "\nMatrix[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> Matrix[i][j];
        }
}

//Sobrecarga del operador ==
int matriz::operator==(const matriz &a) const {
    if (filas != a.filas)
        return 0;

    if (columnas != a.columnas)
        return 0;

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (Matrix[i][j] != a.Matrix[i][j])
                return 0;
    return 1;
}

//Sobrecarga del operador = para asignación
const matriz &matriz::operator=(const matriz &a) {
    if (&a != this) {
        if (filas != a.filas || columnas != a.columnas) {
            for (int i = 0; i < filas; i++) {
                delete[] Matrix[i];
            }
            delete[] Matrix;

            filas = a.filas;
            columnas = a.columnas;

            Matrix = new float*[filas];
            for (int i = 0; i < filas; i++)
                Matrix[i] = new float[columnas];
        }

        for(int i = 0; i < filas; i++)
            for(int j = 0; j < columnas; j++)
                Matrix[i][j] = a.Matrix[i][j];
    }

    return *this;
}

//Suma de matrices
matriz matriz::operator+(const matriz &a) const {
    matriz temp(filas,columnas);
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            temp.Matrix[i][j] = Matrix[i][j] + a.Matrix[i][j];
    
    return temp;
}

//Resta de matrices
matriz matriz::operator-(const matriz &a) const {
    matriz temp(filas,columnas);
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            temp.Matrix[i][j] = Matrix[i][j] - a.Matrix[i][j];
    
    return temp;
}

//Multiplicación de matrices cuadradas y matriz-vector
matriz matriz::operator*(const matriz &a) const {
    matriz temp(a.filas,a.columnas);
    for(int m = 0; m < a.filas; m++)
        for(int n = 0; n < a.columnas; n++)
            for(int i = 0; i < a.filas; i++)
                temp.Matrix[m][n] += Matrix[m][i] * a.Matrix[i][n];
    
    return temp;
}

//Potenciación casilla a casilla en una matriz
matriz matriz::operator^(int a){
    matriz temp(filas,columnas);
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            temp.Matrix[i][j] = pow(temp.Matrix[i][j],a);

    return temp;
};

//Inversa de una matriz 2x2
matriz matriz::inv2(){
    matriz temp(filas,columnas); float det;
    //Se establece una matriz de copia para realizar las operaciones con ella
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            temp.Matrix[i][j] = Matrix[i][j];
    //Se procede a calcular el determinante para matriz 2x2
    det = (temp.Matrix[0][0]*temp.Matrix[1][1])-(temp.Matrix[1][0]*temp.Matrix[0][1]);
    //Procedemos a calcular la adjunta de una matriz y su transpuesta
    temp.Matrix[0][0] = Matrix[1][1];
    temp.Matrix[1][1] = Matrix[0][0];
    temp.Matrix[0][1] *= -1;
    temp.Matrix[1][0] *= -1;
    //Procedemos a multiplicar por el reciproco del determinante
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            temp.Matrix[i][j] *= (1/det);
    
    return temp;
}

//Transpuesta de una matriz mxn
matriz matriz::trn(){
    matriz temp(filas,columnas);
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            temp.Matrix[i][j] = Matrix[j][i];
    
    return temp;
}

//Multiplicación por un escalar
matriz matriz::dot(float a){
    matriz temp(filas,columnas);
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            temp.Matrix[i][j] = Matrix[i][j] * a;
    
    return temp;
}

//Inversa de una matriz 3x3
matriz matriz::inv3(){
    matriz temp(filas,columnas),adj(filas,columnas); float det;
    //Se establece una matriz de copia para realizar las operaciones con ella
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            temp.Matrix[i][j] = Matrix[i][j];
            adj.Matrix[i][j] = Matrix[i][j];
        }
    }
    //Procedemos a calcular el determinante de una matriz 3x3
    det = (temp.Matrix[0][0]*temp.Matrix[1][1]*temp.Matrix[2][2])+(temp.Matrix[0][1]*temp.Matrix[1][2]*temp.Matrix[2][0])+(temp.Matrix[0][2]*temp.Matrix[1][0]*temp.Matrix[2][1])-((temp.Matrix[2][0]*temp.Matrix[1][1]*temp.Matrix[0][2])+(temp.Matrix[2][1]*temp.Matrix[1][2]*temp.Matrix[0][0])+(temp.Matrix[2][2]*temp.Matrix[1][0]*temp.Matrix[0][1]));
    //Calculamos cada termino de la matriz Adjunta
    float a00,a01,a02,a10,a11,a12,a20,a21,a22; 
    a00 = deter(temp.Matrix[1][1],temp.Matrix[1][2],temp.Matrix[2][1],temp.Matrix[2][2]);
    a01 = -1*deter(temp.Matrix[1][0],temp.Matrix[1][2],temp.Matrix[2][0],temp.Matrix[2][2]);
    a02 = deter(temp.Matrix[1][0],temp.Matrix[1][1],temp.Matrix[2][0],temp.Matrix[2][1]);
    a10 = -1*deter(temp.Matrix[0][1],temp.Matrix[0][2],temp.Matrix[2][1],temp.Matrix[2][2]);
    a11 = deter(temp.Matrix[0][0],temp.Matrix[0][2],temp.Matrix[2][0],temp.Matrix[2][2]);
    a12 = -1*deter(temp.Matrix[0][0],temp.Matrix[0][1],temp.Matrix[2][0],temp.Matrix[2][1]);
    a20 = deter(temp.Matrix[0][1],temp.Matrix[0][2],temp.Matrix[1][1],temp.Matrix[1][2]);
    a21 = -1*deter(temp.Matrix[0][0],temp.Matrix[0][2],temp.Matrix[1][0],temp.Matrix[1][2]);
    a22 = deter(temp.Matrix[0][0],temp.Matrix[0][1],temp.Matrix[1][0],temp.Matrix[1][1]);
    //Procedemos a crear la matriz adjunta con los valores antes calculados
    adj.Matrix[0][0] = a00; adj.Matrix[0][1] = a01; adj.Matrix[0][2] = a02;
    adj.Matrix[1][0] = a10; adj.Matrix[1][1] = a11; adj.Matrix[1][2] = a12;
    adj.Matrix[2][0] = a20; adj.Matrix[2][1] = a21; adj.Matrix[2][2] = a22;
    //Calculamos la transpuesta de la matriz adjunta
    //adj.getMatriz();
    adj = adj.trn();
    adj = adj.dot(1/det);
    return adj;
}

//Función que devuelve el determinante de una matriz 2x2
float deter(float a,float b,float c,float d){
    float det;
    det = (a*d)-(b*c);
    return det;
}