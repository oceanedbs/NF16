#include<stdio.h>
#include<stdlib.h>
#define TAILLE 5
#define N 3

typedef matrice[TAILLE][TAILLE];



void copie_sous_matrice(float source[N][N], float dest[N][N],  int ligne, int dim){
    int l,c,ld=0;
    for (l=0;l<N;l++)
        if (l!=ligne)
        {
            for (c=1;c<dim;c++)
                dest[ld][c-1]=source[l][c];
            ld++;
        }
}

float det(float matrice[N][N], int dim){
    float sous_matrice[N][N];
    int l,signe=1;
    float deter=0.0;
    if (dim==1) return(matrice[0][0]);
    for(l=0;l<dim;l++)
    {
        copie_sous_matrice(matrice, sous_matrice,l,dim);
        deter+=signe*matrice[l][0]*det(sous_matrice,dim-1); 
//ici on est sûr que après dim-1 appels récursifs, on passera au cas de base dim==1 où la récursivité s'arrêtera
        signe=-signe;
    }
    return(deter);
}

int main(){
   int b;

   float matrice[N][N] ={1,2,3,4,5,6,7,8,9};

    b=det(matrice,2);

    printf("%d \n",b);


}
