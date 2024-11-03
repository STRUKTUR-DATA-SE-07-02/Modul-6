#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;   // Nomor Polisi
    string warna;   // Warna Kendaraan
    int thnBuat;    // Tahun Pembuatan
};

typedef kendaraan infotype;
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

// Deklarasi Fungsi
void buatList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void tampilkanInfo(List L);
void masukkanAkhir(List &L, address P);
bool cekNopolTerdaftar(List L, string nopol);
address cariElm(List L, string nopol);
void hapusAwal(List &L, address &P);
void hapusAkhir(List &L, address &P);
void hapusSetelah(address prec, address &P);

#endif