#include<stdlib.h>
#include<stdio.h>

int main () {

    float a,b;

    printf("Saisissez la température en degré Farenheit \n");
    scanf("%f", &a);

    b=(5/9.0)*(a-32);

    printf("Cette température équivault à %.2f degrés Celsius", b  );

    return 0;

}
