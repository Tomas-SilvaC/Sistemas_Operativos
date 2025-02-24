#ifndef _MATRICES_H_
#define _MATRICES_H_

//Inicializa dos matrices de tamaño n
//Parametros: Dos matrices de enteros y un entero n de tamaño
//Retorno: Es void, por lo que no retorna nada
void IniMat(int *a, int *b, int n);

//Imprime una matriz de tamaño n
//Parametros: Una matriz de enteros y un entero n de tamaño
//Retorno: Es void, por lo que no retorna nada
void ImpMat(int *a, int n);

//Multiplica dos matrices de tamaño n y lo guarda en una tercera matriz de igual tamaño
//Parametros: Tres matrices de enteros y un entero n de tamaño
//Retorno: Es void, por lo que no retorna nada
void MulMat(int *a, int*b, int *c, int n);

#endif