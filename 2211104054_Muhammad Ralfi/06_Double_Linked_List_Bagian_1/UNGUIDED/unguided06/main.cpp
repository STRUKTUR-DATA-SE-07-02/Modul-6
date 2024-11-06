/*
#include "doublelist.h"
#include <iostream>

int main() {
    List L;
    CreateList(L);

    for (int i = 0; i < 4; i++) {
        string nopol, warna;
        int tahun;

        cout << "masukkan nomor polisi: ";
        cin >> nopol;

        if (isDuplicate(L, nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            i--;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> tahun;

        kendaraan k;
        k.nopol = nopol;
        k.warna = warna;
        k.thnBuat = tahun;

        insertLast(L, alokasi(k));
    }

    cout << "\nDATA LIST 1" << endl;
    address P = L.first;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        if (P->next != NULL) {
            cout << endl;
        }
        P = P->next;
    }

    return 0;
}
*/
#include "doublelist.h"
#include <iostream>

int main() {
    List L;
    CreateList(L);

    // Menambahkan data kendaraan
    for (int i = 0; i < 4; i++) {
        string nopol, warna;
        int tahun;

        cout << "masukkan nomor polisi: ";
        cin >> nopol;

        if (isDuplicate(L, nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            i--;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> tahun;

        kendaraan k;
        k.nopol = nopol;
        k.warna = warna;
        k.thnBuat = tahun;

        insertLast(L, alokasi(k));
    }

    // Menampilkan seluruh data list
    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Memungkinkan pencarian berdasarkan nomor polisi
    string searchNopol;
    cout << "\nMasukkan nomor polisi yang ingin dicari: ";
    cin >> searchNopol;
    address found = findElm(L, searchNopol);
    if (found != NULL) {
        cout << "Data ditemukan:\n";
        cout << "no polisi : " << found->info.nopol << endl;
        cout << "warna     : " << found->info.warna << endl;
        cout << "tahun     : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan\n";
    }

    return 0;
}
/*
#include "doublelist.h"
#include <iostream>

void hapusKendaraan(List &L) {
    string nopol;
    cout << "Masukkan nomor polisi yang ingin dihapus: ";
    cin >> nopol;

    address P = findElm(L, nopol);
    if (P == NULL) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first) {
            deleteFirst(L, P);
            cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus dari posisi pertama.\n";
        } else if (P == L.last) {
            deleteLast(L, P);
            cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus dari posisi terakhir.\n";
        } else {
            deleteAfter(P->prev, P);
            cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus dari posisi tengah.\n";
        }
    }
}

int main() {
    List L;
    CreateList(L);

    // Menambahkan data kendaraan
    for (int i = 0; i < 4; i++) {
        string nopol, warna;
        int tahun;

        cout << "masukkan nomor polisi: ";
        cin >> nopol;

        if (isDuplicate(L, nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            i--;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> tahun;

        kendaraan k;
        k.nopol = nopol;
        k.warna = warna;
        k.thnBuat = tahun;

        insertLast(L, alokasi(k));
    }

    // Menampilkan seluruh data list
    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Menghapus data kendaraan berdasarkan nomor polisi
    hapusKendaraan(L);

    // Menampilkan data list setelah penghapusan
    cout << "\nDATA LIST SETELAH PENGHAPUSAN" << endl;
    printInfo(L);

    return 0;
}
*/
