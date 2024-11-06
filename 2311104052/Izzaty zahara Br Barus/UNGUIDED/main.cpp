#include "doublelist.h"
#include "doublelist.cpp"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P;
    int pilihan;
    
    createList(L);
    
    do {
        cout << "\n====== MENU DOUBLE LINKED LIST ======" << endl;
        cout << "1. Tambah Data Kendaraan" << endl;
        cout << "2. Tampilkan Data Kendaraan" << endl;
        cout << "3. Cari Data Kendaraan" << endl;
        cout << "4. Hapus Data Kendaraan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: {
                Kendaraan kendaraan;
                cout << "\n--- Tambah Data Kendaraan ---" << endl;
                cout << "Nomor Polisi    : "; cin >> kendaraan.nopol;
                cout << "Warna           : "; cin >> kendaraan.warna;
                cout << "Tahun Pembuatan : "; cin >> kendaraan.thnBuat;
                
                insertLast(L, alokasi(kendaraan));
                cout << "\nData berhasil ditambahkan!" << endl;
                break;
            }
            
            case 2: {
                cout << "\n--- Data Kendaraan ---" << endl;
                printInfo(L);
                break;
            }
            
            case 3: {
                string nopol;
                cout << "\n--- Cari Data Kendaraan ---" << endl;
                cout << "Masukkan Nomor Polisi: ";
                cin >> nopol;
                
                address hasil = findElm(L, nopol);
                if(hasil != nullptr) {
                    cout << "\nKendaraan ditemukan!" << endl;
                    cout << "Nomor Polisi    : " << hasil->info.nopol << endl;
                    cout << "Warna           : " << hasil->info.warna << endl;
                    cout << "Tahun Pembuatan : " << hasil->info.thnBuat << endl;
                } else {
                    cout << "\nKendaraan tidak ditemukan!" << endl;
                }
                break;
            }
            
            case 4: {
                int subPilihan;
                cout << "\n--- Hapus Data Kendaraan ---" << endl;
                cout << "1. Hapus Data Pertama" << endl;
                cout << "2. Hapus Data Terakhir" << endl;
                cout << "Pilihan: ";
                cin >> subPilihan;
                
                if(subPilihan == 1) {
                    deleteFirst(L, P);
                    if(P != nullptr) {
                        cout << "\nData pertama berhasil dihapus!" << endl;
                        dealokasi(P);
                    }
                } else if(subPilihan == 2) {
                    deleteLast(L, P);
                    if(P != nullptr) {
                        cout << "\nData terakhir berhasil dihapus!" << endl;
                        dealokasi(P);
                    }
                }
                break;
            }
            
            case 0: {
                cout << "\nTerima kasih!" << endl;
                break;
            }
            
            default: {
                cout << "\nPilihan tidak valid!" << endl;
                break;
            }
        }
    } while(pilihan != 0);
    
    return 0;
}