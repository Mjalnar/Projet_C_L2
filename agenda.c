//
// Created by david on 30/11/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "agenda.h"
#include "stdlib.h"

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
agenda* add_val_to_head(agenda *mylist, contact * mycontact){
    // Parcourt les niveaux du contact pour l'ajouter à la tête de l'agenda
    for(int i = 0; i <= mycontact->nb_lvl - 1; ++i) {
        mycontact->next[i] = mylist->heads[i];
        mylist->heads[i] = mycontact;
    }
    return mylist;
}


agenda* tri_new_contact(agenda* myagenda){
    contact *mycontact = create_contact();
    int lvl = myagenda->max_lvl - 1;
    contact **cur = myagenda->heads;
    int c = 0;

    if (myagenda->heads[0] == NULL || mycontact->nom_prenom[0] < myagenda->heads[0]->nom_prenom[0]) {
        return add_val_to_head(myagenda, mycontact);
    }
    else {
        while (lvl >= 0) {
            contact *temp = cur[lvl];

            if(mycontact->nom_prenom[c] == temp->nom_prenom[c]){
                lvl--;
                c++;
            }

            if (temp == NULL) {
                if (mycontact->nb_lvl - 1 >= lvl) {
                    mycontact->next[lvl] = temp;
                    cur[lvl] = mycontact;
                }
            }
            else {
                if (temp->nom_prenom[0] > mycontact->nom_prenom[0]) {

                    mycell->next[lvl] = temp;
                    cur[lvl] = mycell;

                }
                else{
                    if(temp->nom_prenom[0] < mycontact->nom_prenom[0]) {
                        cur = temp->next;

                        mycell->next[lvl] = cur[lvl];
                        cur[lvl] = mycell;
                    }
                }

            }
        }
        lvl--;
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


