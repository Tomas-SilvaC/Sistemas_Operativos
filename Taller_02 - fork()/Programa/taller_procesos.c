/******************************************************************************
 * PONTIFICIA UNIVERSIDAD JAVERIANA
 * Tomas Alejandro Silva Correal - Juan Pabon Vargas
 * Taller02 - Taller de Fork()
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
typedef struct{
    char nombre[50];
    int resultado;
} Resultados;

int main(int argc, char *argv[])
{
	//Obtiene tamaC1o de arreglos
	int N1=atoi(argv[1]);
	int N2=atoi(argv[3]);
	//Los procesos:
	int GrandHijo;
	int Segundohijo;
    int Primerhijo;
    int Padre;
	//Obtiene los datos de nombre de archivo
	char *archivo00=argv[2];
	char *archivo01=argv[4];

	/*-----------------------------------------------------------------------------------
	SECCIÓN DE LECTURA DE ARCHIVOS DADO EL NOMBRE DEL ARCHIVO COMO PARAMETRO DE ENTRADA
	-----------------------------------------------------------------------------------*/
	//LECTURA DEL PRIMER ARCHIVO
	FILE *arc00;
	arc00 = fopen(archivo00, "r");
	int *ArF00= calloc(N1, sizeof(int));
	//Llena un arreglo temporal con "calloc" para los datos del archivo
	for(int i=0; i<N1; i++) {
		fscanf(arc00, "%d", &ArF00[i]);
	}
	fclose(arc00);

	//LECTURA DEL SEGUNDO ARCHIVO
	FILE *arc01;
	arc01 = fopen(archivo01, "r");
	int *ArF01= calloc(N1, sizeof(int));
	//Llena un arreglo temporal con "calloc" para los datos del archivo
	for(int i=0; i<N1; i++) {
		fscanf(arc01, "%d", &ArF01[i]);
	}
	fclose(arc01);
	/*-----------------------------------------------------------------------------------
	SECCICN DE PROCESOS CON FORK
	-----------------------------------------------------------------------------------*/
	//Para el proceso padre (el cual usa pipe()), se creal el pipe
	int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }
    
	//Crea variables de suma donde se guarda cada resultado de proceso
	int sumA=0;
    int sumB=0;
    int sumC=0;
    int sumD=0;
    
    //GrandHijo como nuevo proceso
    sleep(1);
	GrandHijo=fork(); //Genera un proceso hijo por fork()
	if(GrandHijo == 0) {
	    Resultados R;
	    R.resultado=0;
	    close(pipefd[0]); // Deja solo para escribir
	    strcpy(R.nombre, "Sumatoria de primer arreglo");
		for(int i=0; i<N1; i++) {
			R.resultado += ArF00[i];
		}
		//escribe el resultado en el pipe
		write(pipefd[1], &R.resultado, sizeof(int));
		close(pipefd[1]);
		exit(0);
	}
    //SegundoHijo como nuevo proceso
	sleep(1);
	Segundohijo=fork(); //Genera un proceso hijo por fork()
	if(Segundohijo == 0) {
	    Resultados R;
	    R.resultado=0;
		close(pipefd[0]); // Deja solo para escribir
		for(int i=0; i<N2; i++) {
			R.resultado += ArF01[i];
		}
		//escribe el resultado en el pipe
		write(pipefd[1], &R.resultado, sizeof(int));
		close(pipefd[1]);
		exit(0);
	}
	
    //PrimerHijo como nuevo proceso
    sleep(1);
	Primerhijo=fork(); //Genera un proceso hijo por fork()
    if(Primerhijo == 0){
        Resultados R;
	    R.resultado=0;
		close(pipefd[0]); // Deja solo para escribir
        for(int i=0; i<N1; i++){
			R.resultado += ArF00[i];
		}
        for(int i=0; i<N2; i++){
			R.resultado += ArF01[i];
		}
        //escribe el resultado en el pipe
        write(pipefd[1], &R.resultado, sizeof(int));
        close(pipefd[1]);
		exit(0);
    }
    
    sleep(1);
    //Padre como nuevo proceso
    Padre=fork(); //Genera un proceso hijo por fork()
    if (Padre == 0) {
        
		close(pipefd[1]); // Deja para solo leer
        Resultados R;
	    R.resultado=0;
		int resultado;
		for (int i = 0; i < 3; i++) {
			read(pipefd[0], &resultado, sizeof(int));
			if(i == 0)
			    printf("Resultado de la sumatoria del primer arreglo %d\n", resultado);
			else if(i == 1)
			    printf("Resultado de la sumatoria del segundo arreglo %d\n", resultado);
			else{
			    printf("Resultado de la sumatoria de ambos arreglos %d\n", resultado);
			}
		}
	    //Cierra el pipe
		close(pipefd[0]);
		exit(0);
	}
	// Padre espera a todos
	for (int i = 0; i < 4; i++) {
		wait(NULL);
	}
	//Libera memoria dinamica por medio de "Free"
	free(ArF00);
	free(ArF01);
	return 0;
}
