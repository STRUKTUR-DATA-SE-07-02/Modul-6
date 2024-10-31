#include "doublelist.h"
#include <iostream>
using namespace std;
int main() {
    List L;
    CreateList(L);
    infotype data;
    for (int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> data.nopol;

        cout << "Masukkan warna kendaraan: ";
        cin >> data.warna;

        cout << "Masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        address P = alokasi(data);
        insertLast(L, P);
        cout << endl;
    }
    cout << "Data kendaraan yang telah dimasukkan:" << endl;
    printInfo(L);
    cout << endl;

    infotype searchData;
    cout << "Masukkan nomor polisi yang ingin dicari: ";
    cin >> searchData.nopol;

    address foundElement = findElm(L, searchData);
    if (foundElement != nullptr) {
        cout << "Kendaraan ditemukan!" << endl;
        cout << "Nomor Polisi: " << foundElement->info.nopol << endl;
        cout << "Warna: " << foundElement->info.warna << endl;
        cout << "Tahun: " << foundElement->info.thnBuat << endl;
    } else {
        cout << "Kendaraan dengan nomor polisi " << searchData.nopol << " tidak ditemukan." << endl;
    }
    cout << endl;
//
//    address deletedFirst;
//    deleteFirst(L, deletedFirst);
//    cout << "Setelah menghapus elemen pertama:" << endl;
//    printInfo(L);

//    address deletedLast;
//    deleteLast(L, deletedLast);
//    cout << "Setelah menghapus elemen terakhir:" << endl;
//    printInfo(L);

    if (L.First != nullptr) {
        address deletedAfter;
        deleteAfter(L.First, deletedAfter);
        cout << "Setelah menghapus elemen setelah elemen pertama:" << endl;
        printInfo(L);
    }
    address P = L.First;
    while (P != nullptr) {
        address next = P->next;
        dealokasi(P);
        P = next;
    }

    return 0;
}
