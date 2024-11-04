#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Kendaraan {
    string nomorPolisi;
    string warna;
    int tahun;
};

int main() {
    vector<Kendaraan> dataKendaraan;

    while (true) {
        Kendaraan kendaraanBaru;
        cout << "Masukkan nomor polisi: ";
        cin >> kendaraanBaru.nomorPolisi;

        // Cek duplikat
        bool adaDuplikat = false;
        for (const Kendaraan& kendaraan : dataKendaraan) {
            if (kendaraan.nomorPolisi == kendaraanBaru.nomorPolisi) {
                cout << "Nomor polisi sudah terdaftar." << endl;
                adaDuplikat = true;
                break;
            }
        }

        if (!adaDuplikat) {
            cout << "Masukkan warna kendaraan: ";
            cin >> kendaraanBaru.warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> kendaraanBaru.tahun;

            dataKendaraan.push_back(kendaraanBaru);
        }

        cout << endl;

        // Tampilkan opsi untuk melanjutkan atau tidak
        char pilihan;
        cout << "Ingin menambahkan data lagi? (y/n): ";
        cin >> pilihan;
        if (pilihan != 'y' && pilihan != 'Y') {
            break;
        }
    }

    // Tampilkan semua data kendaraan
    cout << "DATA LIST 1" << endl;
    for (const Kendaraan& kendaraan : dataKendaraan) {
        cout << "Nomor Polisi: " << kendaraan.nomorPolisi << endl;
        cout << "Warna       : " << kendaraan.warna << endl;
        cout << "Tahun       : " << kendaraan.tahun << endl;
    }

    return 0;
}
