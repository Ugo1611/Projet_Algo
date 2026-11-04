#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistique.h"

#include "ligneCommande.h"

typedef struct {
    char reference[12];
    char designation[60];
    int quantiteVendue;
} ProduitVente;

typedef struct {
    int idClient;
    char nom[50];
    char prenom[50];
    float chiffreAffaires;
} ClientCA;

float calculerCATotal(BOUTIQUE *b) {
    int i,j;
    float total = 0.0;
    if (b == NULL) {
        return 0.0;
    }
    for (i = 0; i < b -> nbClients; i++) {
        for (j = 0; j < b -> clients[i].nbCommandes; j++) {
            COMMANDE *cmd = &(b -> clients[i].commande[j]);
            if (strcmp (cmd -> statut, "ANNULEE") != 0) {
                total += cmd -> montantHT;
            }
        }
    }
    return total;
}

float calculerCAPeriode(BOUTIQUE *b, int mois, int annee) {
    int i,j;
    float periode = 0.0;
    if (b == NULL) {
        return 0.0;
    }
    for (i = 0; i < b -> nbClients; i++) {
        for (j = 0; j < b -> clients[i].nbCommandes; j++) {
            COMMANDE *cmd = &(b -> clients[i].commande[j]);
            if (strcmp (cmd -> statut, "ANNULEE") != 0) {
                periode += cmd -> montantHT;
            }
        }
    }
    return periode;
}

void afficherPalmaresP(BOUTIQUE *b) {
    int i,j,k,l,minIdx,limite;
    ProduitVente *stats = NULL;
    ProduitVente temp;
    if (b == NULL || b -> nbClients == 0) {
        return;
    }
    stats = (ProduitVente *) malloc(b -> nbProduits * sizeof(ProduitVente));
    if (stats == NULL) {
        printf("Erreur d'allocation mémoire");
        return;
    }
    for (i = 0; i < b -> nbProduits; i++) {
        strcpy(stats[i].reference, b -> produits[i].reference);
        strcpy(stats[i].designation, b -> produits[i].designation);
        stats[i].quantiteVendue = 0;
    }
    for (i = 0; i < b -> nbClients; i++) {
        for (j = 0; j < b -> clients[i].nbCommandes; j++) {
            COMMANDE *cmd = &(b -> clients[i].commande[j]);
            if (strcmp(cmd -> statut, "ANNULEE") != 0) {
                for (k = 0; k < cmd -> nbLignes; k++) {
                    for (l = 0; l < b -> nbProduits; l++) {
                        if (strcmp(stats[l].reference, cmd -> lignes[k].refProduit) == 0) {
                            stats[l].quantiteVendue += cmd -> lignes[k].quantite;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < b -> nbProduits - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < b -> nbProduits; j++) {
            if (stats[j].quantiteVendue > stats[minIdx].quantiteVendue) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = stats[i];
            stats[i] = stats[minIdx];
            stats[minIdx] = temp;
        }
    }
    printf("PALMARES DES PRODUITS (TOP 5)\n");
    limite = (b -> nbProduits < 5) ? b -> nbProduits : 5;
    for (i = 0; i < limite; i++) {
        printf("%d. [%s] %s - Quantité vendue : %d\n", i+1, stats[i].reference, stats[i].designation, stats[i].quantiteVendue);
    }
    free(stats);
}

void afficherAlertesS(BOUTIQUE *b) {
    int i;
    int alerte = 0;
    if (b == NULL || b -> nbProduits == 0) {
        printf("Aucun produit au catalogue\n");
        return;
    }
    printf("ALERTE REAPPROVISIONNEMENT STOCK\n");
    for (i = 0; i < b -> nbProduits; i++) {
        if (b -> produits[i].actif && b -> produits[i].quantiteStock <= b -> produits[i].seuilAlerte) {
            printf("[%s] %s - Stock restant : %d (Seuil d'alerte : %d)\n", b -> produits[i].reference, b -> produits[i].designation, b -> produits[i].quantiteStock, b -> produits[i].seuilAlerte);
            alerte = 1;
        }
    }
    if (!alerte) {
        printf("Aucun produit en alerte de stock\n");
    }
}
