#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>
using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList {
    Kendaraan info;
    ElmList* next;
    ElmList* prev;
};

struct List {
    ElmList* First;
    ElmList* Last;
};

// Fungsi dan prosedur untuk operasi pada Double Linked List
void createList(List &L);
ElmList* alokasi(const Kendaraan &x);
void dealokasi(ElmList* &P);
void printInfo(const List &L);
void insertLast(List &L, ElmList* P);
ElmList* findElm(const List &L, const string &nopol);
void deleteFirst(List &L, ElmList* &P);
void deleteLast(List &L, ElmList* &P);
void deleteAfter(ElmList* Prec, ElmList* &P);

#endif
