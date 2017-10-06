#include<stdlib.h>
#include<stdio.h>

int main () {

    float a, b;

    printf("Saisissez un premier nombre \n");
    scanf("%f", &a);

    printf("Saisissez un second nombre \n");
    scanf("%f", &b);

    printf("La somme de %f et %f est %f \n", a, b, a+b);

    return 0;

}
