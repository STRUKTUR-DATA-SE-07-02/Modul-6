#include "doublelist.h"

bool checkNopol(List &L, const string &nopol) {
    ElmList* P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);
    kendaraan data;
    char choice;

    // Proses pengisian data kendaraan
    do {
        cout << "Masukkan nomor polisi: ";
        cin >> data.nopol;

        if (checkNopol(L, data.nopol)) {
            cout << "Nomor polisi sudah terdaftar\n";
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        ElmList* P = alokasi(data);
        insertLast(L, P);

        cout << "\nApakah Anda ingin menambahkan lagi? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    // Proses pencarian data kendaraan
    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> cariNopol;

    ElmList* hasil = findElm(L, cariNopol);
    if (hasil != nullptr) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna       : " << hasil->info.warna << endl;
        cout << "Tahun       : " << hasil->info.thnBuat << endl;
    } else {
        cout << "\nNomor Polisi tidak ditemukan." << endl;
    }

    return 0;
}
