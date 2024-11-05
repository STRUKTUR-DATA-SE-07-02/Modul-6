#include "doublelist.h"

int main() {
    list L;
    infotype kendaraan;
    address P;

    createList(&L);

    // Input kendaraan 1
    strcpy(kendaraan.nopol, "D001");
    strcpy(kendaraan.warna, "Hitam");
    kendaraan.thnBuat = 2015;
    P = alokasi(kendaraan);
    insertLast(&L, P);

    // Input kendaraan 2
    strcpy(kendaraan.nopol, "D002");
    strcpy(kendaraan.warna, "Merah");
    kendaraan.thnBuat = 2018;
    P = alokasi(kendaraan);
    insertLast(&L, P);

    // Input kendaraan 3
    strcpy(kendaraan.nopol, "D003");
    strcpy(kendaraan.warna, "Putih");
    kendaraan.thnBuat = 2020;
    P = alokasi(kendaraan);
    insertLast(&L, P);

    // Cetak semua data
    printf("Data Kendaraan:\n");
    printInfo(L);

    // Cari kendaraan dengan NoPol D001
    P = findElm(L, "D001");
    if (P != Nil) {
        printf("Kendaraan dengan NoPol D001 ditemukan: Warna %s, Tahun %d\n", info(P).warna, info(P).thnBuat);
    } else {
        printf("Kendaraan dengan NoPol D001 tidak ditemukan\n");
    }

    // Hapus kendaraan dengan NoPol D003
    deleteLast(&L, &P);
    printf("Kendaraan dengan NoPol D003 telah dihapus\n");

    // Cetak ulang data
    printf("Data Kendaraan setelah penghapusan:\n");
    printInfo(L);

    return 0;
}
