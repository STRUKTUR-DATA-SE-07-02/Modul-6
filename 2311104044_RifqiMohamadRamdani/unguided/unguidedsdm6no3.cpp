#include <iostream>
#include <string>

using namespace std;

// Struktur untuk informasi mobil
struct Mobil {
    string nomorPolisi;
    string warna;
    int tahun;
    Mobil* next;
};

// Prosedur untuk menghapus elemen pertama
void deleteFirst(Mobil*& head, Mobil*& p) {
    if (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}

// Prosedur untuk menghapus elemen terakhir
void deleteLast(Mobil*& head, Mobil*& p) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        p = head;
        head = nullptr;
        delete p;
    } else {
        Mobil* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        p = temp->next;
        temp->next = nullptr;
        delete p;
    }
}

// Prosedur untuk menghapus elemen setelah elemen tertentu
void deleteAfter(Mobil* prec, Mobil*& p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        delete p;
    }
}

// Prosedur untuk menghapus elemen berdasarkan nomor polisi
void deleteByPlate(Mobil*& head, const string& targetNomor) {
    Mobil* p = nullptr;

    if (head != nullptr && head->nomorPolisi == targetNomor) {
        deleteFirst(head, p);
    } else {
        Mobil* temp = head;
        while (temp->next != nullptr && temp->next->nomorPolisi != targetNomor) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            deleteAfter(temp, p);
        }
    }

    if (p != nullptr) {
        cout << "Data dengan nomor polisi " << targetNomor << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nomor polisi " << targetNomor << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan data list
void printList(Mobil* head) {
    Mobil* temp = head;
    cout << "DATA LIST 1" << endl;
    while (temp != nullptr) {
        cout << "Nomor Polisi  : " << temp->nomorPolisi << endl;
        cout << "Warna         : " << temp->warna << endl;
        cout << "Tahun         : " << temp->tahun << endl;
        temp = temp->next;
    }
}

int main() {
    // Membuat linked list dari beberapa mobil
    Mobil* mobil1 = new Mobil{"D001", "hitam", 90, nullptr};
    Mobil* mobil2 = new Mobil{"D002", "biru", 85, nullptr};
    Mobil* mobil3 = new Mobil{"D003", "merah", 95, nullptr};
    Mobil* mobil4 = new Mobil{"D004", "kuning", 90, nullptr};

    mobil1->next = mobil2;
    mobil2->next = mobil3;
    mobil3->next = mobil4;

    // Menampilkan list sebelum penghapusan
    printList(mobil1);

    // Input nomor polisi yang ingin dihapus
    string targetNomor;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> targetNomor;

    // Menghapus elemen dengan nomor polisi yang diberikan
    deleteByPlate(mobil1, targetNomor);

    // Menampilkan list setelah penghapusan
    printList(mobil1);

    // Membersihkan memori
    while (mobil1 != nullptr) {
        Mobil* temp = mobil1;
        mobil1 = mobil1->next;
        delete temp;
    }

    return 0;
}
