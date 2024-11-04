#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk informasi kendaraan
struct infotype {
    string NomorPolisi;
    string Warna;
    int Tahun;
};

// Struktur Node
struct Node {
    infotype info;
    Node* next;
};

// Kelas List yang menyimpan head pointer
class List {
private:
    Node* first;

public:
    List() : first(nullptr) {} // Konstruktor untuk inisialisasi list kosong

    // Fungsi untuk menambahkan data ke list
    void addData(const string& nomorPolisi, const string& warna, int tahun) {
        Node* newNode = new Node;
        newNode->info.NomorPolisi = nomorPolisi;
        newNode->info.Warna = warna;
        newNode->info.Tahun = tahun;
        newNode->next = first;
        first = newNode;
    }

    // Fungsi untuk mencari data berdasarkan NomorPolisi
    Node* findElm(const string& nomorPolisiDicari) {
        Node* P = first;
        while (P != nullptr) {
            if (P->info.NomorPolisi == nomorPolisiDicari) {
                return P; // Mengembalikan alamat node jika ditemukan
            }
            P = P->next;
        }
        return nullptr; // Mengembalikan nullptr jika tidak ditemukan
    }
};

int main() {
    List L;

    // Menambahkan beberapa data ke dalam list
    L.addData("D001", "hitam", 90);
    L.addData("D002", "merah", 91);
    L.addData("D003", "biru", 92);

    // Input dari pengguna untuk mencari nomor polisi
    string nomorPolisiDicari;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> nomorPolisiDicari;

    // Mencari data di list
    Node* hasil = L.findElm(nomorPolisiDicari);
    if (hasil != nullptr) {
        cout << "Nomor Polisi: " << hasil->info.NomorPolisi << endl;
        cout << "Warna       : " << hasil->info.Warna << endl;
        cout << "Tahun       : " << hasil->info.Tahun << endl;
    } else {
        cout << "Nomor Polisi tidak ditemukan." << endl;
    }

    return 0;
}
