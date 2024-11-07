#include "doublelist.h"

void CreateList(list *L) {
    first(*L) = Nil;
    last(*L) = Nil;
}

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(struct elmlist));
    if (P != Nil) {
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

void InsertLast(list *L, address P) {
    if (first(*L) == Nil) {
        first(*L) = P;
        last(*L) = P;
    } else {
        next(last(*L)) = P;
        prev(P) = last(*L);
        last(*L) = P;
    }
}

void PrintInfo(list L) {
    address P = first(L);
    while (P != Nil) {
        printf("Nomor Polisi: %s\n", info(P).nopol);
        printf("Warna Kendaraan: %s\n", info(P).warna);
        printf("Tahun Kendaraan: %d\n", info(P).thnBuat);
        printf("\n");
        P = next(P);
    }
}

address findElm(list L, char *nopol) {
    address P = first(L);
    while (P != Nil) {
        if (strcmp(info(P).nopol, nopol) == 0) {
            return P;  // Mengembalikan alamat elemen jika ditemukan
        }
        P = next(P);
    }
    return Nil;  // Jika tidak ditemukan
}

void deleteFirst(list *L, address *P) {
    *P = first(*L);
    if (first(*L) != Nil) {
        if (first(*L) == last(*L)) {
            first(*L) = Nil;
            last(*L) = Nil;
        } else {
            first(*L) = next(first(*L));
            prev(first(*L)) = Nil;
        }
        next(*P) = Nil;
        prev(*P) = Nil;
    }
}

void deleteLast(list *L, address *P) {
    *P = last(*L);
    if (first(*L) != Nil) {
        if (first(*L) == last(*L)) {
            first(*L) = Nil;
            last(*L) = Nil;
        } else {
            last(*L) = prev(last(*L));
            next(last(*L)) = Nil;
        }
        prev(*P) = Nil;
        next(*P) = Nil;
    }
}

void deleteAfter(address Prec, address *P) {
    if (next(Prec) != Nil) {
        *P = next(Prec);
        next(Prec) = next(next(Prec));
        if (next(Prec) != Nil) {
            prev(next(Prec)) = Prec;
        }
        next(*P) = Nil;
        prev(*P) = Nil;
    }
}
