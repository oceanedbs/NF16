#include<stdlib.h>
#include<stdio.h>

int main () {

    float a, b;

    printf("Saisissez l'effectif total \n");
    scanf("%f", &a);

    printf("Saisissez la part de cette effectif que vous souhaitez convertir en pourcentage\n");
    scanf("%f", &b);

    printf("Le pourccentage est %f \n",(b*100)/a);

    return 0;

}
