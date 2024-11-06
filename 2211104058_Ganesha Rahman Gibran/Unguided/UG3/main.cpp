#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    infotype data1 = {"D001", "hitam", 90};
    infotype data2 = {"D003", "putih", 70};
    infotype data3 = {"D004", "kuning", 90};

    insertLast(L, alokasi(data1));
    insertLast(L, alokasi(data2));
    insertLast(L, alokasi(data3));

    cout << "List before deletion:" << endl;
    printInfo(L);

    string targetNopol = "D003";
    address P = findElm(L, targetNopol);

    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << targetNopol << " berhasil dihapus." << endl;
    } else {
        cout << "Nomor polisi " << targetNopol << " tidak ditemukan." << endl;
    }
    cout << "List after deletion:" << endl;
    printInfo(L);

    return 0;
}
