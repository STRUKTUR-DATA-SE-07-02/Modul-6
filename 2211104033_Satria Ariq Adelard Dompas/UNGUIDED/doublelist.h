#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

struct infotype {
    std::string nopol;  // Nomor Polisi
    std::string warna;  // Warna Kendaraan
    int thnBuat;        // Tahun Pembuatan
};

struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

struct List {
    ElmList* First;
    ElmList* Last;
};

// Deklarasi fungsi
void CreateList(List &L);
ElmList* alokasi(infotype x);
void dealokasi(ElmList* &P);
void printInfo(const List &L);
void insertLast(List &L, ElmList* P);
ElmList* findElm(const List &L, infotype x);
void deleteFirst(List &L, ElmList* &P);
void deleteLast(List &L, ElmList* &P);
void deleteAfter(ElmList* Prec, ElmList* &P);

#endif