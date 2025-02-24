#ifndef _VECTORES_H_
#define _VECTORES_H_
#define CAPACIDAD_INICIAL 4
//Estructura de VectorDinamico
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

//Inicializa el vector asignando memoria en bytes
//Parametros: un elemento de tipo vectorDinamico
//Retorno: Es void, por lo que no retorna nada
void vectorInicio(vectorDinamico *V);

//Retorna el total de elementos del vector
//Parametros: Un elemento de tipo vectorDinamico
//Retorno: Es entero, por lo que retornara el total de elementos del vector en este mismo formato
int totalVector(vectorDinamico *V);

//Redefine el tamaño del vector
//Parametros: Un elemento de tipo vectorDinamico y un entero de capacidad
//Retorno: Es void, por lo que no retorna nada
static void resizeVector(vectorDinamico *V, int capacidad);

//Añade elementos al vector
//Parametros: Un elemento de tipo vectorDinamico y void de elemento
//Retorno: Es void, por lo que no retorna nada
void addVector(vectorDinamico *V, void *elemento);
//Libera la memoria de un vector
//Parametros: Un elemento de tipo vectorDinamico
//Retorno: Es void, por lo que no retorna nada
void freeVector(vectorDinamico *V);

//Extraer elemento de vector
//Parametros: Un elemento de tipo vectorDinamico y un entero de indice
//Retorno: Es void, por lo que no retorna nada
void *getVector(vectorDinamico *V, int indice);

//Asigna un elemento al vector en el indice
//Parametros: Un elemento de tipo vectorDinamico, un entero de indice y el elemento a agregar
//Retorno: Es void, por lo que no retorna nada
void setVector(vectorDinamico *V, int indice, void *elemento);

//Borra todos los elementos de un vector
//Parametros: Un elemento de tipo vectorDinamico y un entero de indice
//Retorno: Es void, por lo que no retorna nada
void borrarVector(vectorDinamico *V, int indice);

#endif