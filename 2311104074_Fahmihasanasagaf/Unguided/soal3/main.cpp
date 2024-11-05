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

// Fungsi untuk mencari indeks elemen dengan nomor polisi tertentu
int findIndex(vector<Kendaraan> &L, string x) {
    int n = L.size();
    for (int i = 0; i < n; i++) {
        if (L[i].nomorPolisi == x) {
            return i;
        }
    }
    return -1; // Elemen tidak ditemukan
}

// Prosedur untuk menghapus elemen pertama
void deleteFirst(vector<Kendaraan> &L) {
    L.erase(L.begin());
}

// Prosedur untuk menghapus elemen terakhir
void deleteLast(vector<Kendaraan> &L) {
    L.pop_back();
}

// Prosedur untuk menghapus elemen setelah elemen tertentu
void deleteAfter(vector<Kendaraan> &L, int index) {
    L.erase(L.begin() + index + 1);
}

int main() {
    // Contoh data kendaraan
    vector<Kendaraan> kendaraan = {
        {"D004", "kuning", 99},
        {"D003", "hitam", 90},
        {"D001", "merah", 2000}
    };

    string nomorPolisiHapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> nomorPolisiHapus;

    int indeks = findIndex(kendaraan, nomorPolisiHapus);

    if (indeks != -1) {
        if (indeks == 0) {
            deleteFirst(kendaraan);
        } else if (indeks == kendaraan.size() - 1) {
            deleteLast(kendaraan);
        } else {
            deleteAfter(kendaraan, indeks);
        }
        cout << "Data dengan nomor polisi " << nomorPolisiHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Kendaraan tidak ditemukan" << endl;
    }

    // Tampilkan data list setelah penghapusan
    cout << "DATA LIST 1" << endl;
    for (const Kendaraan& kendaraan : kendaraan) {
        cout << "Nomor Polisi\t: " << kendaraan.nomorPolisi << endl;
        cout << "Warna\t\t: " << kendaraan.warna << endl;
        cout << "Tahun\t\t: " << kendaraan.tahun << endl << endl;
    }

    return 0;
}
