#include "doublelist.h"
#include <iostream>
using namespace std;

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
    P = NULL;
}

void printInfo(List L) {
    cout << "DATA LIST 1" << endl;
    address P = L.First;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        if (P->next != NULL) {
            cout << endl;
        }
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

//2 fungsi mencari elemen
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// 2 fungsi mencari elemen
void searchAndPrint(List L, string searchNopol) {
    cout << "Masukkan Nomor Polisi yang dicari : " << searchNopol << endl;
    
    infotype searchData;
    searchData.nopol = searchNopol;
    
    address found = findElm(L, searchData);
    
    if (found != NULL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

// 3 prosedur menghapus elemen
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First->next == NULL) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.First = L.First->next;
        L.First->prev = NULL;
        P->next = NULL;
    }
}

//3
void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First->next == NULL) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.Last = L.Last->prev;
        L.Last->next = NULL;
        P->prev = NULL;
    }
}

//3
void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != NULL) {
        P->next->prev = Prec;
    }
    P->next = NULL;
    P->prev = NULL;
}

//3
void deleteElement(List &L, string nopol) {
    cout << "Masukkan Nomor Polisi yang akan dihapus : " << nopol << endl;
    
    address P;
    infotype x;
    x.nopol = nopol;
    address found = findElm(L, x);
    
    if (found != NULL) {
        if (found == L.First) {
            deleteFirst(L, P);
        } else if (found == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(found->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}