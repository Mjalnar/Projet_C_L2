/*
==============================================================================
Nom du projet         : Projet_C_L2
Auteurs               : WATINE DAVID, BOUAOU Sohaïb, BAURY Lucas
Date de création      : 21/10/2023
Dernière modification : 08/12/2023
Description           : Projet de deuxième année en école d'ingénieur,
                        qui consiste à creer un agenda de contact et de
                        rendez-vous à partir de liste à niveaux.
==============================================================================
*/


#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "math.h"
#include "menu.h"
#include "agenda.h"

int main() {

    int choix;
    printf("Choisisez votre partie : ");
    scanf(" %d", &choix);

    if (choix == 1){
        menu_partie_1();
    }
    if (choix == 2){
        menu_partie_2();
    }
    if (choix == 3){
        menu_partie_3();
    }

}