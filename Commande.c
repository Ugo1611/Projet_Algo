#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commande.h"
#include "ligneCommande.h"

/* Recalcul des montants */
static void recalculerMontants(COMMANDE *c)
{
    int i;
    c->montantBrutHT = 0;

    for (i = 0; i < c->nbLignes; i++)
    {
        c->lignes[i].sousTotalHT =
            c->lignes[i].quantite * c->lignes[i].prixUnitaireHT;
        c->montantBrutHT += c->lignes[i].sousTotalHT;
    }

    if (c->montantBrutHT < 100) c->tauxRemise = 0;
    else if (c->montantBrutHT < 300) c->tauxRemise = 5;
    else if (c->montantBrutHT < 600) c->tauxRemise = 10;
    else c->tauxRemise = 15;

    c->montantRemise = c->montantBrutHT * c->tauxRemise / 100;
    c->montantHT = c->montantBrutHT - c->montantRemise;
    c->montantTVA = c->montantHT * 0.20f;
    c->fraisPort = (c->montantBrutHT >= 60) ? 0 : 5.90f;
    c->montantTTC = c->montantHT + c->montantTVA + c->fraisPort;
}

/* Calcul des points de fidélité */
static int calculerPoints(COMMANDE *c)
{
    return (int)(c->montantTTC / 10);
}

/* Mise à jour de la commande enregistrée chez le client */
static void synchroniserCommande(COMMANDE *c, CLIENT *client)
{
    int i;

    for (i = 0; i < client->nbCommandes; i++)
    {
        if (client->commande[i].numero == c->numero)
        {
            client->commande[i] = *c;
            return;
        }
    }
}

/* CREATION */
COMMANDE creerCommande(COMMANDE *commande, LigneCommande *lignecommande,CLIENT *client, DATE *date, ADRESSE *adresse,PRODUIT *produit)
{
    COMMANDE c = {0};
    COMMANDE *temp;

    if (!lignecommande || !client || !date || !adresse || !produit ||
        produit->actif != 1 || lignecommande->quantite <= 0 ||
        lignecommande->quantite > produit->quantiteStock)
        return c;

    c.lignes = malloc(sizeof(LigneCommande));
    c.date = malloc(sizeof(DATE));
    c.adresse = malloc(sizeof(ADRESSE));

    if (!c.lignes || !c.date || !c.adresse)
    {
        free(c.lignes);
        free(c.date);
        free(c.adresse);
        return (COMMANDE){0};
    }

    c.lignes[0] = creerLC(produit, lignecommande->quantite);
    if (c.lignes[0].quantite <= 0)
    {
        free(c.lignes);
        free(c.date);
        free(c.adresse);
        return (COMMANDE){0};
    }

    *c.date = *date;
    *c.adresse = *adresse;
    c.numero = client->nbCommandes + 1;
    c.idClient = client->idClient;
    strcpy(c.statut, "EN_COURS");
    c.nbLignes = c.capaciteLignes = 1;

    recalculerMontants(&c);

    if (client->nbCommandes >= client->capaciteCommandes)
    {
        int capacite = client->capaciteCommandes == 0 ? 2 :
                       client->capaciteCommandes * 2;

        temp = realloc(client->commande, capacite * sizeof(COMMANDE));
        if (!temp)
        {
            free(c.lignes);
            free(c.date);
            free(c.adresse);
            return (COMMANDE){0};
        }

        client->commande = temp;
        client->capaciteCommandes = capacite;
    }

    produit->quantiteStock -= c.lignes[0].quantite;
    client->pointsFidelite += calculerPoints(&c);
    client->commande[client->nbCommandes++] = c;

    if (commande) *commande = c;

    return c;
}

/* MODIFICATION : ajout d'un produit */
COMMANDE modifierCommande(COMMANDE *commande, LigneCommande *lignecommande,CLIENT *client, DATE *date, ADRESSE *adresse,PRODUIT *produit, int *nb_ligne_produit,int *nb_client_commande)
{
    LigneCommande *temp;
    LigneCommande ligne;
    int anciensPoints;

    (void)date;
    (void)adresse;
    (void)nb_ligne_produit;
    (void)nb_client_commande;

    if (!commande || !lignecommande || !client || !produit ||
        strcmp(commande->statut, "EN_COURS") != 0 ||
        produit->actif != 1 || lignecommande->quantite <= 0 ||
        lignecommande->quantite > produit->quantiteStock)
        return commande ? *commande : (COMMANDE){0};

    anciensPoints = calculerPoints(commande);
    ligne = creerLC(produit, lignecommande->quantite);
    if (ligne.quantite <= 0) return *commande;

    if (commande->nbLignes >= commande->capaciteLignes)
    {
        int capacite = commande->capaciteLignes == 0 ? 2 :
                       commande->capaciteLignes * 2;

        temp = realloc(commande->lignes, capacite * sizeof(LigneCommande));
        if (!temp) return *commande;

        commande->lignes = temp;
        commande->capaciteLignes = capacite;
    }

    commande->lignes[commande->nbLignes++] = ligne;
    produit->quantiteStock -= ligne.quantite;

    recalculerMontants(commande);
    client->pointsFidelite += calculerPoints(commande) - anciensPoints;
    synchroniserCommande(commande, client);

    return *commande;
}

/* SUPPRESSION d'une ligne */
COMMANDE supprimerCommande(COMMANDE *commande, LigneCommande *lignecommande,CLIENT *client, DATE *date, ADRESSE *adresse,PRODUIT *produit, int *nb_ligne_produit,int *nb_client_commande)
{
    int i, index, anciensPoints;

    (void)date;
    (void)adresse;
    (void)nb_client_commande;

    if (!commande || !lignecommande || !client || !produit ||
        !nb_ligne_produit || strcmp(commande->statut, "EN_COURS") != 0)
        return commande ? *commande : (COMMANDE){0};

    index = *nb_ligne_produit;

    if (index < 0 || index >= commande->nbLignes ||
        strcmp(commande->lignes[index].refProduit, produit->reference) != 0)
        return *commande;

    anciensPoints = calculerPoints(commande);
    produit->quantiteStock += commande->lignes[index].quantite;

    for (i = index; i < commande->nbLignes - 1; i++)
        commande->lignes[i] = commande->lignes[i + 1];

    commande->nbLignes--;
    recalculerMontants(commande);

    client->pointsFidelite += calculerPoints(commande) - anciensPoints;
    synchroniserCommande(commande, client);

    return *commande;
}

/* ANNULATION */
COMMANDE annulerCommande(COMMANDE *commande, CLIENT *client,DATE *date, ADRESSE *adresse,int *nb_ligne_commande)
{
    (void)date;
    (void)adresse;
    (void)nb_ligne_commande;

    if (!commande || !client ||
        strcmp(commande->statut, "EN_COURS") != 0 ||
        commande->nbLignes <= 0)
        return commande ? *commande : (COMMANDE){0};

    client->pointsFidelite -= calculerPoints(commande);
    strcpy(commande->statut, "ANNULEE");

    synchroniserCommande(commande, client);

    return *commande;
}
