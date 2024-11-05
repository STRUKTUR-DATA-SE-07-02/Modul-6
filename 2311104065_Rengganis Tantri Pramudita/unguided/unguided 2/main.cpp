
#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    // Data yang sudah tersimpan sebelumnya
    infotype kendaraan1 = {"D001", "hitam", 90};
    infotype kendaraan2 = {"D003", "putih", 70};
    infotype kendaraan3 = {"D004", "kuning", 90};

    insertFirst(L, alokasi(kendaraan1));
    insertFirst(L, alokasi(kendaraan2));
    insertFirst(L, alokasi(kendaraan3));

    // Tampilkan data list awal
    cout << "DATA LIST 1\n";
    printInfo(L);

    // Input nomor polisi yang ingin dicari
    infotype kendaraanCari;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> kendaraanCari.nopol;

    // Cari data berdasarkan nomor polisi
    address hasilCari = findElm(L, kendaraanCari);
    if (hasilCari != nullptr) {
        cout << "\n";
        cout << "Nomor Polisi : " << hasilCari->info.nopol << endl;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "\nData dengan nomor polisi " << kendaraanCari.nopol << " tidak ditemukan.\n";
    }

    return 0;
}
