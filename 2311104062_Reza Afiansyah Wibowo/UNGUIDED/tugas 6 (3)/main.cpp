#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    // Menambahkan beberapa elemen
    infotype x;
    x.nopol = "D004"; x.warna = "Kuning"; x.thnBuat = 90;
    address P = alokasi(x);
    insertLast(L, P);

    x.nopol = "D001"; x.warna = "Hitam"; x.thnBuat = 90;
    P = alokasi(x);
    insertLast(L, P);

    // Menghapus elemen dengan nomor polisi D003
    x.nopol = "D003";
    address Prec = findElm(L, x);
    if (Prec != nullptr) {
        address P;
        deleteAfter(L, Prec, P);
        dealokasi(P);
        cout << "Elemen dengan nomor polisi D003 berhasil dihapus." << endl;
    } else {
        cout << "Elemen dengan nomor polisi D003 tidak ditemukan." << endl;
    }

    // Menampilkan isi double linked list
    cout << "DATA LIST 1" << endl;
    P = L.first;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna       : " << P->info.warna << endl;
        cout << "Tahun       : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }

    return 0;
}
