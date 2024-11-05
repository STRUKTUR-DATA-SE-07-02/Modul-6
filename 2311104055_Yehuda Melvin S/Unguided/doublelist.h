#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>

using namespace std;

// Type infotype kendaraan
struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

// Type address adalah pointer ke ElmList
typedef struct ElmList* address;

// Type ElmList
struct ElmList {
    Kendaraan info;
    address next;
    address prev;
};

// Type List
struct List {
    address First;
    address Last;
};

// Prototipe fungsi dan prosedur
void createList(List &L);
address alokasi(Kendaraan x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);
bool isNopolExist(const List &L, const string &nopol);
address findElm(const List &L, const string &nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
