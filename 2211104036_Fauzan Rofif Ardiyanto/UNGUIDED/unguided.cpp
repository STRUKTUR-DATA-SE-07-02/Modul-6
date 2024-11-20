// doublelist.h
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
using namespace std;

// Type infotype
struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

// Type address sebagai pointer to ElmList
typedef struct ElmList *address;

// Type ElmList
struct ElmList
{
    kendaraan info;
    address next;
    address prev;
};

// Type List
struct List
{
    address First;
    address Last;
};

// Prosedur dan Fungsi ADT
void CreateList(List &L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif

// Prosedur CreateList
void CreateList(List &L)
{
    L.First = nullptr;
    L.Last = nullptr;
}

// Fungsi alokasi
address alokasi(kendaraan x)
{
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Prosedur dealokasi
void dealokasi(address &P)
{
    delete P;
    P = nullptr;
}

// Prosedur untuk menampilkan semua elemen dalam list
void printInfo(List L)
{
    address P = L.First;
    while (P != nullptr)
    {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        cout << "--------------------------" << endl;
        P = P->next;
    }
}

// Prosedur untuk menambahkan elemen di akhir list
void insertLast(List &L, address P)
{
    if (L.First == nullptr)
    { // List kosong
        L.First = P;
        L.Last = P;
    }
    else
    {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Fungsi untuk mencari elemen berdasarkan nopol
address findElm(List L, string nopol)
{
    address P = L.First;
    while (P != nullptr)
    {
        if (P->info.nopol == nopol)
        {
            return P;
        }
        P = P->next;
    }
    return nullptr; // Tidak ditemukan
}

// Prosedur untuk menghapus elemen pertama
void deleteFirst(List &L, address &P)
{
    if (L.First != nullptr)
    {
        P = L.First;
        if (L.First == L.Last)
        { // Hanya satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        }
        else
        {
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        P->next = nullptr;
        dealokasi(P);
    }
}

// Prosedur untuk menghapus elemen terakhir
void deleteLast(List &L, address &P)
{
    if (L.Last != nullptr)
    {
        P = L.Last;
        if (L.First == L.Last)
        { // Hanya satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        }
        else
        {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        P->prev = nullptr;
        dealokasi(P);
    }
}

// Prosedur untuk menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P)
{
    if (Prec != nullptr && Prec->next != nullptr)
    {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr)
        {
            P->next->prev = Prec;
        }
        else
        {
            Prec->prev = nullptr;
        }
        P->next = nullptr;
        P->prev = nullptr;
        dealokasi(P);
    }
}

bool isNopolExist(List L, string nopol)
{
    return findElm(L, nopol) != nullptr;
}

int main()
{
    List L;
    CreateList(L);

    int choice;
    do
    {
        cout << "\nMENU:\n";
        cout << "1. Tambah data kendaraan\n";
        cout << "2. Cari data kendaraan berdasarkan nomor polisi\n";
        cout << "3. Tampilkan seluruh data kendaraan\n";
        cout << "4. Hapus data kendaraan\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 1)
        {
            kendaraan k;
            cout << "Masukkan nomor polisi: ";
            cin >> k.nopol;
            if (isNopolExist(L, k.nopol))
            {
                cout << "Nomor polisi sudah terdaftar\n";
                continue;
            }
            cout << "Masukkan warna kendaraan: ";
            cin >> k.warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> k.thnBuat;

            insertLast(L, alokasi(k));
        }
        else if (choice == 2)
        {
            string nopol;
            cout << "Masukkan nomor polisi yang dicari: ";
            cin >> nopol;
            address found = findElm(L, nopol);
            if (found)
            {
                cout << "\nData ditemukan:\n";
                cout << "No Polisi : " << found->info.nopol << endl;
                cout << "Warna     : " << found->info.warna << endl;
                cout << "Tahun     : " << found->info.thnBuat << endl;
            }
            else
            {
                cout << "Data tidak ditemukan\n";
            }
        }
        else if (choice == 3)
        {
            cout << "\nDATA LIST:\n";
            printInfo(L);
        }

    } while (choice != 5);

    return 0;
}
