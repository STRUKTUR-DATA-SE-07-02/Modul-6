#ifndef doublelist_H
#define doublelist_H

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

void CreateList(list *L);
address Alokasi(infotype X);
void Dealokasi(address P);
void InsertLast(list *L, address P);
void PrintInfo(list L);
address findElm(list L, char *nopol);
void deleteFirst(list *L, address *P);
void deleteLast(list *L, address *P);
void deleteAfter(address Prec, address *P);

#endif
