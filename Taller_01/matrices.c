
#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"
//Inicializa dos matrices de tamaño n
//Parametros: Dos matrices de enteros y un entero n de tamaño
//Retorno: Es void, por lo que no retorna nada
void IniMat(int *a, int *b, int n){
        for(int i=0; i<n*n; i++){
                a[i] = i;
                b[i] = 3*i;
        }
}

//Imprime una matriz de tamaño n
//Parametros: Una matriz de enteros y un entero n de tamaño
//Retorno: Es void, por lo que no retorna nada
void ImpMat(int *a, int n){

        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        printf(" %d ", a[i*n+j]);
                }
                printf("\n");
        }
        printf("--------------------------------\n");
}

//Multiplica dos matrices de tamaño n y lo guarda en una tercera matriz de igual tamaño
//Parametros: Tres matrices de enteros y un entero n de tamaño
//Retorno: Es void, por lo que no retorna nada
void MulMat(int *a, int*b, int *c, int n){
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        int sum=0;
                        int *pA, *pB;
                        pA=a+i*n;
                        pB=b + j;
                        for(int k=0; k<n; k++, pA++, pB+=n){
                                sum += (*pA * *pB);
                        }
                        c[i*n+j] = sum;
                }
        }
}
