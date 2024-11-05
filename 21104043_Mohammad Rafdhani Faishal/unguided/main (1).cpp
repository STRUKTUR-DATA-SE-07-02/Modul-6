#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    int pilihan;
    infotype kendaraan;
    infotype searchKey;
    address P;

    do {
        cout << "\nMenu:\n";
        cout << "1. tambah data kendaraan\n";
        cout << "2. cari data kendaraan\n";
        cout << "3. hapus data kendaraan by nomor polisi\n";
        cout << "4. cetak data kendaraan\n";
        cout << "5. keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "masukkan nopol: ";
            cin >> kendaraan.nopol;
            cout << "masukkan warna kendaraan: ";
            cin >> kendaraan.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> kendaraan.thnBuat;

            if (findElm(L, kendaraan) == nullptr) {
                P = alokasi(kendaraan);
                insertLast(L, P);
            } else {
                cout << "nomor polisi sudah terdaftar\n";
            }
        } else if (pilihan == 2 ){
            cout << "\nmasukkan nopol yang ingin dicari: ";
            cin >> searchKey.nopol;

            address found = findElm (L, searchKey);
            if (found != nullptr){
                cout << "\ndata ditemukan:\n";
                cout << "no polisi : " << found->info.nopol << endl;
                cout << "warna     : " << found->info.warna << endl;
                cout << "tahun     : " << found->info.thnBuat << endl;
            }else{
                cout << "\ndata nopol" << searchKey.nopol << " tidak ditemukan.\n";
            }

        }
        else if (pilihan == 3) {
            string nopol;
            cout << "masukkan nopol untuk dihapus: ";
            cin >> nopol;
            kendaraan.nopol = nopol;
            P = findElm(L, kendaraan);
            if (P != nullptr) {
                if (P == L.first) {
                    deleteFirst(L, P);
                } else if (P == L.last) {
                    deleteLast(L, P);
                } else {
                    deleteAfter(P->prev, P);
                }
                dealokasi(P);
                cout << "success\n";
            } else {
                cout << "data not found!\n";
            }
        } else if (pilihan == 4) {
            printInfo(L);
        }
    } while (pilihan != 4);

    return 0;
}
