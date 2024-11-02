#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    string nopol, warna;
    int tahun;
    char lanjut, pilihan;

    do {
        infotype kendaraan;

        cout << "masukkan nomor polisi: ";
        cin >> kendaraan.nopol;

        // Cek apakah nomor polisi sudah ada
        bool nopolExists = false;
        address current = L.First;
        while (current != nullptr) {
            if (current->info.nopol == kendaraan.nopol) {
                nopolExists = true;
                break;
            }
            current = current->next;
        }

        if (nopolExists) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> kendaraan.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> kendaraan.thnBuat;

            address P = alokasi(kendaraan);
            insertLast(L, P);
        }

        printInfo(L);

        cout << "\nLanjut (y/n)? ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Cari data kendaraan" << endl;
        cout << "2. Hapus data kendaraan" << endl;
        cout << "3. Tampilkan semua data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case '1': {
                infotype searchKey;
                cout << "\nMasukkan nomor polisi yang dicari: ";
                cin >> searchKey.nopol;

                address hasil = findElm(L, searchKey);
                if (hasil != nullptr) {
                    cout << "\nData Kendaraan ditemukan:" << endl;
                    cout << "no polisi : " << hasil->info.nopol << endl;
                    cout << "warna     : " << hasil->info.warna << endl;
                    cout << "tahun     : " << hasil->info.thnBuat << endl;
                } else {
                    cout << "\nData kendaraan dengan nomor polisi " << searchKey.nopol << " tidak ditemukan." << endl;
                }
                break;
            }
            case '2': {
                string nopolHapus;
                cout << "\nData kendaraan yang tersedia:" << endl;
                printInfo(L);
                cout << "\nMasukkan nomor polisi yang akan dihapus: ";
                cin >> nopolHapus;
                deleteElm(L, nopolHapus);
                cout << "\nData setelah penghapusan:" << endl;
                printInfo(L);
                break;
            }
            case '3': {
                printInfo(L);
                break;
            }
            case '4': {
                cout << "\nProgram selesai..." << endl;
                break;
            }
            default: {
                cout << "\nPilihan tidak valid!" << endl;
                break;
            }
        }
    } while (pilihan != '4');

    // Pembersihan memory di akhir program
    address temp = L.First;
    while (temp != nullptr) {
        address next = temp->next;
        dealokasi(temp);
        temp = next;
    }

    return 0;
}
