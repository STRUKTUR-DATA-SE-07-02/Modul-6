#include <iostream>
#include "doublelist.h"

using namespace std;

int main() {
    list L;
    CreateList(&L);

    int jumlahKendaraan;
    cout << "Masukkan jumlah kendaraan yang ingin dimasukkan: ";
    cin >> jumlahKendaraan;

    char nopol[10];
    char warna[10];
    int thnBuat;
    infotype kendaraan;
    address P;

    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "Masukkan nomor polisi : ";
        cin >> nopol;

        // Mengecek apakah nomor polisi sudah ada
        if (findElm(L, nopol) != Nil) {
            cout << "NOMOR POLISI SUDAH TERDAFTAR !" << endl;
            i--;  // Meminta input ulang jika nomor polisi sudah terdaftar
            continue;
        }

        cout << "Masukkan warna kendaraan : ";
        cin >> warna;
        cout << "Masukkan tahun kendaraan : ";
        cin >> thnBuat;

        // Mengisi data kendaraan
        strcpy(kendaraan.nopol, nopol);
        strcpy(kendaraan.warna, warna);
        kendaraan.thnBuat = thnBuat;

        // Menambahkan data ke dalam list
        P = Alokasi(kendaraan);
        InsertLast(&L, P);
    }

    // Menampilkan data yang ada di dalam list
    cout << "\nData List 1:" << endl;
    PrintInfo(L);

    // Mencari elemen berdasarkan nomor polisi
    char cariNopol[10];
    cout << "\nMasukkan nomor polisi yang ingin dicari: ";
    cin >> cariNopol;

    address ditemukan = findElm(L, cariNopol);
    if (ditemukan != Nil) {
        cout << "Data ditemukan:\n";
        cout << "Nomor Polisi: " << info(ditemukan).nopol << endl;
        cout << "Warna: " << info(ditemukan).warna << endl;
        cout << "Tahun: " << info(ditemukan).thnBuat << endl;
    } else {
        cout << "Nomor polisi " << cariNopol << " tidak ditemukan!" << endl;
    }

    // Menghapus elemen dengan nomor polisi tertentu
    char hapusNopol[10];
    cout << "\nMasukkan nomor polisi yang ingin dihapus: ";
    cin >> hapusNopol;

    P = findElm(L, hapusNopol);
    if (P != Nil) {
        if (P == first(L)) {
            deleteFirst(&L, &P);
        } else if (P == last(L)) {
            deleteLast(&L, &P);
        } else {
            address Prec = prev(P);  // Mencari elemen sebelum P
            deleteAfter(Prec, &P);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus.\n";
    } else {
        cout << "Nomor polisi " << hapusNopol << " tidak ditemukan!\n";
    }

    // Menampilkan kembali data list setelah penghapusan
    cout << "\nData List Setelah Penghapusan:" << endl;
    PrintInfo(L);

    return 0;
}
