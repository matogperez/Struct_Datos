#include<stdio.h>

typedef struct racional{
        int num;
        int den;
    }racional;

racional funcMult(racional r1,racional r2);
racional funcResta(racional r1, racional r2);
racional funcSuma(racional r1, racional r2);

int main (void){
    int opcion;
    
    racional n1, n2, nr;
    printf("\nDame el numerador de un número racional n1: ");
    scanf("%i", &n1.num);
    printf("\nDame el denominador de un número racional n1: ");
    scanf("%i", &n1.den);
    printf("\nDame el numerador de un número racional n2: ");
    scanf("%i", &n2.num);
    printf("\nDame el denominador de un número racional n2: ");
    scanf("%i", &n2.den);

    printf("\n¿Qué deseas hacer? Si quieres sumar los números, oprime 1, si quieres restarlos oprime 2 y si quiere multiplicarlos, oprime 3: ");
    scanf("%i", &opcion);
    if (opcion==3)
       nr=funcMult(n1,n2);
    else if (opcion==2)
        nr=funcResta(n1,n2);
    else if (opcion ==1)
        nr=funcSuma(n1,n2);
    printf("El resultado de la operación es:\n%i\n__\n%i\n", nr.num,nr.den);
}


racional funcMult(racional r1,racional r2){
    racional rf;
    rf.num =(r1.num*r2.num);
    rf.den =(r1.den*r2.den);
    return rf;
}

racional funcResta(racional r1, racional r2){
    racional rf;
    rf.num=(r1.num*r2.den)-(r2.num*r1.den);
    rf.den=(r1.den*r2.den);
    return rf;
}

racional funcSuma(racional r1, racional r2){
    racional rf;
    rf.num=(r1.num*r2.den)+(r2.num*r1.den);
    rf.den=(r1.den*r2.den);
    return rf;
}