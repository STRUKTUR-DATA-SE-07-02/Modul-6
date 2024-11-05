#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

using namespace std;

// Type infotype
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

// Type address
typedef struct ElmList* address;

// Type ElmList
struct ElmList {
    kendaraan info;
    address next;
    address prev;
};

// Type List
struct List {
    address First;
    address Last;
};

// Prosedur dan fungsi pada ADT Double Linked List
void CreateList(List &L);
address alokasi(kendaraan x);
void dealokasi(address &P);
bool isDuplicate(const List &L, const kendaraan &x);
void printInfo(const List &L);
void insertLast(List &L, address P);
address findElm(const List &L, const string &nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, ElmList* prec, address &P);

#endif // DOUBLELIST_H
