//
// Created by david on 30/11/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "agenda.h"
#include "stdlib.h"
#include "string.h"

// Crée un agenda vide avec un nombre spécifié de niveaux
agenda *create_empty_agenda(int nb_lvl){

    agenda* new_agenda = (agenda *) malloc(sizeof(agenda));

    if (new_agenda == NULL) {
        printf("Allocation de mémoire pour l'agenda a échoué.\n");
        return NULL;
    }

    new_agenda->max_lvl = nb_lvl;
    new_agenda->heads = (contact **) malloc(sizeof(contact*) * nb_lvl);

    if (new_agenda->heads == NULL) {
        printf("Allocation de mémoire pour les têtes de liste a échoué.\n");
        free(new_agenda); // Libère la mémoire si l'allocation échoue
        return NULL;
    }

    // Initialise les têtes de liste à NULL
    for(int i = 0; i < nb_lvl; i++){
        new_agenda->heads[i] = NULL;
    }

    return new_agenda;
}

// Ajoute un contact à la tête de l'agenda selon ses niveaux
agenda* add_val_to_head_agenda(agenda *mylist, contact * mycontact){
    // Parcourt les niveaux du contact pour l'ajouter à la tête de l'agenda
    for(int i = 0; i <= mycontact->nb_lvl - 1; ++i) {
        mycontact->next[i] = mylist->heads[i];
        mylist->heads[i] = mycontact;
    }
    return mylist;
}


agenda* tri_new_contact(agenda* myagenda, contact *new_contact) {
    int lvl;

    for (lvl = myagenda->max_lvl - 1; lvl >= 0; lvl--) {
        contact **cur = myagenda->heads;

        if (myagenda->heads[0] == NULL || new_contact->nom_prenom[lvl] < myagenda->heads[0]->nom_prenom[lvl]) {
            return add_val_to_head_agenda(myagenda, new_contact);
        }
        else {
            while (cur[lvl] != NULL) {
                if (new_contact->nom_prenom[lvl] == cur[lvl]->nom_prenom[lvl]) {
                    lvl--;
                } else {
                    new_contact->next[lvl] = cur[lvl];
                    cur[lvl] = new_contact;
                    return myagenda; // Ajout du contact et retour
                }
            }
        }
    }
    return myagenda;
}


// Fonction pour lire une chaîne de caractères depuis l'entrée standard
char *scanString(void){
    int t_p = 0;
    int i = 0;
    char* mystr = (char*)malloc(sizeof(char));
    char c ;

    while ((c = getchar()) != '\n'){
        t_p ++;
        // Réalloue de la mémoire pour la chaîne à chaque nouveau caractère
        mystr = (char*) realloc(mystr, (t_p+1) * sizeof(char));
        mystr[i] = c;
        i++;
    }
    mystr[i] = '\0'; // Ajoute le caractère de fin de chaîne
    return mystr;
}

//version 1
/*
// Fonction de recherche d'un contact dans l'agenda en utilisant le nom/prénom
contact* search_contact(agenda myagenda, char* smone){
    contact* cur = myagenda.heads[0];

    // Parcourt les contacts dans le niveau de base de l'agenda
    while (cur != NULL){
        // Vérifie si le nom/prénom du contact correspond à la recherche
        if(cur->nom_prenom == smone)
            return cur; // Renvoie le contact si trouvé
        cur = cur->next[0];
    }
    printf("Contact introuvable"); // Message si le contact n'est pas trouvé
    return NULL;
}
*/

//version 2
// Fonction de recherche d'un contact dans l'agenda en utilisant le nom/prénom
contact* search_contact(agenda myagenda, char* smone){
    contact* cur = myagenda.heads[0];

    // Parcourt les contacts dans le niveau de base de l'agenda
    while (cur != NULL){
        // Vérifie si le nom/prénom du contact correspond à la recherche
        if(strcmp(cur->nom_prenom, smone) == 0)
            return cur; // Renvoie le contact si trouvé
        cur = cur->next[0];
    }
    printf("Contact introuvable"); // Message si le contact n'est pas trouvé
    return NULL;
}

void print_lvl_agenda(agenda* myagenda, int nb_lvl){
    // Initialisation des pointeurs temporaires
    contact * tmp = myagenda->heads[nb_lvl];
    contact * tmp2 = myagenda->heads[0];

    printf("[list head_%d @-]--", nb_lvl + 1);

    while(tmp != NULL){
        // Vérification si la valeur de tmp est la même que la valeur de tmp2
        if (tmp->nom_prenom == tmp2->nom_prenom){
            printf(">[ %s|@- ]--", tmp->nom_prenom);
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
void print_all_agenda(agenda* myagenda){
    // Parcourt et affiche chaque niveau de la liste
    for (int i = 0; i < myagenda->max_lvl; i++){
        print_lvl_agenda(myagenda, i); // Utilise la fonction existante pour afficher un niveau spécifique
    }
    return;
}

void free_agenda(agenda* my_agenda) {
    // Libère la mémoire des niveaux de contacts dans l'agenda
    for (int i = 0; i < my_agenda->max_lvl; ++i) {
        contact* cur_contact = my_agenda->heads[i];
        while (cur_contact != NULL) {
            contact* temp = cur_contact->next[i];
            free_contact(cur_contact);
            cur_contact = temp;
        }
    }

    // Libère la mémoire de l'agenda lui-même
    free(my_agenda);
}