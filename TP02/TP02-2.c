#include<stdio.h>
#include<stdlib.h>
#define NMAX 20

struct menu{
    char tab[20][60];
    int nbitem;

};

struct Un_Tableau_Entier{
    int tab[NMAX];
    int ncase;

};

typedef struct {
    double d;
    double D;
    double L;
    enum {VIN, VINAIGRE, BIERE, HUILE} type;
}tonneau;

//Notez que vin,vinaigre,biere et huile ne sont pas des chaines des caractères mais des constantes égales à la valeur de leur position dans l'énumération. Ainsi,
        //vin==0,vinaigre==1,biere==2,huile==3


//Dans cette définition c'est le deuxième "tonneau" qui représente le nom du type on aurait pu écrire
//typedef struct tonneau {....} tonneauType;  ici c'est tonneauType le nom du type et non tonneau. Cette dernière définition est équivalente aux deux instructions suivantes:
//struct tonneau {...}; typedef struct tonneau tonneauType;


int main(){
    double  V;
    tonneau t;

    printf("On calcule le volume d'un tonneau. Donnez le diamètre du tonneau \n");
    scanf("%f",t.d);

    printf("Donnez le grand diamètre du tonneau \n");
    scanf("%f", t.D);

    printf("Donnez la longueur du tonneau \n");
    scanf("%f", t.L);

    V=3.14159* t.L * ( t.d/2.0 + 2/3 * (t.D/2- t.d/2) )/2.0;

	printf("Le volume du tonneau est donc %f", V);

    }
