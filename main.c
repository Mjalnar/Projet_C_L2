#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "math.h"
#include "menu.h"
#include "agenda.h"

int main() {

    rdv * myrdv = create_rdv();
    print_rdv(myrdv);

    /*
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
    }*/
}