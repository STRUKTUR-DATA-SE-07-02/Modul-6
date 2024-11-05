// main.cpp
#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    infotype kendaraan;
    address P;

    CreateList(L);

// Insert sample data
    int count = 0;  // Counter untuk tracking setiap 3 kali pengisian data
    while (true) {
        cout << "masukkan nomor polisi: ";
        cin >> kendaraan.nopol;

        if (isKendaraanExist(L, kendaraan.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> kendaraan.thnBuat;

        P = alokasi(kendaraan);
        insertLast(L, P);
        count++;  // Menambah counter setiap kali data baru dimasukkan

        // Menambahkan baris kosong setelah setiap 3 kali pengisian data
        if (count % 3 == 0) {
            cout << endl;  // Baris kosong
        }

        if (L.First != NULL && L.First->next != NULL && L.First->next->next != NULL) {
            break;
        }
    }

    // Display the list
    printInfo(L);

    // Find element by nomor polisi
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    string nopolCari;
    cin >> nopolCari;
    P = findElm(L, nopolCari);
    if (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Delete element based on user input
    cout << "\nMasukkan Nomor Polisi yang ingin dihapus: ";
    string nopolHapus;
    cin >> nopolHapus;

    P = findElm(L, nopolHapus);
    if (P != NULL) {
        address deletedNode = NULL;

        if (P == L.First) {
            deleteFirst(L, deletedNode);
        } else if (P == L.Last) {
            deleteLast(L, deletedNode);
        } else {
            deleteAfter(L, P->prev, deletedNode);
        }

        dealokasi(deletedNode);
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan, sehingga tidak dapat dihapus." << endl;
    }

    // Display the list after deletion
    printInfo(L);

    return 0;
}
