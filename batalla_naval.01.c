/* ===========================================================================
/* 
/* batalla_naval_01.c
/* 
/* 
/* Matáis González Pérez <matiasgonzalezrp@gmail.com>
/* 
/*    Copyright (C) 2025
/*    Estructura de Datos
/*    Facultad de Ciencias
/*    UAEM
/*    Cuernavaca, Morelos
/* 
/*  04. Feb. 05 (blg)
/* - from scratch
/* 
/* 
/* ===========================================================================*/

/*
Este programa es una tarea para la clase de Estructura de datos del CInC.
La instrucción es crear un programa para jugar Batalla Naval contra la computadora.
Esta es la primera versión del programa.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define SIZE 10
#define NUMBARCOS 5


typedef struct coordenadas{
	
	int x;
	int y;
	}coordenadas;

typedef struct barco{

	coordenadas coor [5];
	int tam;
	}barco;
	
	

int llenarMatriz(int (*tablero)[SIZE]);
int barcosMac(int (*tablero)[SIZE], barco conjunto[5]);

int main (void){

    srand(time(NULL));

    int tableroUsuario[SIZE][SIZE],tableroMac[SIZE][SIZE],radarUsuario[SIZE][SIZE], cFunc, contadorHitU, contadorHitM;
    int i,j;
    barco pa, acorazado, destructor1, destructor2, lanchita;
		
	barco conjunto_m[5]={pa, acorazado, destructor1, destructor2, lanchita};

    cFunc=llenarMatriz(tableroUsuario);
    cFunc=llenarMatriz(radarUsuario);
    cFunc=llenarMatriz(tableroMac);
    cFunc=barcosMac(tableroMac, conjunto_m);
    //cFunc=barcosUsuario(tableroUsuario);
    contadorHitM=0;
    contadorHitU=0;

    for(j=0;j<NUMBARCOS;j++){
        for(i=0;i<conjunto_m[j].tam;i++){
            printf("\nLa coordenada x del barco %i es: %i,", j+1, conjunto_m[j].coor[i].x);
            printf("\nLa coordenada y del barco %i es: %i", j+1, conjunto_m[j].coor[i].y);
        }
        printf("\n");

    }

}


int llenarMatriz(int (*tablero)[SIZE]){

    int i, j;
    for(j=0;j<SIZE;j++){
        for(i=0;i<SIZE;i++){
            tablero[i][j]=0;
        }
    }
    return 0;
}

int barcosMac(int (*tablero)[SIZE], barco conjunto[5]){
	
	int i, j, k, l, w, x, y, z;
	z=0;
    do{
        for(j=0;j<NUMBARCOS; j++){
            w=(rand()%2); //Para determinar si el barco crece en dirección x o en dirección y.
            x=rand()%10; //Para coordenada x de dónde inicia el barco.
            y=rand()%10; //Para coordenada yde dónde inicia el barco.
		    for(i=0;i<conjunto[j].tam;i++){
                if(((tablero[x+i][y]==0)&&(tablero[x+conjunto[j].tam][y]<SIZE))&&w==0){
                    tablero[x+i][y]=1;
                    conjunto[j].coor[i].x=x+i;
                    conjunto[j].coor[i].y=y;
                    
                }
                else if(((tablero[x][y+i]==0)&&(tablero[x][y+conjunto[j].tam]<SIZE))&&w==1){
                    tablero[x][y+i]==1;
                    conjunto[j].coor[i].x=x;
                    conjunto[j].coor[i].y=y+i;
                }
                else{
                    z=1;
                }
                
            }
        
        }
    }
    while(z==1);

}
