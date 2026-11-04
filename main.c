#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "initialisation.h"
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "ligneCommande.h"
#include "statistique.h"

static int lireChoix(void)
{
    int choix;
    printf("  Votre choix : ");
    if (scanf("%d", &choix) != 1)
    {
        exit(EXIT_FAILURE);
    }
    return choix;
}

void STUB_ajouterProduit(void)      { printf("  [STUB] ajouterProduit - a implementer dans produit.c\n"); }
void STUB_modifierProduit(void)     { printf("  [STUB] modifierProduit - a implementer dans produit.c\n"); }
void STUB_supprimerProduit(void)    { printf("  [STUB] supprimerProduit - a implementer dans produit.c\n"); }
void STUB_afficherCatalogue(void)   { printf("  [STUB] afficherCatalogue - a implementer dans produit.c\n"); }

/* --- Module CLIENTS ------------------------------------------------------- */
void STUB_ajouterClient(void)       { printf("  [STUB] ajouterClient - a implementer dans client.c\n"); }
void STUB_modifierClient(void)      { printf("  [STUB] modifierClient - a implementer dans client.c\n"); }
void STUB_supprimerClient(void)     { printf("  [STUB] supprimerClient - a implementer dans client.c\n"); }
void STUB_afficherListeClients(void){ printf("  [STUB] afficherListeClients - a implementer dans client.c\n"); }

/* --- Module COMMANDES ----------------------------------------------------- */
void STUB_creerCommande(void)       { printf("  [STUB] creerCommande - a implementer dans commande.c\n"); }
void STUB_afficherUneCommande(void) { printf("  [STUB] afficherUneCommande - a implementer dans commande.c\n"); }

/* --- Module STATISTIQUES -------------------------------------------------- */
void STUB_afficherChiffreAffaires(void) { printf("  [STUB] afficherChiffreAffaires - a implementer dans statistique.c\n"); }

/* ==========================================================================
 * SOUS-MENUS : un seul motif a retenir, applique 4 fois.
 * Pour ajouter une fonctionnalite : un printf + un case + la borne max.
 * ========================================================================== */

static void menuProduits(void)
{
    int choix;
    do
    {
        printf("\n===== GESTION DES PRODUITS =====\n");
        printf("  1. Ajouter un produit\n");
        printf("  2. Modifier un produit\n");
        printf("  3. Supprimer un produit\n");
        printf("  4. Afficher le catalogue\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: STUB_ajouterProduit();    break;
            case 2: STUB_modifierProduit();   break;
            case 3: STUB_supprimerProduit();  break;
            case 4: STUB_afficherCatalogue(); break;
            case 0:                      break; /* retour automatique */
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

static void menuClients(void)
{
    int choix;
    do
    {
        printf("\n===== GESTION DES CLIENTS =====\n");
        printf("  1. Ajouter un client\n");
        printf("  2. Modifier un client\n");
        printf("  3. Supprimer un client\n");
        printf("  4. Afficher la liste des clients\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: STUB_ajouterClient();        break;
            case 2: STUB_modifierClient();       break;
            case 3: STUB_supprimerClient();      break;
            case 4: STUB_afficherListeClients(); break;
            case 0:                         break;
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

static void menuCommandes(void)
{
    int choix;
    do
    {
        printf("\n===== GESTION DES COMMANDES =====\n");
        printf("  1. Creer une commande\n");
        printf("  2. Afficher une commande\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: STUB_creerCommande();       break;
            case 2: STUB_afficherUneCommande(); break;
            case 0:                        break;
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

static void menuStatistiques(void)
{
    int choix;
    do
    {
        printf("\n===== STATISTIQUES =====\n");
        printf("  1. Chiffre d'affaires global\n");
        printf("  0. Retour au menu principal\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: STUB_afficherChiffreAffaires(); break;
            case 0:                            break;
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);
}

/* ==========================================================================
 * PROGRAMME PRINCIPAL
 * ========================================================================== */
int main(void)
{
    int choix;

    printf("==============================================\n");
    printf("  SHOPFLOW - Boutique en ligne (squelette)\n");
    printf("==============================================\n");

    do
    {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("  1. Gestion des produits\n");
        printf("  2. Gestion des clients\n");
        printf("  3. Gestion des commandes\n");
        printf("  4. Statistiques\n");
        printf("  0. Quitter\n");
        choix = lireChoix();

        switch (choix)
        {
            case 1: menuProduits();     break;
            case 2: menuClients();      break;
            case 3: menuCommandes();    break;
            case 4: menuStatistiques(); break;
            case 0: printf("\n  Au revoir !\n"); break;
            default: printf("  [!] Choix invalide.\n"); break;
        }
    } while (choix != 0);

    return EXIT_SUCCESS;
}
