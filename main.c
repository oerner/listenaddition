#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

list_el * n_liste(int wert){
    if(wert == 0){
        return NULL;
    }
    else{
        list_el * n_element = malloc(sizeof(list_el));
        n_element->val = wert % 10;
        n_element->next = n_liste(wert / 10);
        return n_element;
    }
}

int wert_liste(list_t liste1){
    int potenz = 1;
    int wert = 0;
    while(liste1->next != NULL){
        wert += liste1->val * potenz;
        liste1 = liste1->next;
        potenz = potenz * 10;
    }
    wert += liste1->val * potenz;
    return wert;
}

list_t add_lists(list_t liste1, list_t liste2){
    list_t ergebnis;
    int wert = wert_liste(liste1) + wert_liste(liste2);
    ergebnis = n_liste(wert);
    return ergebnis;
}

void free_memory(list_el *liste){
    list_el *temp;
    while(liste->next != NULL){
        temp = liste;
        liste = liste->next;
        free(temp);
    }
}

void runtest(){
    list_t listen[10];
    for(int i = 0; i < 10; i++){
        int laenge = (rand()%6)+1;
        int potenz = 1;
        int wert = 0;
        for (int j = 0; j < laenge; j++) {
            wert += (rand() % 10)*potenz;
            potenz = potenz * 10;
        }
        listen[i] = n_liste(wert);
    }
    for (int k = 0; k < 10; k++) {
        printf("Liste %d Wert %d\n", k, wert_liste(listen[k]));
    }
    for (int l = 0; l < 5; l++) {
        int l1 = rand()%10;
        int l2 = rand()%10;
        list_t ergebnis = add_lists(listen[l1], listen[l2]);
        printf("Liste %d + Liste %d:\n", l1, l2);
        printf("%d + %d = %d\n", wert_liste(listen[l1]), wert_liste(listen[l2]), wert_liste(ergebnis));
    }
    for (int m = 0; m < 10; m++) {
        free_memory(listen[m]);
    }
    printf("Speicher freigegeben");
}

int main() {
    runtest();
    return 0;
}