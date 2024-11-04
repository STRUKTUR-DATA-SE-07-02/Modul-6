#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Function and procedure prototypes
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);
address findElm(const List &L, const string &nopol);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address P);

#endif