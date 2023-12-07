//
// Created by david on 23/10/2023.
//

#ifndef PROJET_LIST_H
#define PROJET_LIST_H
#include "cell.h"


// Définition de la structure list
typedef struct list {
    int max_lvl;         // Nombre maximal de niveaux dans la liste
    struct cell** heads; // Tableau de pointeurs vers la tête de chaque niveau
} list;


// Déclaration des prototypes des fonctions pour manipuler la liste

// Crée une liste vide avec un nombre de niveaux donné
list* create_empty_list(int nb_lvl);

// Ajoute une valeur en tête de la liste
list* add_val_to_head(list* mylist, cell*); // Attention à définir cell correctement dans cell.h

// Affiche tous les éléments de la liste
void print_all_list(list* mylist);

// Affiche les éléments d'un niveau donné de la liste
void print_lvl_list(list* mylist, int nb_lvl);

// Trie la liste en ordre croissant par rapport à une valeur donnée
list* tri_liste_croisant(list* mylist, int nb_lvl, int val);

// Crée une liste spécifique pour un entier n donné
list* creer_liste_pour_n(int n);

// Effectue une recherche classique dans la liste pour une valeur donnée
void recherche_classique(list* mylist, int val);

// Effectue une recherche dans les niveaux supérieurs de la liste pour une valeur donnée
void recherche_niveau_haut(list* mylist, int val);

#endif //PROJET_LIST_H
