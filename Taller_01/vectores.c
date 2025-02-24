
#include <stdio.h>
#include <stdlib.h>

#include "vectores.h"

//Inicializa el vector asignando memoria en bytes
//Parametros: un elemento de tipo vectorDinamico
//Retorno: Es void, por lo que no retorna nada
void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad); 
}

//Retorna el total de elementos del vector
//Parametros: Un elemento de tipo vectorDinamico
//Retorno: Es entero, por lo que retornara el total de elementos del vector en este mismo formato
int totalVector(vectorDinamico *V){
        return V->totalElementos;
}

//Redefine el tamaño del vector
//Parametros: Un elemento de tipo vectorDinamico y un entero de capacidad
//Retorno: Es void, por lo que no retorna nada
static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);
        
        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}

//Añade elementos al vector
//Parametros: Un elemento de tipo vectorDinamico y void de elemento
//Retorno: Es void, por lo que no retorna nada
void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}

//Libera la memoria de un vector
//Parametros: Un elemento de tipo vectorDinamico
//Retorno: Es void, por lo que no retorna nada
void freeVector(vectorDinamico *V){
        free(V->elementos);
}

//Extraer elemento de vector
//Parametros: Un elemento de tipo vectorDinamico y un entero de indice
//Retorno: Es void, por lo que no retorna nada
void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}

//Asigna un elemento al vector en el indice
//Parametros: Un elemento de tipo vectorDinamico, un entero de indice y el elemento a agregar
//Retorno: Es void, por lo que no retorna nada
void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}

//Borra todos los elementos de un vector
//Parametros: Un elemento de tipo vectorDinamico y un entero de indice
//Retorno: Es void, por lo que no retorna nada
void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}
