#include<stdlib.h>
#include<stdio.h>

int main () {

    int a,b;

    printf("Saisissez un nombre \n");
    scanf("%f", &a);

    b=a%2;

    if(b==1){
        printf("Le nombre est impair");
    }

    else{
        printf ("Le nombre est pair");
    }


    return 0;

}
