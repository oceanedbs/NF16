#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

int main(){
  Arbre *dico;
  int w;
  w=strncmp("rapide", "rap", strlen("rap"));
  printf("%d", w);
  dico=initDico("rapidement");

  ajoutMot(dico, "rapide");
  ajoutMot(dico, "rap");
  ajoutMot(dico, "rapidement");
  ajoutMot(dico, "rapidite");
  ajoutMot(dico, "rapidita");
  ajoutMot(dico, "rapiditu");
  ajoutMot(dico, "nul");
  ajoutMot(dico, "final");
  ajoutMot(dico, "chaise");
  ajoutMot(dico, "tableau");
  ajoutMot(dico, "table");
  ajoutMot(dico, "tablier");
  ajoutMot(dico, "tabouret");

 rechercherMot(dico, "rap");

 suggestionMots(dico, "ra", 5);

  return 0;
}
