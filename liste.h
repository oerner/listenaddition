//
// Created by oerner on 17.12.19.
//

#ifndef LISTENADDITION_LISTE_H
#define LISTENADDITION_LISTE_H

struct list {
    int val;
    struct list* next;
};
typedef struct list list_el;
typedef list_el* list_t;

#endif //LISTENADDITION_LISTE_H
