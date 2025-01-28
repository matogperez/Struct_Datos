#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void){
    int j,i,n,x,temp,c;
    int t=10;
    c=0;
    int arreglo [t];
    srand(time(NULL));
    for(i=0;i<t;i++){
        x=(rand()%20)+1;
        arreglo[i] = x;
    }
    for(j=0;j<t-1;j++){
        for(i=0;i<t;i++){
            if(arreglo[i]>arreglo[i+1]){
                temp = arreglo [i];
                arreglo[i]=arreglo[i+1];
                arreglo[i+1]=temp;
            }
        }
    }
    printf("\nEste programa genera 10 números aleatoreos entre 1 y 20");
    printf("\nEscribe un número del 1 al 30 y te diré si dos números que generé dan esa suma ");
    scanf("%i", &n);

    for(j=0;j<t;j++){
        for(i=0;i<t;i++){
            if(j<i){
                if(arreglo[j]+arreglo[i]==n){
                    printf("\nLos números %i y %i suman %i\n", arreglo[i],arreglo[j],n);
                    c=1;
                }
            }
        }
    }
    if(c==0)
    printf("\nNingún número coincidió\n");

    for(i=0;i<t;i++){
        printf("%i\t", arreglo[i]);
    }
    printf("\n");
}