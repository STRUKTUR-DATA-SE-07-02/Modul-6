#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    // Membuat beberapa data kendaraan
    kendaraan k1 = {"D001", "Merah", 2020};
    kendaraan k2 = {"D002", "Hitam", 2019};
    kendaraan k3 = {"D003", "Putih", 2021};

    // Insert data
    insertLast(L, alokasi(k1));
    insertLast(L, alokasi(k2));
    insertLast(L, alokasi(k3));

    cout << "Data Kendaraan Awal:" << endl;
    printInfo(L);

    // Mencari kendaraan dengan nomor polisi D001
    cout << "\nMencari kendaraan dengan nopol D001:" << endl;
    address found = findElm(L, "D001");
    if(found != NULL) {
        cout << "Kendaraan ditemukan!" << endl;
        cout << "Nomor Polisi: " << found->info.nopol << endl;
        cout << "Warna: " << found->info.warna << endl;
        cout << "Tahun Pembuatan: " << found->info.thnBuat << endl;
    } else {
        cout << "Kendaraan tidak ditemukan!" << endl;
    }

    // Menghapus data pertama
    address P;
    deleteFirst(L, P);
    cout << "\nSetelah menghapus data pertama:" << endl;
    printInfo(L);

    if(P != NULL) {
        cout << "Data yang dihapus:" << endl;
        cout << "Nomor Polisi: " << P->info.nopol << endl;
        cout << "Warna: " << P->info.warna << endl;
        cout << "Tahun Pembuatan: " << P->info.thnBuat << endl;
        dealokasi(P);
    }

    return 0;
}
