#include <iostream>
#include <string>
using namespace std;

// Define the structure for police data
struct infotype {
    string nopol;
    string warna;
    int tahun;
};

// Define the structure for list element
struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

// Define the structure for list
struct List {
    ElmList* first;
    ElmList* last;
};

// Function prototypes
void createList(List& L);
ElmList* alokasi(infotype x);
void dealokasi(ElmList* p);
void insertLast(List& L, ElmList* p);
void printInfo(List L);
ElmList* findElm(List L, infotype x);
void deleteFirst(List& L, ElmList*& p);
void deleteLast(List& L, ElmList*& p);
void deleteAfter(ElmList* prec, ElmList*& p);
void deleteElement(List& L, string nopol);

int main() {
    List L;
    infotype x;
    
    // Initialize list
    createList(L);
    
    // Input data
    char more;
    do {
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.tahun;
        
        ElmList* p = alokasi(x);
        insertLast(L, p);
        
        cout << "Input more data? (y/n): ";
        cin >> more;
    } while (more == 'y' || more == 'Y');
    
    // Print initial list
    cout << "\nDATA LIST 1\n";
    printInfo(L);
    
    // Search for element D001
    cout << "\nMencari nomor polisi D001:\n";
    x.nopol = "D001";
    ElmList* found = findElm(L, x);
    if (found != NULL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.tahun << endl;
    } else {
        cout << "Data tidak ditemukan\n";
    }
    
    // Delete element D003
    cout << "\nMenghapus nomor polisi D003:\n";
    deleteElement(L, "D003");
    
    // Print final list
    cout << "\nDATA LIST 1 (setelah penghapusan)\n";
    printInfo(L);
    
    return 0;
}

void createList(List& L) {
    L.first = NULL;
    L.last = NULL;
}

ElmList* alokasi(infotype x) {
    ElmList* p = new ElmList;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void dealokasi(ElmList* p) {
    delete p;
}

void insertLast(List& L, ElmList* p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void printInfo(List L) {
    ElmList* p = L.first;
    while (p != NULL) {
        cout << "Nomor Polisi : " << p->info.nopol << endl;
        cout << "Warna        : " << p->info.warna << endl;
        cout << "Tahun        : " << p->info.tahun << endl;
        cout << endl;
        p = p->next;
    }
}

ElmList* findElm(List L, infotype x) {
    ElmList* p = L.first;
    while (p != NULL) {
        if (p->info.nopol == x.nopol) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void deleteFirst(List& L, ElmList*& p) {
    p = L.first;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.first = p->next;
        L.first->prev = NULL;
        p->next = NULL;
    }
}

void deleteLast(List& L, ElmList*& p) {
    p = L.last;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.last = p->prev;
        L.last->next = NULL;
        p->prev = NULL;
    }
}

void deleteAfter(ElmList* prec, ElmList*& p) {
    p = prec->next;
    prec->next = p->next;
    if (p->next != NULL) {
        p->next->prev = prec;
    }
    p->next = NULL;
    p->prev = NULL;
}

void deleteElement(List& L, string nopol) {
    ElmList* p;
    if (L.first->info.nopol == nopol) {
        deleteFirst(L, p);
    } else if (L.last->info.nopol == nopol) {
        deleteLast(L, p);
    } else {
        ElmList* prec = L.first;
        while (prec->next != NULL && prec->next->info.nopol != nopol) {
            prec = prec->next;
        }
        if (prec->next != NULL) {
            deleteAfter(prec, p);
        }
    }
    if (p != NULL) {
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
        dealokasi(p);
    } else {
        cout << "Data tidak ditemukan\n";
    }
}