#include "doublelist.h"
#include "doublelist.cpp"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);

    int numEntries;
    cout << "Masukkan jumlah kendaraan yang ingin ditambahkan: ";
    cin >> numEntries;
    cin.ignore(); // Mengabaikan karakter newline setelah input integer

    for (int i = 0; i < numEntries; i++) {
        kendaraan k;
        cout << "\nMasukkan data kendaraan ke-" << (i + 1) << ":\n";
        
        cout << "Nomor Polisi: ";
        getline(cin, k.nopol);
        
        cout << "Warna: ";
        getline(cin, k.warna);
        
        cout << "Tahun Pembuatan: ";
        cin >> k.thnBuat;
        cin.ignore(); // Mengabaikan karakter newline setelah input integer

        // Mengalokasikan elemen dan memasukkan ke dalam list
        address P = alokasi(k);
        insertLast(L, P);
    }

    // Menampilkan isi list
    cout << "\nDATA LIST 1\n";
    cout << "-------------------\n";
    printInfo(L);

    string nopolToFind;
    cout << "Masukkan nopol kendaraan yang ingin dicari: ";
    getline(cin, nopolToFind);
                
    address foundP = findElm(L, nopolToFind); // Rename to foundP
                
    if (foundP != nullptr) {
        cout << "Data kendaraan ditemukan:\n";
        cout << "Nopol: " << foundP->info.nopol 
        << "\nWarna: " << foundP->info.warna 
        << "\nTahun: " << foundP->info.thnBuat << "\n";
    } else {
        cout << "Elemen dengan nopol " << nopolToFind << " tidak ditemukan.\n";
    }

    // Mencari dan menghapus elemen dengan nopol yang diinput
    string nopolToDelete;
    cout << "Masukkan nopol kendaraan yang ingin dihapus: ";
    getline(cin, nopolToDelete);
    address deleteP = findElm(L, nopolToDelete); // Rename to deleteP

    if (deleteP != nullptr) {
        // Jika elemen yang ingin dihapus adalah elemen pertama
        if (deleteP == L.First) {
            deleteFirst(L, deleteP); // Ensure you pass the right address
        }
        // Jika elemen yang ingin dihapus adalah elemen terakhir
        else if (deleteP == L.Last) {
            deleteLast(L, deleteP); // Ensure you pass the right address
        }
        // Jika elemen yang ingin dihapus berada di tengah list
        else {
            deleteAfter(L, deleteP->prev, deleteP); // Menghapus setelah node predecessor
        }
        
        cout << "Elemen dengan nopol " << nopolToDelete << " berhasil dihapus.\n";
    } else {
        cout << "Elemen dengan nopol " << nopolToDelete << " tidak ditemukan.\n";
    }

    // Menampilkan isi list setelah penghapusan
    cout << "\nDATA LIST SETELAH PENGHAPUSAN\n";
    cout << "-------------------\n";
    printInfo(L);

    return 0;
}
