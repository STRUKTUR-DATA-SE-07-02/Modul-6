#include <iostream>
#include <string>

using namespace std;

struct Mobil {
    string nomorPolisi;
    string warna;
    int tahun;
    Mobil* next;
};

Mobil* findElm(Mobil* head, const string& targetNomor) {
    Mobil* current = head;
    while (current != nullptr) {
        if (current->nomorPolisi == targetNomor) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int main() {

    Mobil* mobil1 = new Mobil{"D001", "hitam", 90, nullptr};
    Mobil* mobil2 = new Mobil{"D002", "biru", 85, nullptr};
    Mobil* mobil3 = new Mobil{"D003", "merah", 95, nullptr};

    mobil1->next = mobil2;
    mobil2->next = mobil3;

    string targetNomor;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> targetNomor;

    Mobil* mobilDitemukan = findElm(mobil1, targetNomor);
    if (mobilDitemukan != nullptr) {
        cout << "Nomor Polisi  : " << mobilDitemukan->nomorPolisi << endl;
        cout << "Warna         : " << mobilDitemukan->warna << endl;
        cout << "Tahun         : " << mobilDitemukan->tahun << endl;
    } else {
        cout << "Nomor Polisi tidak ditemukan." << endl;
    }

    delete mobil1;
    delete mobil2;
    delete mobil3;

    return 0;
}
