#include<stdlib.h>
#include<stdio.h>

int main () {

    char a;

    printf("Saisissez un caractère \n");
    a=getchar();

    switch(a){
        case('1'):
            printf("un");
            break;
        case('2'):
            printf("deux");
            break;
        case('3'):
            printf("trois");
            break;
        default :
            printf("autre");

    }

    return 0;

}
