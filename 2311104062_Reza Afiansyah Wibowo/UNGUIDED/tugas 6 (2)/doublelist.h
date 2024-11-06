#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

struct Kendaraan {
    std::string nopol;
    std::string warna;
    int thnBuat;
};
typedef Kendaraan infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List& L);
address alokasi(infotype x);
void dealokasi(address& P);
void printInfo(List L);
void insertLast(List& L, address P);
address findElm(List L, infotype x);

#endif // DOUBLELIST_H
