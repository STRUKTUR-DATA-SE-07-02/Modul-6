#include "Doublelist.h"

// Inisialisasi list
void buatList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

// Mengalokasikan memori untuk node baru dan mengisi nilainya
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

// Menghapus memori dari node
void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Menampilkan semua elemen dalam list
void tampilkanInfo(List L) {
    address P = L.First;
    cout << "DATA LIST 1" << endl;
    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

// Menambahkan node di akhir list
void masukkanAkhir(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Mengecek apakah nomor polisi sudah ada dalam list
bool cekNopolTerdaftar(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

// Mencari elemen berdasarkan nomor polisi
address cariElm(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// Menghapus elemen pertama
void hapusAwal(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        P->next = nullptr;
    }
}

// Menghapus elemen terakhir
void hapusAkhir(List &L, address &P) {
    if (L.Last != nullptr) {
        P = L.Last;
        if (L.First == L.Last) {
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        P->prev = nullptr;
    }
}

// Menghapus elemen setelah elemen tertentu
void hapusSetelah(address prec, address &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

#include "Doublelist.h"

int main() {
    List L;
    buatList(L);

    infotype data;
    address P;
    char pilihan;

    do {
        // Minta input data kendaraan
        cout << "Masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        // Cek apakah nomor polisi sudah terdaftar setelah input selesai
        if (cekNopolTerdaftar(L, data.nopol)) {
            cout << "Nomor polisi sudah terdaftar" << endl;
        } else {
            // Jika nomor polisi belum terdaftar, alokasikan dan tambahkan ke list
            P = alokasi(data);
            masukkanAkhir(L, P);
        }

        // Tanya apakah ingin menambah data lagi
        cout << "Apakah ingin menambah data lagi? (y/n): ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');

    // Tampilkan semua data
    tampilkanInfo(L);

    // Contoh mencari elemen
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> data.nopol;
    P = cariElm(L, data.nopol);
    if (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna       : " << P->info.warna << endl;
        cout << "Tahun       : " << P->info.thnBuat << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan" << endl;
    }

    // Contoh menghapus elemen dengan nomor polisi tertentu
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    cin >> data.nopol;
    P = cariElm(L, data.nopol);
    if (P != nullptr) {
        if (P == L.First) {
            hapusAwal(L, P);
        } else if (P == L.Last) {
            hapusAkhir(L, P);
        } else {
            hapusSetelah(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << data.nopol << " berhasil dihapus." << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan" << endl;
    }

    // Tampilkan data setelah penghapusan
    tampilkanInfo(L);

    return 0;
}