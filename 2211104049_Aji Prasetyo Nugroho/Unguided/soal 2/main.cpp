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

    string searchNopol;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> searchNopol;

    address found = findElm(L, searchNopol);
    if (found != nullptr) {
        cout << "\nNomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.tahun << endl;
    } else {
        cout << "\nData tidak ditemukan.\n";
    }

    return 0;
}
