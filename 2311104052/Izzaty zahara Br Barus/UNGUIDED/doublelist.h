#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;

typedef ElmList* address;

struct ElmList {
    Kendaraan info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void createList(List& L);
address alokasi(const Kendaraan& x);
void dealokasi(address& P);
void printInfo(const List& L);
void insertLast(List& L, address P);
address findElm(const List& L, const string& nopol);
void deleteFirst(List& L, address& P);
void deleteLast(List& L, address& P);

#endif 