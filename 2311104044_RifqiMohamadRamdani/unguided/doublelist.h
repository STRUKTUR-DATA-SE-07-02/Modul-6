#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

struct infotype {
    std::string nopol;
    std::string warna;
    int thnBuat;
};

struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

using address = ElmList*;

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);

#endif

