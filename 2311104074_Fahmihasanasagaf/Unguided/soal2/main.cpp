#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struktur untuk mewakili sebuah kendaraan
struct Kendaraan {
    string nomorPolisi;
    string warna;
    int tahun;
};

// Fungsi untuk mencari elemen dengan nomor polisi tertentu
int findElm(vector<Kendaraan> &L, string x) {
    int n = L.size();
    for (int i = 0; i < n; i++) {
        if (L[i].nomorPolisi == x) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    // Contoh data kendaraan
    vector<Kendaraan> kendaraan = {
        {"D001", "hitam", 90},
        {"B123", "merah", 2000},
        {"A456", "biru", 2010}
    };

    string nomorPolisiDicari;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> nomorPolisiDicari;

    int indeks = findElm(kendaraan, nomorPolisiDicari);

    if (indeks != -1) {
        cout << "Nomor Polisi\t: " << kendaraan[indeks].nomorPolisi << endl;
        cout << "Warna\t\t: " << kendaraan[indeks].warna << endl;
        cout << "Tahun\t\t: " << kendaraan[indeks].tahun << endl;
    } else {
        cout << "Kendaraan tidak ditemukan" << endl;
    }

    return 0;
}
