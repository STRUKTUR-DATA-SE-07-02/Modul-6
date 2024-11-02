#include "doublelist.h"
#include "doublelist.cpp"
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

        address found = findElm(L, data);
        if (found != nullptr) {
            cout << "Nomor polisi sudah terdaftar" << endl << endl;
            continue;  // Skip this iteration and proceed to the next input
        }

        address P = alokasi(data);
        insertLast(L, P);
        cout << endl;
    }

    printInfoReverse(L);
    cout << endl;

    infotype searchData;
    cout << "Masukkan nomor polisi yang ingin dicari: ";
    cin >> searchData.nopol;

    address foundElement = findElm(L, searchData);
    cout << endl;
    if (foundElement != nullptr) {
        cout << "Nomor Polisi  : " << foundElement->info.nopol << endl;
        cout << "Warna         : " << foundElement->info.warna << endl;
        cout << "Tahun         : " << foundElement->info.thnBuat << endl;
    } else {
        cout << "Kendaraan dengan nomor polisi " << searchData.nopol << " tidak ditemukan." << endl;
    }
    cout << endl;

    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    string nopolHapus;
    cin >> nopolHapus;

    deleteData(L, nopolHapus);

    cout << endl;

    printInfoReverse(L);

    return 0;
}
