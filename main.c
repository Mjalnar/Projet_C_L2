#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "math.h"
#include "menu.h"

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

/*
        list* mylist = creer_liste_pour_n(7);

        startTimer();
        for(int i = 0; i<1000000; i++){
            int random = rand() % (int)pow(2,7)-1;
           //printf("\n%d",random);
            recherche_classique(mylist,random);
        }
        stopTimer();
        displayTime();

        startTimer();
        for(int i = 0; i<1000000; i++){
            int random = rand() % (int)pow(2,7)-1;
            //printf("\n%d",random);
            recherche_niveau_haut(mylist,random);
        }
        stopTimer();
        displayTime();
*/




}