#include <iostream>
#include <string>
using namespace std;

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST 1" << endl;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

bool isKendaraanExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    infotype kendaraan;
    address P;

    CreateList(L);

    while (true) {
        cout << "masukkan nomor polisi: ";
        cin >> kendaraan.nopol;

        if (isKendaraanExist(L, kendaraan.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> kendaraan.thnBuat;

        P = alokasi(kendaraan);
        insertLast(L, P);

        if (L.First != NULL && L.First->next != NULL && L.First->next->next != NULL) {
            break;
        }
    }

    printInfo(L);
    return 0;
}
