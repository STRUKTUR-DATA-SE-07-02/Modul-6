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
            continue; // Skip this iteration and proceed to the next input
        }

        address P = alokasi(data);
        insertLast(L, P);
        cout << endl;
    }

    printInfoReverse(L);
    return 0;
}
