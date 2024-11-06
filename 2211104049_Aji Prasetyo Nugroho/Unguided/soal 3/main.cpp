#include "doublelist.h"

int main() {
    List L;
    createList(L);

    infotype data;
    address p;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.tahun;

        p = alokasi(data);
        insertLast(L, p);

        cout << "apakah ingin menambah data lagi? (y/n): ";
        cin >> choice;
    }

    cout << endl << "DATA LIST" << endl;
    printInfo(L);

    string deleteNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    cin >> deleteNopol;

    address toDelete = findElm(L, deleteNopol);
    if (toDelete != nullptr) {
        if (toDelete == L.first) {
            deleteFirst(L, toDelete); 
        } else if (toDelete == L.last) {
            deleteLast(L, toDelete);  
        } else {
            deleteAfter(toDelete->prev, toDelete); 
        }
        cout << "\nData dengan nomor polisi " << deleteNopol << " berhasil dihapus.\n";
    } else {
        cout << "\nData tidak ditemukan.\n";
    }

    cout << endl << "DATA LIST" << endl;
    printInfo(L);

    return 0;
}
