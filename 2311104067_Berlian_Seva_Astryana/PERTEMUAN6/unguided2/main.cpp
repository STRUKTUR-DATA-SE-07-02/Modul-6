#include "doublelist.h"
#include <iostream>
using namespace std;

bool isNopolExists(List L, const string &nopol) {
    return findElm(L, nopol) != nullptr;
}

int main() {
    List L;
    CreateList(L);

    string nopol, warna;
    int thnBuat;

    // Memasukkan beberapa data kendaraan
    for (int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> nopol;

        if (isNopolExists(L, nopol)) {
            cout << "Nomor polisi sudah terdaftar\n";
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> thnBuat;

        infotype kendaraanBaru = {nopol, warna, thnBuat};
        address P = alokasi(kendaraanBaru);
        insertLast(L, P);
    }

    // Mencetak semua data di list
    printInfo(L);

    // Mencari elemen dengan nomor polisi tertentu
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> nopol;
    address hasilPencarian = findElm(L, nopol);

    if (hasilPencarian != nullptr) {
        cout << "\nNomor Polisi : " << hasilPencarian->info.nopol << "\n";
        cout << "Warna        : " << hasilPencarian->info.warna << "\n";
        cout << "Tahun        : " << hasilPencarian->info.thnBuat << "\n";
    } else {
        cout << "Nomor polisi tidak ditemukan\n";
    }

    // Menghapus elemen berdasarkan nomor polisi
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    cin >> nopol;
    address P = findElm(L, nopol);
    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    } else {
        cout << "Nomor polisi tidak ditemukan.\n";
    }

    // Mencetak ulang semua data setelah penghapusan
    printInfo(L);

    return 0;
}
