#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
        
    infotype kend;
    address P;
    string nopol, warna;
    int tahun;
    bool isRunning = true;
    while (isRunning) {
        cout << "masukkan nomor polisi: ";
        cin >> nopol;
        
        address temp = L.First;
        bool exists = false;
        while (temp != NULL) {
            if (temp->info.nopol == nopol) {
                exists = true;
                break;
            }
            temp = temp->next;
        }
        
        if (exists) {
            cout << "nomor polisi sudah terdaftar" << endl;
            continue;
        }
        
        cout << "masukkan warna kendaraan: ";
        cin >> warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> tahun;
        
        kend.nopol = nopol;
        kend.warna = warna;
        kend.thnBuat = tahun;
        
        P = alokasi(kend);
        insertLast(L, P);
        
        printInfo(L);
    }
    return 0;
}