#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

int main(int argc, char const *argv[]) {
  DicoABR *dico;

  dico=initDico("rapidement");

  ajoutMot(dico, "rapide");
  ajoutMot(dico, "rap");
  ajoutMot(dico, "rapidement");
  ajoutMot(dico, "rapidite");
  ajoutMot(dico, "rapidita");
  ajoutMot(dico, "rapiditu");

  rechercherMot(dico, "rap");

//  supprimeMot(dico,"rapide");

  suggestionMots(dico, "rap", 3);
/*
  void parcours_infixe(DicoABR *mot, int k, char *souschaine);

  return 0;

  */
}
