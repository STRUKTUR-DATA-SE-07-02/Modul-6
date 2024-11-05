#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    infotype kendaraan1 = {"D001", "hitam", 90};
    infotype kendaraan2 = {"D003", "putih", 70};
    infotype kendaraan3 = {"D004", "kuning", 90};

    insertLast(L, alokasi(kendaraan1));
    insertLast(L, alokasi(kendaraan2));
    insertLast(L, alokasi(kendaraan3));

    std::cout << "DATA LIST 1" << std::endl;
    printInfo(L);

    std::string cariNopol = "D001";
    address found = findElm(L, cariNopol);
    if (found) {
        std::cout << "Nomor Polisi yang dicari: " << cariNopol << std::endl;
        std::cout << "Warna: " << found->info.warna << std::endl;
        std::cout << "Tahun: " << found->info.thnBuat << std::endl;
    } else {
        std::cout << "Nomor Polisi tidak ditemukan." << std::endl;
    }

    address P;
    deleteFirst(L, P);
    if (P) {
        std::cout << "Data dengan nomor polisi " << P->info.nopol << " berhasil dihapus." << std::endl;
        dealokasi(P);
    }

    std::cout << "DATA LIST setelah penghapusan" << std::endl;
    printInfo(L);

    return 0;
}
