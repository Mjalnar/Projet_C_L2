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

/*
agenda* tri_new_contact(agenda* myagenda){
    contact *mycontact = create_contact();
    int lvl = myagenda->max_lvl - 1;
    contact **cur = myagenda->heads;
    int c = 0;

    if (myagenda->heads[0] == NULL || mycontact->nom_prenom[0] < myagenda->heads[0]->nom_prenom[0]) {
        return add_val_to_head_agenda(myagenda, mycontact);
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
*/
/*
// Fonction de tri des contacts dans l'agenda basée sur les premières lettres des noms
agenda* tri_new_contact(agenda* myagenda) {
    contact *mycontact = create_contact(); // Crée un nouveau contact

    // Parcourt les niveaux (du plus élevé au plus bas)
    for (int lvl = myagenda->max_lvl - 1; lvl >= 0; lvl--) {
        contact **cur = myagenda->heads;

        // Si l'agenda est vide ou le nom du nouveau contact est avant la première lettre du premier contact
        if (myagenda->heads[0] == NULL || mycontact->nom_prenom[lvl] < myagenda->heads[0]->nom_prenom[lvl]) {
            return add_val_to_head_agenda(myagenda, mycontact); // Ajoute le nouveau contact à la tête de l'agenda
        } else {
            while (cur[lvl] != NULL) {
                if (mycontact->nom_prenom[lvl] == cur[lvl]->nom_prenom[lvl]) {
                    lvl--; // Si les lettres sont identiques, passe au niveau inférieur
                } else {
                    mycontact->next[lvl] = cur[lvl];
                    cur[lvl] = mycontact;
                    break; // Chaîne les contacts si les lettres sont différentes et sort de la boucle
                }
            }
        }
    }
    return myagenda;
}*/


agenda* tri_new_contact(agenda* myagenda, contact *new_contact) {
    int lvl;

    for (lvl = myagenda->max_lvl - 1; lvl >= 0; lvl--) {
        contact **cur = myagenda->heads;

        if (myagenda->heads[0] == NULL || new_contact->nom_prenom[lvl] < myagenda->heads[0]->nom_prenom[lvl]) {
            return add_val_to_head_agenda(myagenda, new_contact);
        } else {
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
//===============================================================================================================================
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

