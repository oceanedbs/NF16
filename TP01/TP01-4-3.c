#include<stdlib.h>
#include<stdio.h>




int main () {

    int i;
    int* j;

    i=5;
    j=&i;

    printf("La valeur de i est %d et le contenu point� par j est %d \n",i, *j);


    *j++;

    printf("La valeur de i est %d", i);

    i=i*5;

    printf("La valeur point�e par j est %d," *j);

    j++;

    printf("La valeur point�e par j est %d," *j);

    return 0;

}
