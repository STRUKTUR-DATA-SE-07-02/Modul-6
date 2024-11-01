#include <iostream>
#include <string>

struct infotype {
    std::string nopol; // nomor polisi
    std::string warna; // warna kendaraan
    int thnBuat;       // tahun pembuatan
};

struct elmlist {
    infotype info;
    elmlist* next;
    elmlist* prev;
};

struct List {
    elmlist* first;
    elmlist* last;
};

void CreateList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

elmlist* alokasi(const infotype &x) {
    elmlist* newElm = new elmlist;
    newElm->info = x;
    newElm->next = nullptr;
    newElm->prev = nullptr;
    return newElm;
}

void dealokasi(elmlist* &P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    elmlist* current = L.first;
    while (current != nullptr) {
        std::cout << "no polisi : " << current->info.nopol
                  << "\nwarna     : " << current->info.warna
                  << "\ntahun     : " << current->info.thnBuat << "\n\n";
        current = current->next;
    }
}

void insertLast(List &L, elmlist* P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

elmlist* findElm(const List &L, const std::string &nopol) {
    elmlist* current = L.first;
    while (current != nullptr) {
        if (current->info.nopol == nopol) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void deleteFirst(List &L, elmlist* &P) {
    if (L.first != nullptr) {
        P = L.first;
        if (L.first == L.last) {
            L.first = L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        P->next = nullptr;
    }
}

void deleteLast(List &L, elmlist* &P) {
    if (L.last != nullptr) {
        P = L.last;
        if (L.first == L.last) {
            L.first = L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        P->prev = nullptr;
    }
}

void deleteAfter(elmlist* Prec, elmlist* &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

int main() {
    List kendaraanList;
    CreateList(kendaraanList);

    // Menambahkan beberapa elemen ke dalam double linked list
    infotype kendaraan1 = {"D001", "hitam", 90};
    infotype kendaraan2 = {"D003", "putih", 70};
    infotype kendaraan3 = {"D004", "kuning", 90};

    insertLast(kendaraanList, alokasi(kendaraan1));
    insertLast(kendaraanList, alokasi(kendaraan2));
    insertLast(kendaraanList, alokasi(kendaraan3));

    // Output data list awal
    std::cout << "DATA LIST 1\n";
    printInfo(kendaraanList);

    // Mencari elemen dengan nomor polisi D001
    std::string cariNopol = "D001";
    elmlist* foundElm = findElm(kendaraanList, cariNopol);
    if (foundElm != nullptr) {
        std::cout << "\nMasukkan Nomor Polisi yang dicari : " << cariNopol << "\n";
        std::cout << "Nomor Polisi : " << foundElm->info.nopol
                  << "\nWarna        : " << foundElm->info.warna
                  << "\nTahun        : " << foundElm->info.thnBuat << "\n";
    } else {
        std::cout << "\nNomor Polisi " << cariNopol << " tidak ditemukan.\n";
    }

    // Menghapus elemen dengan nomor polisi D003
    cariNopol = "D003";
    elmlist* deleteElm = findElm(kendaraanList, cariNopol);
    if (deleteElm == kendaraanList.first) {
        deleteFirst(kendaraanList, deleteElm);
    } else if (deleteElm == kendaraanList.last) {
        deleteLast(kendaraanList, deleteElm);
    } else if (deleteElm != nullptr) {
        deleteAfter(deleteElm->prev, deleteElm);
    }

    std::cout << "\nMasukkan Nomor Polisi yang akan dihapus : " << cariNopol << "\n";
    std::cout << "Data dengan nomor polisi " << cariNopol << " berhasil dihapus.\n";

    // Output data list setelah penghapusan
    std::cout << "\nDATA LIST 1\n";
    printInfo(kendaraanList);

    return 0;
}
