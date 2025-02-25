//----------------------------------
//20/02/2025
//Tomas Alejandro Silva Correal
//Taller de Compilación modular
//-----------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"
#include "vectores.h"

int main(int argc, char *argv[]){
        if(argc<2){
                printf("Error en argumentos de entrada");
                printf("        $./ejecutable N\n");
	        exit(0);
        }
        int n=0;
        printf("---------------------------------------------\n");
        printf("¿Que desea realizar el dia de hoy?\n");
        printf("---------------------------------------------\n");
        printf("1. Multiplicar matrices\n");
        printf("2. vectorDinamico\n");
        printf("3. Salir\n");
        printf("---------------------------------------------\n");
        printf("Digite el valor de su elección: ");
        scanf("%d", &n);
        //Revisa que n este en el parametro
        while(n < 1 || 3 < n){
            printf("Valor no permitido, digite nuevamente: ");
            scanf("%d", &n);
        }
        while(n !=3 ){
            if(n==1){
                //Valor de entrada (tamaño de matriz)
                int N = (int) atoi(argv[1]);
                printf("Tamaño de matriz: %d \n", N);
                
                //Crea las matrices, las llena, multiplica, imprime y borra mediante liberar memoria
                int *mA = (int*) malloc(N*N*sizeof(int));
                int *mB = (int*) malloc(N*N*sizeof(int));
                int *mC = (int*) malloc(N*N*sizeof(int));
        	//Llena las matrices
                IniMat(mA, mB, N);
		//Multiplica y guarda en mC
                MulMat(mA, mB, mC, N);

		//Imprime las matrices
                ImpMat(mA,N);
                ImpMat(mB,N);
                ImpMat(mC,N);
        
        	//Libera memoria de las matrices
                free(mA);
                free(mB);
                free(mC);
            }
            else{
                //Crea el vectorDinamico, saca del mismo elementos, los imprime y termina
        	    vectorDinamico editor;
                vectorInicio(&editor);
        	//Añade elementos al vector
                addVector(&editor, "Hola");
                addVector(&editor, "Profesional");
        	//Se imprimen elementos del vector
                for (int i = 0; i < totalVector(&editor); i++)
                    printf("%s", (char *) getVector(&editor, i));
        	//Se borra elemento en el vector con indice = 1
                borrarVector(&editor, 1);
        	//Dado que el indice no cumple con los requisitos, no se logra agregar el elemento al vector
                setVector(&editor, 1, "Buenos");

		//Imprime los elementos de la matriz - siendo solo el elemento 0, dado que el total de los elementos 
		//en el vector es igual a 1
                for (int i = 0; i < totalVector(&editor); i++)
                printf("%s ", (char *) getVector(&editor, i));
            }
            //vuelve a preguntar por n
            printf("Digite el valor de su elección: ");
            scanf("%d", &n);
            while(n < 1 || 3 < n){
            printf("Valor no permitido, digite nuevamente: ");
            scanf("%d", &n);
            }
        }
        return 0;
}
