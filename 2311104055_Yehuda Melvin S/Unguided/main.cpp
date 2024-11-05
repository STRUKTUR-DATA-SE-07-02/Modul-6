#include "doublelist.h"

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Data Kendaraan\n";
    cout << "2. Tampilkan Data Kendaraan\n";
    cout << "3. Hapus Data Kendaraan\n";
    cout << "4. Cari Data Kendaraan\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

void deleteMenu() {
    cout << "\nPilih Metode Penghapusan:\n";
    cout << "1. Hapus Elemen Pertama\n";
    cout << "2. Hapus Elemen Terakhir\n";
    cout << "3. Hapus Setelah Elemen Tertentu\n";
    cout << "Pilih: ";
}

int main() {
    List L;
    createList(L);
    int pilihan;

    do {
        menu();
        cin >> pilihan;

        if (pilihan == 1) { // Tambah Data Kendaraan
            Kendaraan k;
            cout << "Masukkan nomor polisi: ";
            cin >> k.nopol;
            if (isNopolExist(L, k.nopol)) {
                cout << "Nomor polisi sudah terdaftar\n";
                continue;
            }
            cout << "Masukkan warna kendaraan: ";
            cin >> k.warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> k.thnBuat;
            address P = alokasi(k);
            insertLast(L, P);
        }
        else if (pilihan == 2) { // Tampilkan Data Kendaraan
            printInfo(L);
        }
        else if (pilihan == 3) { // Hapus Data Kendaraan
            deleteMenu();
            int delChoice;
            cin >> delChoice;
            address P;

            if (delChoice == 1) {
                deleteFirst(L, P);
                if (P != nullptr) {
                    cout << "Data dengan nomor polisi " << P->info.nopol << " telah dihapus.\n";
                    dealokasi(P);
                }
            }
            else if (delChoice == 2) {
                deleteLast(L, P);
                if (P != nullptr) {
                    cout << "Data dengan nomor polisi " << P->info.nopol << " telah dihapus.\n";
                    dealokasi(P);
                }
            }
            else if (delChoice == 3) {
                cout << "Masukkan nomor polisi elemen sebelum elemen yang ingin dihapus: ";
                string nopol;
                cin >> nopol;
                address Prec = findElm(L, nopol);
                if (Prec != nullptr && Prec->next != nullptr) {
                    deleteAfter(Prec, P);
                    cout << "Data dengan nomor polisi " << P->info.nopol << " telah dihapus.\n";
                    dealokasi(P);
                } else {
                    cout << "Elemen tidak ditemukan atau tidak ada elemen setelahnya.\n";
                }
            }
        }
        else if (pilihan == 4) { // Cari Data Kendaraan
            cout << "Masukkan nomor polisi yang dicari: ";
            string nopol;
            cin >> nopol;
            address P = findElm(L, nopol);
            if (P != nullptr) {
                cout << "Data ditemukan:\n";
                cout << "No polisi : " << P->info.nopol << endl;
                cout << "Warna     : " << P->info.warna << endl;
                cout << "Tahun     : " << P->info.thnBuat << endl;
            } else {
                cout << "Data tidak ditemukan.\n";
            }
        }

    } while (pilihan != 0);

    return 0;
}
