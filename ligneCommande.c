#include <stdio.h>
#include <stdlib.h>
#include "ligneCommande.h"

LigneCommande creerLC(PRODUIT *produit, int quantite) {
    LigneCommande ligne_c;
    if (produit != NULL && quantite > 0) {
        strcpy(ligne_c.refProduit, produit -> reference);
        strcpy(ligne_c.designation, produit -> designation);
        ligne_c.quantite = quantite;
        ligne_c.prixUnitaireHT = produit -> prixUnitaireHT;
        ligne_c.sousTotalHT = quantite * produit -> prixUnitaireHT;
    }
    return ligne_c;
}

void afficherLC(LigneCommande *ligne_c, int index) {
    if (ligne_c != NULL) {
        printf("[%d] %s (%s) - Quantité : %d x %.2f Euros HT = %.2f Euros HT", index, ligne_c -> designation, ligne_c -> refProduit, ligne_c -> quantite, ligne_c -> prixUnitaireHT, ligne_c -> sousTotalHT);
    }
}
