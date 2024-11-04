#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);
    char tambahLagi;

    do {
        infotype kendaraan;

        cout << "masukkan nomor polisi: ";
        cin >> kendaraan.nopol;

        // Cek apakah nomor polisi sudah terdaftar
        if (isNopolExists(L, kendaraan.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            continue; // Kembali ke awal loop jika nomor polisi sudah ada
        }

        cout << "masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> kendaraan.tahun;

        // Masukkan data kendaraan ke dalam list
        insertLast(L, allocate(kendaraan));

        cout << "Apakah Anda ingin menambah kendaraan lagi? (y/n): ";
        cin >> tambahLagi;

    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    // Tampilkan data kendaraan
    printInfo(L);

    return 0;
}
