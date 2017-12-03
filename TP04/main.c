#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

int main(int argc, char const *argv[]) {
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

//  supprimeMot(dico,"rapide");

 suggestionMots(dico, "rap", 5);
/*
  void parcours_infixe(DicoABR *mot, int k, char *souschaine);

  return 0;

  */
  return 0;
}
