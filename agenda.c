//
// Created by david on 30/11/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "agenda.h"
#include "stdlib.h"

agenda *create_empty_agenda(int nb_lvl){                               /* voir si demander a l'utilisateur nb_lvl */
    agenda* new_agenda = (agenda *) malloc(sizeof(agenda));
    new_agenda->max_lvl = nb_lvl;
    new_agenda->heads = (contact **) malloc(sizeof(contact*) * nb_lvl);
    for(int i=0; i<nb_lvl; i++){
        new_agenda->heads[i] = NULL;
    }
    return new_agenda;
}





char *scanString(void){

    int t_p = 0;
    int i = 0;
    char* mystr = (char*)malloc(sizeof(char));
    char c ;

    while ((c = getchar()) != '\n'){
        t_p ++;
        mystr = (char*) realloc(mystr,t_p+1 * sizeof(char));
        mystr[i] = c;
        i++;
    }
    mystr[i] = '\0';
    return mystr;
}

