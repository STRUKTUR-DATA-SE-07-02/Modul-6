#include "doublelist.h"

// Membuat list kosong
void CreateList(List &L)
{
    L.First = nullptr;
    L.Last = nullptr;
}

// Mengalokasikan memori untuk elemen baru
address alokasi(Kendaraan x)
{
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// Dealokasi memori
void dealokasi(address &P)
{
    delete P;
    P = nullptr;
}

// Mencetak informasi dari list
void printInfo(List L)
{
    address current = L.First;
    while (current != nullptr)
    {
        cout << "no polisi : " << current->info.nopol << endl;
        cout << "warna : " << current->info.warna << endl;
        cout << "tahun : " << current->info.thnBuat << endl;
        current = current->next;
    }
}

// Menyisipkan elemen baru di akhir list
void insertLast(List &L, Kendaraan P)
{
    address newNode = alokasi(P);
    if (L.First == nullptr)
    {
        L.First = newNode;
        L.Last = newNode;
    }
    else
    {
        L.Last->next = newNode;
        newNode->prev = L.Last;
        L.Last = newNode;
    }
}

address findElm(List L, string x)
{
    address current = L.First;
    while (current != nullptr)
    {
        if (current->info.nopol == x)
        {
            return current; // Mengembalikan alamat node yang ditemukan
        }
        current = current->next;
    }
    return nullptr; // Mengembalikan nullptr jika tidak ditemukan
}

void deleteFirst(List &L, address &P)
{
    if (L.First == nullptr)
    {
        cout << "List kosong, tidak ada yang dapat dihapus." << endl;
        return;
    }
    P = L.First;
    if (L.First == L.Last)
    { // Jika hanya ada satu elemen
        L.First = nullptr;
        L.Last = nullptr;
    }
    else
    {
        L.First = L.First->next;
        L.First->prev = nullptr;
    }
    delete P;
}

void deleteLast(List &L, address &P)
{
    if (L.First == nullptr)
    {
        cout << "List kosong, tidak ada yang dapat dihapus." << endl;
        return;
    }
    P = L.Last;
    if (L.First == L.Last)
    { // Jika hanya ada satu elemen
        L.First = nullptr;
        L.Last = nullptr;
    }
    else
    {
        L.Last = L.Last->prev;
        L.Last->next = nullptr;
    }
    delete P;
}

void deleteAfter(List &L, address Prec, address &P)
{
    if (Prec == nullptr || Prec->next == nullptr)
    {
        cout << "Tidak ada elemen setelah elemen yang diberikan." << endl;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr)
    {
        P->next->prev = Prec;
    }
    else
    {
        // Jika P adalah elemen terakhir
        L.Last = Prec;
    }
    delete P;
}