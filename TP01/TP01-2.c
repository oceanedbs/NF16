#include<stdlib.h>
#include<stdio.h>

void echange(int*a, int* b){
    int c;
    c=*b;
    *b=*a;
    *a=c;


}


int main(){
    int a, b;

    printf("Saisissez la valeur de a \n");
    scanf("%d", &a);

    printf("Saisissez la valeur de b \n");
    scanf("%d", &b);

    echange(&a,&b);

    printf("La nouvelle valeur de a est %d et la nouvelle valeur de b est %d", a, b);
}


