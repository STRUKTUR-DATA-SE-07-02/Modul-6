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
    dataKendaraan.push_back({"R45UNA", "merah", 2004});
    dataKendaraan.push_back({"B1053", "biru", 2097});
    dataKendaraan.push_back({"D003", "kuning", 1979});
    dataKendaraan.push_back({"D002", "hitam", 1969});

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
