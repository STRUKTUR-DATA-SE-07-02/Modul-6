#include "doublelist.cpp"
#include "doublelist.h"
#include <iostream>

using namespace std;

int main() {
    VehicleList L;
    string nopol, warna;
    int tahun;
    int numVehicles;
    int choice;

    do {
        cout << "\n=== Menu List Kendaraan ===" << endl;
        cout << "1. Tambah kendaraan" << endl;
        cout << "2. Cari kendaraan" << endl;
        cout << "3. Tampilkan semua kendaraan" << endl;
        cout << "4. Hapus kendaraan" << endl;  // Opsi hapus kendaraan
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Berapa kendaraan yang ingin Anda masukkan? ";
                cin >> numVehicles;

                for (int i = 1; i <= numVehicles; ++i) {
                    bool validNopol = false;

                    while (!validNopol) {
                        cout << "Masukkan nomor polisi (kendaraan " << i << "): ";
                        cin >> nopol;

                        if (L.isRegistered(nopol)) {
                            Vehicle* registeredVehicle = L.searchVehicle(nopol);
                            cout << "Nomor polisi sudah terdaftar dengan detail berikut:" << endl;
                            cout << "Nomor polisi : " << registeredVehicle->nopol << endl;
                            cout << "Warna        : " << registeredVehicle->warna << endl;
                            cout << "Tahun        : " << registeredVehicle->tahun << endl;
                            cout << "Silakan masukkan nomor polisi yang berbeda." << endl;
                        } else {
                            validNopol = true;
                        }
                    }

                    cout << "Masukkan warna kendaraan: ";
                    cin >> warna;
                    cout << "Masukkan tahun kendaraan: ";
                    cin >> tahun;
                    cout << "" << endl;

                    Vehicle* P = new Vehicle(nopol, warna, tahun);  
                    L.insertLast(P);
                }
                break;
            }
            case 2: {
                cout << "Masukkan nomor polisi kendaraan yang ingin dicari: ";
                cin >> nopol;
                Vehicle* foundVehicle = L.searchVehicle(nopol);
                if (foundVehicle) {
                    cout << "Detail kendaraan ditemukan:" << endl;
                    cout << "Nomor polisi : " << foundVehicle->nopol << endl;
                    cout << "Warna        : " << foundVehicle->warna << endl;
                    cout << "Tahun        : " << foundVehicle->tahun << endl;
                } else {
                    cout << "Kendaraan dengan nomor polisi tersebut tidak ditemukan." << endl;
                }
                break;
            }
            case 3: {
                cout << "\nDaftar kendaraan yang berhasil dimasukkan:\n";
                L.printList();
                break;
            }
            case 4: {
                cout << "Masukkan nomor polisi kendaraan yang ingin dihapus: ";
                cin >> nopol;
                bool success = L.deleteVehicle(nopol);
                if (success) {
                    cout << "Kendaraan dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
                } else {
                    cout << "Kendaraan dengan nomor polisi tersebut tidak ditemukan." << endl;
                }
                break;
            }
            case 5: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}