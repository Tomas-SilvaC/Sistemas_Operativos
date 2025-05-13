/*-----------------------------------------------------
PONTIFICIA UNIVERSIDAD JAVERIANA
Tomas alejandro Silva Correal
Programación paralela via OpenMP
-------------------------------------------------------*/
/*-----------------------------------------------------
RESUMEN:
Este programa crea hilos de ejecución para cada nucleo
imprime una cadena de caracteres por cada llamado.
------------------------------------------------------*/
//Librerias necesarias
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	//Se inician hilos correspondientes	
	printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads());

	#pragma omp parallel

	{//Se ejecuta por todos los hilos
		printf("Hello World desde el hilo: %d\n", omp_get_thread_num());
	}
	return 0;
}
