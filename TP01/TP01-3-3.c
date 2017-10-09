#include<stdlib.h>
#include<stdio.h>

int main () {
	int tab[3][4];
	int i, a=12;

	for(i=0; i<4; i++){
		for(j=0; j<5, j++){
		tab[i][j]=a;
		a++;
		}
	}

	return 0;

}
