// doublelist.h
#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <string>
using namespace std;

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool isKendaraanExist(List L, string nopol);
address findElm(List L, string nopol);  // Task 2 function
void deleteFirst(List &L, address &P);  // Task 3 function
void deleteLast(List &L, address &P);   // Task 3 function
void deleteAfter(List &L, address Prec, address &P);  // Task 3 function

#endif
