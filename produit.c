#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produit.h"

PRODUIT ajouterP(PRODUIT *produit) {
    int nbP = 0;
    int i = nbP;
    int nb_lig = 8;

    /* Affichage du tableau */
    printf("Les produits actcuellement disponibles :\n");
    for (i = 0; i < nb_lig; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produit[i].reference, produit[i].designation, produit[i].categorie, produit[i].prixUnitaireHT, produit[i].quantiteStock, produit[i].seuilAlerte,produit[i].actif);
    }

    /* Ajout d'un produit */
    do {
        printf("Entrez la référence commerciale du produit (SKU) : ");
        scanf("%s", produit[i].reference);
    } while (produit[i].reference[0] == '\0');

    do {
        printf("Entrez le libèle du produit : ");
        fgets(produit[i].designation, strlen(produit[i].designation), stdin);
    } while (produit[i].designation[0] == '\0');

    do {
        printf("Entrez la catégorie du produit : ");
        scanf("%s", produit[i].categorie);
    } while (produit[i].categorie[0] == '\0');

    do {
        printf("Entrez le prix hors taxes du produit : ");
        scanf("%f", produit[i].prixUnitaireHT);
    } while (produit[i].prixUnitaireHT == 0);

    do {
        printf("Entrez le stock disponibles du produit : ");
        scanf("%s", produit[i].quantiteStock);
    } while (produit[i].quantiteStock < 0);

    do {
        printf("Entrez le seuil de réapprovisionnemment du produit : ");
        scanf("%f", produit[i].seuilAlerte);
    } while (produit[i].seuilAlerte < 0);

    do {
        printf("Est-ce que le produit est actif ? (1 = Oui, 0 = Non");
        scanf("%d", &produit[i].actif);
    } while (produit[i].actif != 0 && produit[i].actif != 1);

    /* Affichage du nouveau tableau avec les nouveaux produits */
    printf("La liste des produits mis à jour :\n");
    for (i = 0; i < nb_lig; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produit[i].reference, produit[i].designation, produit[i].categorie, produit[i].prixUnitaireHT, produit[i].quantiteStock, produit[i].seuilAlerte,produit[i].actif);
    }
    return *produit;
}

PRODUIT modifierP(PRODUIT *produit) {
    int nb_lig = 8;
    int i;
    int nbP;

    /* Affichage du tableau */
    printf("Les produits actcuellement disponibles :\n");
    for (i = 0; i < nb_lig; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produit[i].reference, produit[i].designation, produit[i].categorie, produit[i].prixUnitaireHT, produit[i].quantiteStock, produit[i].seuilAlerte,produit[i].actif);
    }

    /* Sélection d'un produit */
    do {
        printf("Entrez le produit à modifier (de 0 à 7) : ");
        scanf("%d", &nbP);
    } while (nbP < 0 && nbP > 8);
    nbP = i;

    /* Modification du produit */
    do {
        printf("Nouveau prix unitaire HT");
        scanf("%.2f", &produit[i].prixUnitaireHT);
    } while (produit[i].prixUnitaireHT < 1);

    do {
        printf("Mise à jour du stock : ");
        scanf("%d", &produit[i].quantiteStock);
    } while (produit[i].quantiteStock < 0);

    do {
        printf("Modification du seuil d'alerte : ");
        scanf("%f", &produit[i].seuilAlerte);
    } while (produit[i].seuilAlerte < 0);

    /* Affichage du nouveau tableau */
    printf("La liste des produits mis à jour :\n");
    for (i = 0; i < nb_lig; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produit[i].reference, produit[i].designation, produit[i].categorie, produit[i].prixUnitaireHT, produit[i].quantiteStock, produit[i].seuilAlerte,produit[i].actif);
    }
    return *produit;
}

PRODUIT supprimerP(PRODUIT *produit) {
    int nb_lig = 8;
    int i;
    int nbP = 0;

    /* Affichage du tableau */
    printf("Les produits actcuellement disponibles :\n");
    for (i = 0; i < nb_lig; i++) {
        printf("%s, %s, %s, %f, %d, %d, %d", produit[i].reference, produit[i].designation, produit[i].categorie, produit[i].prixUnitaireHT, produit[i].quantiteStock, produit[i].seuilAlerte,produit[i].actif);
    }

    /* Sélection du produit à supprimer */
    do {
        printf("Entrez le produit à supprimer (de 0 à 7) : ");
        scanf("%d", &nbP);
    } while (nbP < 0 && nbP > 8);
    printf("Produits actuellement disponibles :\n");
    nbP = i;
}
