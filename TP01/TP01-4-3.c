#include<stdlib.h>
#include<stdio.h>




int main () {

    int i;
    int* j;

    i=5;
    j=&i;

    printf("La valeur de i est %d et le contenu pointé par j est %d \n",i, *j);


    *j++;

    printf("La valeur de i est %d", i);

    i=i*5;

    printf("La valeur pointée par j est %d," *j);

    j++;

    printf("La valeur pointée par j est %d," *j);

    return 0;

}
