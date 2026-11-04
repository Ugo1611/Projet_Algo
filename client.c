//
//
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"


/* Ajouter un client */
void ajouterClient(BOUTIQUE *boutique)
{
    CLIENT nouveauClient;

    if (boutique->nbClients >= boutique->capaciteClients)
    {
        boutique->capaciteClients += 10;

        boutique->clients = realloc(
            boutique->clients,
            boutique->capaciteClients * sizeof(CLIENT)
        );
    }

    nouveauClient.idClient = boutique->idClientSuivant;
    boutique->idClientSuivant++;

    printf("Nom : ");
    scanf("%49s", nouveauClient.nom);

    printf("Prenom : ");
    scanf("%49s", nouveauClient.prenom);

    printf("Email : ");
    scanf("%79s", nouveauClient.email);

    printf("Telephone : ");
    scanf("%14s", nouveauClient.telephone);

    printf("Rue : ");
    scanf(" %79[^\n]", nouveauClient.adresse.rue);

    printf("Ville : ");
    scanf(" %49[^\n]", nouveauClient.adresse.ville);

    printf("Code postal : ");
    scanf("%5s", nouveauClient.adresse.codePostal);

    printf("Pays : ");
    scanf(" %49[^\n]", nouveauClient.adresse.pays);

    nouveauClient.pointsFidelite = 0;
    nouveauClient.nbCommandes = 0;
    nouveauClient.capaciteCommandes = 0;
    nouveauClient.commandes = NULL;
    nouveauClient.actif = 1;

    boutique->clients[boutique->nbClients] = nouveauClient;
    boutique->nbClients++;

    printf("Client ajoute avec succes !\n");
}


/* Afficher les clients */
void afficherClients(BOUTIQUE boutique)
{
    int i;

    for (i = 0; i < boutique.nbClients; i++)
    {
        if (boutique.clients[i].actif == 1)
        {
            printf("\nID : %d\n", boutique.clients[i].idClient);
            printf("Nom : %s\n", boutique.clients[i].nom);
            printf("Prenom : %s\n", boutique.clients[i].prenom);
            printf("Email : %s\n", boutique.clients[i].email);
            printf("Telephone : %s\n", boutique.clients[i].telephone);

            printf("Rue : %s\n", boutique.clients[i].adresse.rue);
            printf("Ville : %s\n", boutique.clients[i].adresse.ville);
            printf("Code postal : %s\n", boutique.clients[i].adresse.codePostal);
            printf("Pays : %s\n", boutique.clients[i].adresse.pays);

            printf("Points de fidelite : %d\n",
                   boutique.clients[i].pointsFidelite);
        }
    }
}


/* Rechercher un client */
void rechercherClient(BOUTIQUE boutique)
{
    int id;
    int i;
    int trouve = 0;

    printf("ID du client : ");
    scanf("%d", &id);

    for (i = 0; i < boutique.nbClients; i++)
    {
        if (boutique.clients[i].idClient == id &&
            boutique.clients[i].actif == 1)
        {
            printf("\nID : %d\n", boutique.clients[i].idClient);
            printf("Nom : %s\n", boutique.clients[i].nom);
            printf("Prenom : %s\n", boutique.clients[i].prenom);
            printf("Email : %s\n", boutique.clients[i].email);
            printf("Telephone : %s\n", boutique.clients[i].telephone);

            trouve = 1;
        }
    }

    if (trouve == 0)
    {
        printf("Client introuvable.\n");
    }
}


/* Modifier un client */
void modifierClient(BOUTIQUE *boutique)
{
    int id;
    int i;
    int trouve = 0;

    printf("ID du client a modifier : ");
    scanf("%d", &id);

    for (i = 0; i < boutique->nbClients; i++)
    {
        if (boutique->clients[i].idClient == id &&
            boutique->clients[i].actif == 1)
        {
            printf("Nouveau nom : ");
            scanf("%49s", boutique->clients[i].nom);

            printf("Nouveau prenom : ");
            scanf("%49s", boutique->clients[i].prenom);

            printf("Nouvel email : ");
            scanf("%79s", boutique->clients[i].email);

            printf("Nouveau telephone : ");
            scanf("%14s", boutique->clients[i].telephone);

            trouve = 1;

            printf("Client modifie avec succes !\n");
        }
    }

    if (trouve == 0)
    {
        printf("Client introuvable.\n");
    }
}


/* Supprimer un client */
void supprimerClient(BOUTIQUE *boutique)
{
    int id;
    int i;
    int trouve = 0;

    printf("ID du client a supprimer : ");
    scanf("%d", &id);

    for (i = 0; i < boutique->nbClients; i++)
    {
        if (boutique->clients[i].idClient == id &&
            boutique->clients[i].actif == 1)
        {
            boutique->clients[i].actif = 0;

            trouve = 1;

            printf("Client supprime avec succes !\n");
        }
    }

    if (trouve == 0)
    {
        printf("Client introuvable.\n");
    }
}


/* Modifier l'adresse de livraison */
void modifierAdresseLivraison(BOUTIQUE *boutique)
{
    int id;
    int i;
    int trouve = 0;

    printf("ID du client : ");
    scanf("%d", &id);

    for (i = 0; i < boutique->nbClients; i++)
    {
        if (boutique->clients[i].idClient == id &&
            boutique->clients[i].actif == 1)
        {
            printf("Nouvelle rue : ");
            scanf(" %79[^\n]", boutique->clients[i].adresse.rue);

            printf("Nouvelle ville : ");
            scanf(" %49[^\n]", boutique->clients[i].adresse.ville);

            printf("Nouveau code postal : ");
            scanf("%5s", boutique->clients[i].adresse.codePostal);

            printf("Nouveau pays : ");
            scanf(" %49[^\n]", boutique->clients[i].adresse.pays);

            trouve = 1;

            printf("Adresse modifiee avec succes !\n");
        }
    }

    if (trouve == 0)
    {
        printf("Client introuvable.\n");
    }
}


/* Afficher les points de fidelite */
void afficherPointsFidelite(BOUTIQUE boutique)
{
    int id;
    int i;
    int trouve = 0;

    printf("ID du client : ");
    scanf("%d", &id);

    for (i = 0; i < boutique.nbClients; i++)
    {
        if (boutique.clients[i].idClient == id &&
            boutique.clients[i].actif == 1)
        {
            printf("Points de fidelite : %d\n",
                   boutique.clients[i].pointsFidelite);

            trouve = 1;
        }
    }

    if (trouve == 0)
    {
        printf("Client introuvable.\n");
    }
}


/* Ajouter des points de fidelite */
void ajouterPointsFidelite(BOUTIQUE *boutique)
{
    int id;
    int points;
    int i;
    int trouve = 0;

    printf("ID du client : ");
    scanf("%d", &id);

    for (i = 0; i < boutique->nbClients; i++)
    {
        if (boutique->clients[i].idClient == id &&
            boutique->clients[i].actif == 1)
        {
            printf("Nombre de points a ajouter : ");
            scanf("%d", &points);

            if (points > 0)
            {
                boutique->clients[i].pointsFidelite += points;

                printf("Points ajoutes avec succes !\n");
            }
            else
            {
                printf("Nombre de points invalide.\n");
            }

            trouve = 1;
        }
    }

    if (trouve == 0)
    {
        printf("Client introuvable.\n");
    }
}


