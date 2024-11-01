#include "doublelist.h"
#include <iostream>

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;

    for (int i = 0; i < 4; i++) {
        std::cout << "masukkan nomor polisi: ";
        std::cin >> x.nopol;
        std::cout << "masukkan warna kendaraan: ";
        std::cin >> x.warna;
        std::cout << "masukkan tahun kendaraan: ";
        std::cin >> x.thnBuat;

        bool found = false;
        address temp = L.First;
        while (temp != nullptr) {
            if (temp->info.nopol == x.nopol) {
                std::cout << "nomor polisi sudah terdaftar" << std::endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            P = alokasi(x);
            insertLast(L, P);
        }
    }

    printInfo(L);

    return 0;
}

