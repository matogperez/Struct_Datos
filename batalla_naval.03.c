/* ===========================================================================
/* 
/* batalla_naval_03.c
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
/*  11.Feb. 07 (blg)
/* - from scratch
/* 
/* 
/* ===========================================================================*/

/*
Este programa es una tarea para la clase de Estructura de datos del CInC.
La instrucción es crear un programa para jugar Batalla Naval contra la computadora.
Esta es la segunda versión del programa.
Ya está parcialmente solucionada la puesta de las coordenadas en los barcos de la máquina.
Siguientes pasos: poner las coordenadas de los barcos del usuario
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
int barcosMac(int (*tablero)[SIZE], barco *conjunto);
int comprobarBarcosMac(int (*tablero)[SIZE], int w, int x, int y, int l, int *z);
int barcosUsuario(int (*tablero)[SIZE], barco *conjunto);

int main (void){

    srand(time(NULL));

    int tableroUsuario[SIZE][SIZE],tableroMac[SIZE][SIZE],radarUsuario[SIZE][SIZE], cFunc, contadorHitU, contadorHitM;
    int i,j;
    barco pa_m, acorazado_m, destructor1_m, destructor2_m, lanchita_m, pa_u, acorazado_u, destructor1_u, destructor2_u, lanchita_u ;
		
	barco conjunto_m[5]={pa_m, acorazado_m, destructor1_m, destructor2_m, lanchita_m};
   

    barco conjunto_u[5]={pa_u, acorazado_u, destructor1_u, destructor2_u, lanchita_u};
    
    cFunc=llenarMatriz(tableroUsuario);
    cFunc=llenarMatriz(radarUsuario);
    cFunc=llenarMatriz(tableroMac);
    cFunc=barcosMac(tableroMac, conjunto_m);
    cFunc=barcosUsuario(tableroUsuario, conjunto_u);

    contadorHitM=0;
    contadorHitU=0;

    for(j=0;j<NUMBARCOS;j++){
        for(i=0;i<conjunto_m[j].tam;i++){
            printf("\nLa coordenada x del barco %i es: %i", j+1, conjunto_m[j].coor[i].x);
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

int barcosMac(int (*tablero)[SIZE], barco *conjunto){
	
	int i, j, k, m, w, x, y, z;
    
        for(j=0;j<NUMBARCOS;j++){
            do{
                z=0;
                w=(rand()%2); //Para determinar si el barco crece en dirección x o en dirección y.
                x=rand()%10; //Para coordenada x de dónde inicia el barco.
                y=rand()%10; //Para coordenada yde dónde inicia el barco.
		        //Las siguientes líneas son para asignarle los tamaños a los barcos.
                if(j==0) conjunto[j].tam=5;

                else if(j==1) conjunto[j].tam=4;
            
                else if(j==2||j==3) conjunto[j].tam=3;
            
                else conjunto[j].tam=2;

                
                printf("k: %i\n", k);
                for(i=0;i<k;i++){
                    if(i==0)
                    m=comprobarBarcosMac(tablero, w, x, y, k, &z);
                    if(m==0){
                        tablero[x+i][y]=1;
                        conjunto[j].coor[i].x=x+i;
                        conjunto[j].coor[i].y=y;
                    }
                    else if(m==1){
                        tablero[x-i][y]=1;
                        conjunto[j].coor[i].x=x-i;
                        conjunto[j].coor[i].y=y;
                    }
                    else if(m==2){
                        tablero[x][y+i]=1;
                        conjunto[j].coor[i].x=x;
                        conjunto[j].coor[i].y=y+i;
                    }
                    else if(m==3){
                        tablero[x][y-i]=1;
                        conjunto[j].coor[i].x=x;
                        conjunto[j].coor[i].y=y-i;
                    }
                    
                }
            }while(z==1);
        }
        for(j=0;j<SIZE;j++){
            for(i=0;i<SIZE;i++){
                if (tablero[i][j]==0)
                    printf("*");
                else printf("A");
            }
        printf("\n");
        }
    return 0;
}

int barcosUsuario(int (*tablero)[SIZE], barco *conjunto){

    int i, j, k;
    for(j=0;j<SIZE+1;j++){
        for(i=0;i<SIZE+1;i++){
            if(i==0&&j!=0)
                printf("%i  ", j);
            else if(j==0&&i!=0)
                printf("%c  ", 64+i);
            else
                printf("   ");
        }
        printf("\n");
    }

    return 0;
}



int comprobarBarcosMac(int (*tablero)[SIZE], int w, int x, int y, int l, int *z){

    int i, m; //i es para iterar, m es para almacenar sumas y ret es el return de la funcón
    if((tablero[x][y]==0)&&(w==0)){  //Si el barco avanza hacia la derecha ret=0, si avanza a la izquierda, ret=1
        if(x+l<SIZE){            //si avanza hacia abajo ret=2 y si avanza hacia abajo ret=3, hay que volver a intentar si return 4
            for(i=0;i<l;i++){
                m += tablero[x+i][y];
            }
            if(m==0){
                *z=0;
                return 0;
            }
            else{ *z=1;
            return 4;
            }
        }
        else{
            for(i=0;i>l;i++){
                m+= tablero[x-i][y];
            }
            if(m==0){
                *z=0;
                return 1;
            }
            else {
                *z=1;
                return 4;
            }
        }
    }
    else if((tablero[x][y]==0)&&(w==1)){
        if(y+l<SIZE){
            for(i=0;i<l;i++){
                m += tablero[x][y+i];
            }
            if(m==0){
                *z=0;
                return 2;
            }
            else{ *z=1;
            return 4;
            }
        }
        else{
            for(i=0;i<l;i++){
                m +=tablero[x][y-i];
            }
            if(m==0){
                *z=0;
                return 3;
            }
            else{ *z=1;
            return 4;
            }
        }
    
    }
    else{
        *z=1;
        return 4;
    }
}
