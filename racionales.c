#include<stdio.h>

typedef struct racional{
        int num;
        int den;
    }racional;
int maximo_comun_divisor_recursivo(int a, int b);
racional funcMult(racional r1,racional r2);
racional funcResta(racional r1, racional r2);
racional funcSuma(racional r1, racional r2);

int main (void){
    int opcion, mcd;
    
    racional n1, n2, nr;
    printf("\nDame el numerador de un número racional n1: ");
    scanf("%i", &n1.num);
    do{
        printf("\nDame el denominador de un número racional n1: ");
        scanf("%i", &n1.den);
        if(n1.den==0)
            printf("\nEl 0 no es un denominador válido, pueba otra vez");}
    while (n1.den==0);
    printf("\nDame el numerador de un número racional n2: ");
    scanf("%i", &n2.num);
    do{
        printf("\nDame el denominador de un número racional n2: ");
        scanf("%i", &n2.den);
        if(n1.den==0)
            printf("\nEl 0 no es un denominador válido, pueba otra vez");}
    while (n2.den==0);

    printf("\n¿Qué deseas hacer? \nSi quieres sumar los números, oprime 1, \nSi quieres restarlos oprime 2 \nSi quiere multiplicarlos, oprime 3: ");
    scanf("%i", &opcion);
    if (opcion==3)
       nr=funcMult(n1,n2);
    else if (opcion==2)
        nr=funcResta(n1,n2);
    else if (opcion ==1)
        nr=funcSuma(n1,n2);
    mcd=maximo_comun_divisor_recursivo(nr.num,nr.den);
    nr.num=nr.num/mcd;
    nr.den=nr.den/mcd;
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

int maximo_comun_divisor_recursivo(int a, int b) {
    if (b == 0) return a;
    return maximo_comun_divisor_recursivo(b, a % b);
}
