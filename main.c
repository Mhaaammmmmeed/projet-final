#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define Max_livre 100

struct Livre {
    char titre[50];
    char auteur[50];
    float prix;
    int quantite;
};

struct Livre stock[Max_livre];
int nbLivres=0;


/**fonction ajouter **/


void ajouterLivre() {
    int n_ajter;
    printf("Veuillez sasir nombre des livre vous ajouter :");
    scanf("%d",&n_ajter);
    if (n_ajter < Max_livre) {
        printf("Entrez le titre du livre: ");
        scanf("%s", stock[nbLivres].titre);
        printf("Entrez le nom de l'auteur: ");
        scanf("%s", stock[nbLivres].auteur);
        printf("Entrez le prix du livre: ");
        scanf("%f", &stock[nbLivres].prix);
        printf("Entrez la quantite en stock: ");
        scanf("%d", &stock[nbLivres].quantite);
        nbLivres++;
        printf("Livre ajoute avec succes!\n");
    } else {
        printf("Le stock est plein, impossible d'ajouter plus de livres.\n");
    }
}

/**fonction d'afficher**/


void afficherLivres() {
    printf("Liste des livres en stock :\n");
    for (int i = 0; i < nbLivres; i++) {
        printf("Titre: %s \n Auteur: %s \n Prix: %.2f DH \n Quantite: %d\n", stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
    }
}


/**fonction de rechercher**/


void rechercherLivre(char titreRecherche[]) {
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(stock[i].titre, titreRecherche) == 0) {
            printf("Livre trouve :\n");
            printf("Titre: %s | Auteur: %s | Prix: %.2f MAD | Quantite: %d\n", stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
            return;
        }
    }
    printf("Livre non trouve dans le stock.\n");
}

/**fonction de supprimer**/


void supprimerLivre(char titreSuppression[]) {
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(stock[i].titre, titreSuppression) == 0) {
            for (int j = i; j < nbLivres - 1; j++) {
                stock[j] = stock[j + 1];
            }
            nbLivres--;
            printf("Livre supprime avec succes.\n");
            return;
        }
    }
    printf("Livre non trouve dans le stock, suppression impossible.\n");
}


/** fonction de d'afficher le total**/


void afficherTotalLivres() {
    int totalLivres = 0;
    for (int i = 0; i < nbLivres; i++) {
        totalLivres += stock[i].quantite;
    }
    printf("Le total des livres en stock est de : %d livres\n", totalLivres);
}


/**l  fonction principal main**/


int main() {
    int choix;
    char titreRecherche[50];
    char titreSuppression[50];

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher les livres\n");
        printf("3. Rechercher un livre\n");
        printf("4. Supprimer un livre\n");
        printf("5. Afficher le total des livres en stock\n");
        printf("0. Quitter\n");
        printf("\n");
        printf("Veuillez choise le choix que vous peux: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:


                ajouterLivre();
                break;
            case 2:
                afficherLivres();
                break;
            case 3:
                printf("Entrez le titre du livre à rechercher: ");
                scanf("%s", titreRecherche);
                rechercherLivre(titreRecherche);
                break;
            case 4:
                printf("Entrez le titre du livre à supprimer: ");
                scanf("%s", titreSuppression);
                supprimerLivre(titreSuppression);
                break;
            case 5:
                afficherTotalLivres();
                break;
            case 0:
                printf("Programme termine.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
