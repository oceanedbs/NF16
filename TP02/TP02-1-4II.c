#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fibo2(int a){

    clock_t start, end;

    double elapsed;

    start = clock();

    if(a%2 == 1){
        return pow(fibo2(a-1)/2,2)+pow(fibo2((a-1)/2)+1,2);

    }
    else {
        return fibo2(pow(a/2,2))+2*fibo2(a/2)*fibo2((a/2)+1);
    }

    end=clock()

    elapsed = ((double)end-start)/CLOCKS_PRE_SEC

}




int main(){

    int a,b;
    printf("De quelle valeur voulez vous calculer la suite de Fibo ? \n");
    scanf("%d", &a);

    b=fibo2(a);

    printf("La suite de Fibonacci de %d est %d", a, b);

    return 0;


}
