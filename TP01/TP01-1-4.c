#include<stdlib.h>
#include<stdio.h>

int main () {

    float a,b;

    printf("Saisissez la temp�rature en degr� Farenheit \n");
    scanf("%f", &a);

    b=(5/9.0)*(a-32);

    printf("Cette temp�rature �quivault � %.2f degr�s Celsius", b  );

    return 0;

}
