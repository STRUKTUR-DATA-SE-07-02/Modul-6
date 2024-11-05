#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    int jumlah;
    cout << "Masukkan jumlah kendaraan yang akan diinput: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        infotype kendaraan;
        cout << "\nMasukkan nomor polisi: ";
        cin >> kendaraan.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> kendaraan.thnBuat;

        // Cek apakah nomor polisi sudah terdaftar
        if (findElm(L, kendaraan) == nullptr) {
            insertFirst(L, alokasi(kendaraan));  // Menggunakan insertFirst
        } else {
            cout << "Nomor polisi sudah terdaftar\n";
        }
    }

    // Tampilkan data list setelah input selesai
    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
