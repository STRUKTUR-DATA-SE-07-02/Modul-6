#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    infotype kendaraan1 = {"D001", "hitam", 90};
    infotype kendaraan2 = {"D003", "putih", 70};
    infotype kendaraan3 = {"D004", "kuning", 90};

    insertFirst(L, alokasi(kendaraan1));
    insertFirst(L, alokasi(kendaraan2));
    insertFirst(L, alokasi(kendaraan3));

    cout << "DATA LIST 1\n";
    printInfo(L);

    infotype kendaraanHapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> kendaraanHapus.nopol;

    address P = findElm(L, kendaraanHapus);
    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        cout << "Data dengan nomor polisi " << kendaraanHapus.nopol << " berhasil dihapus.\n";
    } else {
        cout << "Data dengan nomor polisi " << kendaraanHapus.nopol << " tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
