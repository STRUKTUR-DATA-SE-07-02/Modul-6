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

    // Mencetak informasi elemen dalam double linked list
    printInfo(L);

    return 0;
}
