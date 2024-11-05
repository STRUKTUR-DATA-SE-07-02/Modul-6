#include "doublelist.h"

void createList(list *L) {
    first(*L) = Nil;
    last(*L) = Nil;
}

address alokasi(infotype x) {
    address P = (address)malloc(sizeof(struct elmlist));
    if (P != Nil) {
        strcpy(info(P).nopol, x.nopol);
        strcpy(info(P).warna, x.warna);
        info(P).thnBuat = x.thnBuat;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}

void dealokasi(address P) {
    free(P);
}

void printInfo(list L) {
    address P = first(L);
    while (P != Nil) {
        printf("NoPol: %s, Warna: %s, Tahun: %d\n", info(P).nopol, info(P).warna, info(P).thnBuat);
        P = next(P);
    }
}

void insertLast(list *L, address P) {
    if (first(*L) == Nil) {
        first(*L) = P;
        last(*L) = P;
    } else {
        prev(P) = last(*L);
        next(last(*L)) = P;
        last(*L) = P;
    }
}

address findElm(list L, char nopol[]) {
    address P = first(L);
    while (P != Nil) {
        if (strcmp(info(P).nopol, nopol) == 0) {
            return P;
        }
        P = next(P);
    }
    return Nil;
}

void deleteFirst(list *L, address *P) {
    *P = first(*L);
    if (first(*L) != Nil) {
        if (next(first(*L)) == Nil) {
            first(*L) = Nil;
            last(*L) = Nil;
        } else {
            first(*L) = next(*P);
            prev(first(*L)) = Nil;
        }
        next(*P) = Nil;
        prev(*P) = Nil;
    }
}

void deleteLast(list *L, address *P) {
    *P = last(*L);
    if (last(*L) != Nil) {
        if (prev(last(*L)) == Nil) {
            first(*L) = Nil;
            last(*L) = Nil;
        } else {
            last(*L) = prev(*P);
            next(last(*L)) = Nil;
        }
        next(*P) = Nil;
        prev(*P) = Nil;
    }
}

void deleteAfter(address Prec, address *P) {
    if (Prec != Nil && next(Prec) != Nil) {
        *P = next(Prec);
        if (next(*P) != Nil) {
            next(Prec) = next(*P);
            prev(next(*P)) = Prec;
        } else {
            next(Prec) = Nil;
        }
        next(*P) = Nil;
        prev(*P) = Nil;
    }
}
