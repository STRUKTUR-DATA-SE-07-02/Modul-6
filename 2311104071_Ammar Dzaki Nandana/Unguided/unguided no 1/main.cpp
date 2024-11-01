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

    printInfo(L);

    return 0;
}
