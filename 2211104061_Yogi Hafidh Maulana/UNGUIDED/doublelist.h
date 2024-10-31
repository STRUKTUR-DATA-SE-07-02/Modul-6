#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>

using namespace std;

struct Kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList
{
    Kendaraan info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

address findElm(List L, string x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

void CreateList(List &L);
address alokasi(Kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, Kendaraan P);

#endif // DOUBLELIST_H
