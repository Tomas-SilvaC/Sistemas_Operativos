/*******************************************|
 * Fecha: 20 Mayo, 2025                     |
 * Autor: Tomas Alejandro Silva Correal     |
 * Paralelismo mediante Openmp              |
 * Clase: Sitemas Operativos                |
********************************************/

/*----------------------------------------------------------------------------------
 * Descripcion: 
 * Este programa ejecuta el algoritmo de multiplicación de matrices segun el metodo
 * de filas por columnas, este utiliza la función OpenMP para asegurar paralelismo
 * dada una cantidad de hilos elegidas por el usuario.
----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#include "MMOpenMP.h"


int main(int argc, char *argv[]){
	//Revisa la cantidad de argumentos de entrada
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	//Asigna el tamaño de la matriz
	int N = atoi(argv[1]);

	//Define el numero de hilos para OpenMP, para usar en ejecución paralela
	int TH = atoi(argv[2]);

	//Inicializar las matrices con tamaño N
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));
	
	//Verifica en caso de que no se creara alguna de las matrices
	if (!matrixA || !matrixB || !matrixC) {
		fprintf(stderr, "Error: No se pudo asignar memoria. Reduce el tamaño de la matriz (N=%d).\n", N);
		free(matrixA); free(matrixB); free(matrixC);
		return EXIT_FAILURE;
	}

	//se llenan datos al azar
	srand(time(NULL));

	//Se definen hilos de elemetos en paralelo
	omp_set_num_threads(TH);

	//Inicializa las matrices
	iniMatrix(matrixA, matrixB, N);

	//Imprime matrices a multiplicar
	impMatrix(matrixA, N);
	impMatrix(matrixB, N);

	//Se inicia el muestreo para el experimento
	InicioMuestra();
	//Se multiplican las matrices
	multiMatrix(matrixA, matrixB, matrixC, N);
	FinMuestra();
	//Se imprime la matriz resultado
	impMatrix(matrixC, N);

	//Finaliza liberando memoria
	free(matrixA);
	free(matrixB);
	free(matrixC);
	
	return 0;
}

/*----------------------------------------------------------------------------------
 * Conclusiones: El programa trabajado realiza el algoritmo de multiplicación de
 * matrices por el metodo de filas por columnas, este programa mejora su rendimiento
 * por medio de paralelismo utilizando la funcion "Openmp". OpenMP utiliza pragmas,
 * siendo estos comandos directos al compilador que genera dicho paralelismo, los
 * hilos varian, pueden ser elegidos por el usuario o pueden usarse todos los hilos 
 * disponibles por los nucleos de la maquina (en este caso los hilos los define el
 * usuario, junto al tamaño correspondiente de las matrices).
-------------------------------------------------------------------------------------*/

