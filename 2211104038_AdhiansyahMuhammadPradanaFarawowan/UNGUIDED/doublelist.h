#ifndef _DOUBLELIST_H
#define _DOUBLELIST_H

#include <iostream>

struct Kendaraan
{
    std::string nopol;
    std::string warna;
    int tahun_buat;
};

struct ElmList
{
    Kendaraan info;
    ElmList *next;
    ElmList *prev;
};

struct TwoWayList
{
    ElmList *first;
    ElmList *last;
};

void create_list(TwoWayList &L);
ElmList *alloc_elm(Kendaraan x);
void dealloc_elm(ElmList *&P);
void print_info(TwoWayList &L);
void insert_last(TwoWayList &L, ElmList *&P);

ElmList *find_elm(TwoWayList &L, Kendaraan &x);

void delete_first(TwoWayList &L, ElmList *&P);
void delete_last(TwoWayList &L, ElmList *&P);
void delete_after(ElmList *&Prec, ElmList *&P);

#endif
