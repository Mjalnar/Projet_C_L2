//
// Created by david on 23/10/2023.
//

#include "list.h"
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Crée une liste vide avec un nombre donné de niveaux (nb_lvl)
list* create_empty_list(int nb_lvl){
    // Allocation de mémoire pour la structure list
    list* new_list = (list*) malloc(sizeof(list));

    new_list->max_lvl = nb_lvl;

    // Allocation de mémoire pour le tableau de pointeurs heads
    new_list->heads = (cell**) malloc(sizeof(cell*) * nb_lvl);

    for(int i = 0; i < nb_lvl; i++){
        new_list->heads[i] = NULL;
    }
    return new_list;
}

// Ajoute une cellule en tête de la liste
list* add_val_to_head(list *mylist, cell* mycell){

    for(int i = 0; i <= mycell->nb_lvl-1; ++i) {
        // La cellule pointe vers l'élément suivant dans le niveau i
        mycell->next[i] = mylist->heads[i];

        // La tête de la liste pointe vers la nouvelle cellule dans le niveau i
        mylist->heads[i] = mycell;
    }
    return mylist;
}

// Affiche les éléments d'un niveau donné de la liste
void print_lvl_list(list* mylist, int nb_lvl){
    // Initialisation des pointeurs temporaires
    cell * tmp = mylist->heads[nb_lvl];
    cell * tmp2 = mylist->heads[0];

    printf("[list head_%d @-]--", nb_lvl + 1);

    while(tmp != NULL){
        // Vérification si la valeur de tmp est la même que la valeur de tmp2
        if (tmp->value == tmp2->value){
            printf(">[ %d|@- ]--", tmp->value);
            tmp = tmp->next[nb_lvl]; // Passage à l'élément suivant dans ce niveau
        }
        else{
            printf("-----------");
        }
        tmp2 = tmp2->next[0]; // Passage à l'élément suivant dans le niveau de base
    }
    printf(">NULL\n");
}



// Affiche tous les niveaux de la liste
void print_all_list(list* mylist){
    // Parcourt et affiche chaque niveau de la liste
    for (int i = 0; i < mylist->max_lvl; i++){
        print_lvl_list(mylist, i); // Utilise la fonction existante pour afficher un niveau spécifique
    }
    return;
}

// Trie la liste dans l'ordre croissant par rapport à une valeur donnée
list* tri_liste_croisant(list *mylist, int nb_lvl, int val) {
    cell *mycell = add_val_cell(nb_lvl, val);

    int lvl = mylist->max_lvl - 1;

    // Initialise un pointeur temporaire pour parcourir les niveaux
    cell **cur = mylist->heads;

    // Si la liste est vide, ajoute la valeur comme nouvelle tête
    if (mylist->heads[0] == NULL) {
        return add_val_to_head(mylist, mycell);
    }
    else {
        // Parcourt les niveaux pour l'insertion triée
        while (lvl >= 0) {
            cell *temp = cur[lvl];

            if (temp == NULL) {
                // Si le niveau est vide, vérifie le niveau de la cellule à insérer
                if (mycell->nb_lvl - 1 >= lvl) {
                    mycell->next[lvl] = temp;
                    cur[lvl] = mycell;
                }
            }
            else {
                if (temp->value >= mycell->value) {
                    // Insère la cellule si sa valeur est supérieure à celle de la tête actuelle
                    if (lvl <= mycell->nb_lvl - 1) {
                        mycell->next[lvl] = temp;
                        cur[lvl] = mycell;
                    }
                }
                else {
                    // Continue la recherche pour l'insertion
                    cur = temp->next;
                    if (lvl <= mycell->nb_lvl - 1) {
                        mycell->next[lvl] = cur[lvl];
                        cur[lvl] = mycell;
                    }
                }
            }
            lvl--;
        }
    }
    return mylist;
}

// Crée un tableau de taille donnée avec un nombre de niveaux spécifié
int* creerTableau(int taille, int nb_niv) {
    // Allocation de mémoire pour un tableau d'entiers initialisé à zéro
    int *tableau = (int*)malloc(taille * sizeof(int));
    if (tableau == NULL) {
        printf("Allocation de mémoire a échoué.\n");
        return tableau;
    }

    // Initialise le tableau à zéro
    for (int i = 0; i < taille; ++i) {
        tableau[i] = 0;
    }

    int val = 1;
    for (int j = 0; j < nb_niv; j++) {
        for (int k = 1; k <= taille; k++) { // Parcours des indices de 1 à taille inclus
            if (k % val == 0) {
                tableau[k - 1]++; // Incrémente la valeur de la case correspondante
            }
        }
        val *= 2; // Met à jour val pour la prochaine puissance de 2
    }

    return tableau;
}

// Crée une liste triée en fonction des valeurs d'un tableau généré par la fonction creerTableau
list* creer_liste_pour_n(int n){
    // Crée une liste vide avec un nombre de niveaux spécifié
    list* mylist = create_empty_list(n);

    int taille_liste = pow(2, n) - 1;
    int nb_niv = n;

    int *tab = creerTableau(taille_liste, n);

    // Parcourt le tableau et ajoute les valeurs à la liste triée
    for(int i = 0; i < taille_liste; i++) {
        int val = tab[i];
        tri_liste_croisant(mylist, val, i);
    }
    return mylist;
}


// Recherche la valeur donnée dans le niveau de base de la liste
void recherche_classique(list *mylist, int val) {
    // Vérifie si la liste est vide
    if (mylist->heads[0] == NULL) {
        printf("\nLa liste est vide.\n");
        return;
    }

    // Initialise un pointeur temporaire pour parcourir le niveau de base
    cell* tmp = mylist->heads[0];
    int i = 0;

    while (tmp != NULL) {
        if (tmp->value == val) {
            //printf("\nRecherche classique : Valeur trouvée (id: %d)", i);
            return;
        }
        tmp = tmp->next[0];
        i++;
    }
    //printf("\nRecherche classique : Valeur introuvable.");
    return;
}

// Recherche la valeur donnée dans les niveaux supérieurs de la liste
void recherche_niveau_haut(list* mylist, int val) {
    // Initialise le niveau de départ pour la recherche
    int lvl = mylist->max_lvl - 1;
    cell **cur = mylist->heads;

    // Vérifie si la liste est vide
    if (mylist->heads[0] == NULL) {
        printf("\nLa liste est vide.\n");
        return;
    }

    // Parcourt les niveaux supérieurs pour la recherche de la valeur spécifiée
    while (lvl >= 0) {
        cell *temp = cur[lvl];
        if (temp->value == val){
            //printf("\nRecherche multi-niveau : Valeur trouvée\n");
            return;
        }
        if (temp->value < val) {
            cur = temp->next;
        }
        lvl--;
    }
    //printf("\nRecherche multi-niveau : Valeur introuvable\n");
    return;
}
