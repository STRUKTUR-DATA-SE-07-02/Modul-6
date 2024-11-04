#include "doublelist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);

    // Insert some data
    infotype x;
    x.nopol = "D001";
    x.warna = "Hitam";
    x.thnBuat = 90;
    insertLast(L, alokasi(x));

    x.nopol = "D002";
    x.warna = "Merah";
    x.thnBuat = 80;
    insertLast(L, alokasi(x));

    x.nopol = "D003";
    x.warna = "Putih";
    x.thnBuat = 70;
    insertLast(L, alokasi(x));

    cout << "DATA LIST:" << endl;
    printInfo(L);

    // Search for a vehicle
    string searchNopol;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> searchNopol;

    address found = findElm(L, searchNopol);
    if (found != nullptr) {
        cout << "Data ditemukan:" << endl;
        cout << "Nomor Polisi: " << found->info.nopol << endl;
        cout << "Warna: " << found->info.warna << endl;
        cout << "Tahun: " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    // Delete a vehicle by nopol
    string deleteNopol;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> deleteNopol;

    found = findElm(L, deleteNopol);
    if (found != nullptr) {
        if (found == L.First) {
            deleteFirst(L);
        } else if (found == L.Last) {
            deleteLast(L);
        } else {
            deleteAfter(L, found->prev);
        }
        cout << "Data dengan nomor polisi " << deleteNopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    // Print the updated list
    cout << "DATA LIST (Setelah Penghapusan):" << endl;
    printInfo(L);

    return 0;
}
