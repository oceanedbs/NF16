#include<stdlib.h>
#include<stdio.h>

int main () {

    int a, b, c=0;

    printf("Saisissez la valeur de a \n");
    scanf("%d", &a);

    printf("Saisissez la valeur de b \n");
    scanf("%d", &b);

    c=a;
    a=b;
    b=c;

    printf("La nouvelle valeur de a est %d et la nouvelle valeur de b est %d", a, b);

    return 0;

}
