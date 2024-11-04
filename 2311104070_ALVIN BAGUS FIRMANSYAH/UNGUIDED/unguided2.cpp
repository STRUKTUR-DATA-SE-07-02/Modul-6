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

    dataKendaraan.push_back({"D001", "hitam", 1998});
    dataKendaraan.push_back({"B1234", "merah", 2005});
    dataKendaraan.push_back({"D5678", "biru", 2010});

    string nomorPolisiCari;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> nomorPolisiCari;

    bool ditemukan = false;
    for (const Kendaraan& kendaraan : dataKendaraan) {
        if (kendaraan.nomorPolisi == nomorPolisiCari) {
            cout << "Nomor Polisi: " << kendaraan.nomorPolisi << endl;
            cout << "Warna       : " << kendaraan.warna << endl;
            cout << "Tahun       : " << kendaraan.tahun << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Kendaraan tidak ditemukan." << endl;
    }

    return 0;
}
