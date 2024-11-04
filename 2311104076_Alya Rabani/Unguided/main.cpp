#include "doublelist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    
    infotype x;
    
    cout << "masukkan nomor polisi: ";
    x.nopol = "D001";
    cout << x.nopol << endl;
    cout << "masukkan warna kendaraan: ";
    x.warna = "hitam";
    cout << x.warna << endl;
    cout << "masukkan tahun kendaraan: ";
    x.thnBuat = 90;
    cout << x.thnBuat << endl;
    cout << endl;
    
    address P = alokasi(x);
    insertLast(L, P);
  
    cout << "masukkan nomor polisi: ";
    x.nopol = "D003";
    cout << x.nopol << endl;
    cout << "masukkan warna kendaraan: ";
    x.warna = "putih";
    cout << x.warna << endl;
    cout << "masukkan tahun kendaraan: ";
    x.thnBuat = 70;
    cout << x.thnBuat << endl;
    cout << endl;
    
    P = alokasi(x);
    insertLast(L, P);

    cout << "masukkan nomor polisi: ";
    x.nopol = "D004";
    cout << x.nopol << endl;
    cout << "masukkan warna kendaraan: ";
    x.warna = "kuning";
    cout << x.warna << endl;
    cout << "masukkan tahun kendaraan: ";
    x.thnBuat = 90;
    cout << x.thnBuat << endl;
    cout << endl;
    
    P = alokasi(x);
    insertLast(L, P);
    
    // 2
    searchAndPrint(L, "D001");

    // 3
    deleteElement(L, "D003");
    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);
    
    return 0;
}