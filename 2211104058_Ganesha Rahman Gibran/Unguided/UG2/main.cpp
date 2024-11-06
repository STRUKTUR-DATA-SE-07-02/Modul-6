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

    string targetNopol = "D001";
    address found = findElm(L, targetNopol);
    
    if (found != nullptr) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << targetNopol << " tidak ditemukan." << endl;
    }

    return 0;
}
