#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype kendaraan1 = {"B1234XYZ", "Hitam", 2010};
    infotype kendaraan2 = {"B5678ABC", "Putih", 2015};
    infotype kendaraan3 = {"B9101DEF", "Merah", 2020};

    // Alokasi dan insertLast
    address P1 = alokasi(kendaraan1);
    address P2 = alokasi(kendaraan2);
    address P3 = alokasi(kendaraan3);

    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    // Menampilkan info list
    cout << "Data Kendaraan dalam List:" << endl;
    printInfo(L);

    // Dealokasi semua elemen
    dealokasi(P1);
    dealokasi(P2);
    dealokasi(P3);

    return 0;
}

