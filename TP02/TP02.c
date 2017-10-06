#include<stdio.h>
#include<stdlib.h>

int fact1(int n){
    int fn=1,i;
    for(i=2;i<=n;i++){
        fn = fn *i;
    }
    return fn;
}


int main () {
    int a,b;
    printf("De quelle valeur voulez vous calculer la factorielle ? \n");
    scanf("%d", &a);

    b=fact1(a);

    printf("La factorielle de %d est %d", a, b);

    return 0;

}
