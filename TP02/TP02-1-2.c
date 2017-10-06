#include<stdio.h>
#include<stdlib.h>


int fact1(int n){
    if(n==0)
        return  1;
    else
        return n*fact1(n-1); 
//ici on est sûr que après n appels récursifs, on passera au cas de base n==0 où la récursivité s'arrêtera
}

int main () {
    int a,b;

    printf("De quelle valeur voulez vous calculer la factorielle ? \n");
    scanf("%d", &a);

    b=fact1(a);

    printf("La factorielle de %d est %d", a, b);


    return 0;
}
