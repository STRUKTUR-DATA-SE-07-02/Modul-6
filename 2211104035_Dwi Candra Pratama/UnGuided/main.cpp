#include "doublelist.h"
#include "doublelist.cpp"
#include <iostream>

void inputKendaraan(infotype &kendaraan) {
    std::cout << "masukkan nomor polisi: ";
    std::cin >> kendaraan.nopol;
    std::cout << "masukkan warna kendaraan: ";
    std::cin >> kendaraan.warna;
    std::cout << "masukkan tahun kendaraan: ";
    std::cin >> kendaraan.thnBuat;
}

void tampilkanMenu() {
    std::cout << "\nMENU\n";
    std::cout << "1. Tambah Data Kendaraan\n";
    std::cout << "2. Cari Data Kendaraan\n";
    std::cout << "3. Hapus Data Kendaraan Pertama\n";
    std::cout << "4. Hapus Data Kendaraan Terakhir\n";
    std::cout << "5. Hapus Data Setelah Kendaraan Tertentu\n";
    std::cout << "6. Tampilkan Semua Data Kendaraan\n";
    std::cout << "0. Keluar\n";
    std::cout << "Pilih menu: ";
}

int main() {
    List L;
    CreateList(L);

    int pilihan;
    do {
        tampilkanMenu();
        std::cin >> pilihan;
        std::cin.ignore();  // Mengabaikan newline setelah pilihan

        switch (pilihan) {
            case 1: {
                // Tambah data kendaraan
                infotype kendaraan;
                inputKendaraan(kendaraan);

                // Cek apakah nomor polisi sudah ada
                if (findElm(L, kendaraan) != nullptr) {
                    std::cout << "nomor polisi sudah terdaftar\n";
                } else {
                    insertLast(L, alokasi(kendaraan));
                    std::cout << "Data kendaraan berhasil ditambahkan.\n";
                }
                break;
            }
            case 2: {
                // Cari data kendaraan
                infotype cari;
                std::cout << "Masukkan Nomor Polisi yang dicari : ";
                std::cin >> cari.nopol;

                ElmList* found = findElm(L, cari);
                if (found != nullptr) {
                    std::cout << "Nomor Polisi: " << found->info.nopol << std::endl;
                    std::cout << "Warna       : " << found->info.warna << std::endl;
                    std::cout << "Tahun       : " << found->info.thnBuat << std::endl;
                } else {
                    std::cout << "nomor polisi tidak ditemukan.\n";
                }
                break;
            }
            case 3: {
                // Hapus data kendaraan pertama
                ElmList* deleted;
                deleteFirst(L, deleted);
                if (deleted != nullptr) {
                    std::cout << "Data kendaraan pertama berhasil dihapus.\n";
                    dealokasi(deleted);
                } else {
                    std::cout << "List kosong, tidak ada data untuk dihapus.\n";
                }
                break;
            }
            case 4: {
                // Hapus data kendaraan terakhir
                ElmList* deleted;
                deleteLast(L, deleted);
                if (deleted != nullptr) {
                    std::cout << "Data kendaraan terakhir berhasil dihapus.\n";
                    dealokasi(deleted);
                } else {
                    std::cout << "List kosong, tidak ada data untuk dihapus.\n";
                }
                break;
            }
            case 5: {
                // Hapus data setelah kendaraan tertentu
                infotype cari;
                std::cout << "Masukkan nomor polisi kendaraan sebelum data yang ingin dihapus: ";
                std::cin >> cari.nopol;

                ElmList* prec = findElm(L, cari);
                if (prec != nullptr && prec->next != nullptr) {
                    ElmList* deleted;
                    deleteAfter(prec, deleted);
                    if (deleted != nullptr) {
                        std::cout << "Data dengan nomor polisi " << deleted->info.nopol << " berhasil dihapus.\n";
                        dealokasi(deleted);
                    }
                } else {
                    std::cout << "Tidak ada data untuk dihapus setelah nomor polisi tersebut.\n";
                }
                break;
            }
            case 6: {
                // Tampilkan semua data kendaraan
                std::cout << "DATA LIST KENDARAAN\n";
                printInfo(L);
                break;
            }
            case 0: {
                std::cout << "Keluar dari program.\n";
                break;
            }
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
