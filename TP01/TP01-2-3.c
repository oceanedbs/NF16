#include<stdlib.h>
#include<stdio.h>

int main () {

    int a=1, i;

    while (a != 0){
            printf("Saisissez la table de multiplication que vous souhaitez, tapez 0 pour sortir \n");
            scanf("%d", &a);

            if(a>=1 && a<=9){
                for(i=0; i<=10; i++){
                    printf("%d x %d = %d \n", a, i, a*i);
                }
            }


    }




    return 0;

}
