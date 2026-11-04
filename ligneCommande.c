
#include <stdio.h>
#include <string.h>
#include "ligneCommande.h"

LigneCommande creerLC(Produit *produit, int quantite)
{
    LigneCommande ligne_c = {0};
    if (produit == NULL || quantite <= 0)
    {
        return ligne_c;
    }
    if (quantite > produit->quantiteStock)
    {
        return ligne_c;
    }
    strcpy(ligne_c.refProduit, produit->reference);
    strcpy(ligne_c.designation, produit->designation);

    ligne_c.quantite = quantite;
    ligne_c.prixUnitaireHT = produit->prixUnitaireHT;
    ligne_c.sousTotalHT = quantite * produit->prixUnitaireHT;

    return ligne_c;
}

void afficherLC(LigneCommande *ligne_c, int index)
{
    if (ligne_c != NULL)
    {
        printf("[%d] %s (%s) - Quantite : %d x %.2f euros HT = %.2f euros HT\n",
               index,
               ligne_c->designation,
               ligne_c->refProduit,
               ligne_c->quantite,
               ligne_c->prixUnitaireHT,
               ligne_c->sousTotalHT);
    }
}
