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

    // Contoh data kendaraan
    dataKendaraan.push_back({"D001", "hitam", 1998});
    dataKendaraan.push_back({"B1234", "merah", 2005});
    dataKendaraan.push_back({"D5678", "biru", 2010});
    dataKendaraan.push_back({"D003", "kuning", 1990});
    dataKendaraan.push_back({"D004", "hitam", 1990});

    string nomorPolisiHapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> nomorPolisiHapus;

    bool ditemukan = false;
    for (auto it = dataKendaraan.begin(); it != dataKendaraan.end(); ++it) {
        if (it->nomorPolisi == nomorPolisiHapus) {
            dataKendaraan.erase(it);
            ditemukan = true;
            break;
        }
    }

    if (ditemukan) {
        cout << "Data dengan nomor polisi " << nomorPolisiHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Kendaraan tidak ditemukan." << endl;
    }

    // Menampilkan data yang tersisa
    cout << "DATA LIST 1" << endl;
    for (const Kendaraan& kendaraan : dataKendaraan) {
        cout << "Nomor Polisi: " << kendaraan.nomorPolisi << endl;
        cout << "Warna       : " << kendaraan.warna << endl;
        cout << "Tahun       : " << kendaraan.tahun << endl;
    }

    return 0;
}
