#include <iostream>
#include "doublelist.h"

int main() {
    List L;
    createList(L);

    // Membuat beberapa elemen kendaraan
    Kendaraan k1 = {"D001", "Merah", 2015};
    Kendaraan k2 = {"D002", "Biru", 2018};
    Kendaraan k3 = {"D003", "Hitam", 2020};

    // Menambahkan elemen ke double linked list
    insertLast(L, alokasi(k1));
    insertLast(L, alokasi(k2));
    insertLast(L, alokasi(k3));

    // Mencari elemen dengan nomor polisi "D001"
    Kendaraan cari = {"D001", "", 0};
    address found = findElm(L, cari);
    if (found != nullptr) {
        std::cout << "Elemen ditemukan:" << std::endl;
        std::cout << "Nomor Polisi: " << found->info.nopol << std::endl;
        std::cout << "Warna: " << found->info.warna << std::endl;
        std::cout << "Tahun Buat: " << found->info.thnBuat << std::endl;
    } else {
        std::cout << "Elemen tidak ditemukan." << std::endl;
    }

    return 0;
}
