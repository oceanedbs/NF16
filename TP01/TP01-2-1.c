#include<stdlib.h>
#include<stdio.h>

int main () {

    char a;

    printf("Saisissez un carat�re \n");
    scanf("%c", &a);


    if(a<=32){
        printf("C'est une commande sp�ciale ASCII");
    }
    else if (32<a && a<=47){
        printf("C'est un signe de ponctuation");
    }

    else if (a>=65 && a<=96){
        printf("C'est une majuscule");
    }

    else {
        printf("C'est une minuscule");
    }
    return 0;

}
