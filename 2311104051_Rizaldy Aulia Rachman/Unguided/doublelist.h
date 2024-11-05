#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

typedef struct {
    char nopol[10];
    char warna[10];
    int thnBuat;
} infotype;

typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct list {
    address first;
    address last;
};

void createList(list *L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(list L);
void insertLast(list *L, address P);
address findElm(list L, char nopol[]);
void deleteFirst(list *L, address *P);
void deleteLast(list *L, address *P);
void deleteAfter(address Prec, address *P);

#endif
