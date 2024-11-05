#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
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

typedef ElmList* address;

struct List {
    address First;
    address Last;
};

void CreateList(List& L);
address alokasi(infotype x);
void dealokasi(address& P);
void printInfo(const List& L);
void insertLast(List& L, address P);
address findElm(List L, std::string nopol);
void deleteFirst(List& L, address& P);
void deleteLast(List& L, address& P);
void deleteAfter(List& L, address Prec, address& P);

#endif // DOUBLELIST_H
