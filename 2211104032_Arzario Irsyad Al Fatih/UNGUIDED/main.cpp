#include "doublelist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype kendaraan;
    char again;

    // Input data
    do {
        cout << "Masukkan nomor polisi: ";
        cin >> kendaraan.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> kendaraan.thnBuat;

        // Cek duplikasi nomor polisi
        if (findElm(L, kendaraan) != NULL) {
            cout << "Nomor polisi sudah terdaftar" << endl << endl;
            continue;
        }

        address P = alokasi(kendaraan);
        insertLast(L, P);

        cout << "\nTambah data lagi? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "\n";
    printInfo(L);

    // Fitur pencarian
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> kendaraan.nopol;

    address found = findElm(L, kendaraan);
    if (found != NULL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    // Fitur penghapusan
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    string nopolHapus;
    cin >> nopolHapus;

    deleteData(L, nopolHapus);

    cout << "\nDATA LIST" << endl;
    printInfo(L);

    return 0;
}
