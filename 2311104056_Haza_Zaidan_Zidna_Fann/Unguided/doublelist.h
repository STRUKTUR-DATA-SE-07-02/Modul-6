#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>
using namespace std;

// Struktur data untuk menyimpan informasi kendaraan
struct kendaraan {
    string nopol;   // Nomor polisi
    string warna;   // Warna kendaraan
    int thnBuat;    // Tahun pembuatan kendaraan
};

typedef kendaraan infotype;
struct ElmList;    // Deklarasi forward untuk struct ElmList
typedef ElmList* address; // Define `address` sebagai pointer ke ElmList

// Struktur elemen dalam linked list
struct ElmList {
    infotype info;    // Informasi kendaraan
    address next;     // Pointer ke elemen berikutnya
    address prev;     // Pointer ke elemen sebelumnya
};

// Struktur untuk mengelola linked list
struct List {
    address First;   // Pointer ke elemen pertama
    address Last;    // Pointer ke elemen terakhir
};

// Deklarasi fungsi-fungsi untuk manipulasi linked list
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);

address findElm(const List &L, const infotype &x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif // DOUBLELIST_H
