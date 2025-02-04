/* ===========================================================================
/* 
/* batalla_naval_00.c
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


#define SIZE=10

int llenarMatriz(int (*tablero)[SIZE]);
int barcosMac(int (*tablero)[SIZE]);

int main (void){

    srand(time(NULL));

    int tableroUsuario[SIZE][SIZE],tableroMac[SIZE][SIZE],radarUsuario[SIZE][SIZE], cFunc, contadorHitU, contadorHitM;

    cFunc=llenarMatriz(tableroUsuario);
    cFunc=llenarMatriz(radarUsuario);
    cFunc=llenarMatriz(tableroMac);
    cFunc=barcosMac(tableroMac);
    contadorHitM=0;
    contadorHitU=0;

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