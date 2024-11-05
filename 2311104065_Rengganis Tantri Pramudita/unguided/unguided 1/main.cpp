#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    // Menambahkan beberapa data kendaraan
    insertLast(L, alokasi({"D001", "hitam", 90}));
    insertLast(L, alokasi({"D003", "putih", 70}));
    insertLast(L, alokasi({"D004", "kuning", 90}));

    // Cetak semua data
    cout << "DATA LIST 1" << endl;
    printInfo(L);

    // Mencari elemen berdasarkan nomor polisi
    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> cariNopol;

    ElmList* hasil = findElm(L, cariNopol);
    if (hasil != nullptr) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nNomor polisi " << cariNopol << " tidak ditemukan." << endl;
    }

    // Menghapus elemen dengan nomor polisi yang diminta
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    cin >> cariNopol;

    ElmList* P = findElm(L, cariNopol);
    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "\nData dengan nomor polisi " << cariNopol << " berhasil dihapus." << endl;
    } else {
        cout << "\nNomor polisi " << cariNopol << " tidak ditemukan." << endl;
    }

    // Cetak data setelah penghapusan
    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
