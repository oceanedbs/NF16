#include<stdlib.h>
#include<stdio.h>

int main () {

    int a=0;

    do {
        printf("Saisissez une valeur de A \n");
        scanf("%d", &a);
    }while(a>=0);

    printf("-1 \n Vous avez saisie une valeur négative");

    return 0;

}
