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
                
                //crea las matrices, las llena, multiplica, imprime y borra mediante liberar memoria
                int *mA = (int*) malloc(N*N*sizeof(int));
                int *mB = (int*) malloc(N*N*sizeof(int));
                int *mC = (int*) malloc(N*N*sizeof(int));
        
                IniMat(mA, mB, N);
                MulMat(mA, mB, mC, N);
        
                ImpMat(mA,N);
                ImpMat(mB,N);
                ImpMat(mC,N);
        
        
                free(mA);
                free(mB);
                free(mC);
            }
            else{
                //crea el vectorDinamico, saca del mismo elementos, los imprime y termina
        	    vectorDinamico editor;
                vectorInicio(&editor);
        
                addVector(&editor, "Hola");
                addVector(&editor, "Profesional");
        
                for (int i = 0; i < totalVector(&editor); i++)
                    printf("%s", (char *) getVector(&editor, i));
        
                borrarVector(&editor, 1);
        
                setVector(&editor, 1, "Buenos");
        
        
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
