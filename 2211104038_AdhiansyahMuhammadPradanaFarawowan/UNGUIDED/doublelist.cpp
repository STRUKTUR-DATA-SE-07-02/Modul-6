#include "doublelist.h"

void create_list(TwoWayList &L)
{
    L.first = nullptr;
    L.last = nullptr;
}

ElmList *alloc_elm(Kendaraan x)
{
    ElmList *new_elm = new ElmList;
    new_elm->info = x;
    new_elm->next = nullptr;
    new_elm->prev = nullptr;

    return new_elm;
}

void dealloc_elm(ElmList *&P)
{
    P->next = nullptr;
    P->prev = nullptr;
    delete P;
}

void print_info(TwoWayList &L)
{
    ElmList *current = L.first;
    while (current != nullptr)
    {
        std::cout << "Nomor polisi: " << current->info.nopol << '\n';
        std::cout << "Warna: " << current->info.warna << '\n';
        std::cout << "Tahun kendaraan: " << current->info.tahun_buat << '\n';
        current = current->next;
    }
}

void insert_last(TwoWayList &L, ElmList *&P)
{
    if (L.first == nullptr)
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

ElmList *find_elm(TwoWayList &L, Kendaraan &x)
{
    ElmList *P = L.first;
    while (P != nullptr)
    {
        if (P->info.nopol == x.nopol)
        {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void delete_first(TwoWayList &L, ElmList *&P)
{
    if (L.first != nullptr)
    {
        P = L.first;
        L.first = L.first->next;

        if (L.first != nullptr)
        {
            L.first->prev = nullptr;
        }
        else
        {
            L.last = nullptr;
        }

        P->next = nullptr;
        P->prev = nullptr;
    }
    else
    {
        std::cout << "Elemen pertama tidak ada, penghapusan dibatalkan." << '\n';
    }
}

void delete_last(TwoWayList &L, ElmList *&P)
{
    if (L.last != nullptr)
    {
        P = L.last;
        L.last = L.last->prev;
        if (L.last != nullptr)
        {
            L.last->next = nullptr;
        }
        else
        {
            L.first = nullptr;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
    else
    {
        std::cout << "Elemen terakhir tidak ada, penghapusan dibatalkan." << '\n';
    }
}

void delete_after(ElmList *&Prec, ElmList *&P)
{
    if (Prec != nullptr && Prec->next != nullptr)
    {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr)
        {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
    else
    {
        std::cout << "Elemen selanjutnya kosong, penghapusan dibatalkan." << std::endl;
    }
}
