#include<stdio.h>
#include<stdlib.h>

int fibo1(int n){

    if(n==0 || n==1)
    {
        return n;
    }
    else{
        return fibo1(n-1)+fibo1(n-2);
    }
}

int main(){

    int a,b;
    printf("De quelle valeur voulez vous calculer la suite de Fibo ? \n");
    scanf("%d", &a);

    b=fibo1(a);

    printf("La suite de Fibonacci de %d est %d", a, b);

    return 0;


}
