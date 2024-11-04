#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node {
    string nomor_polisi;
    string warna;
    string tahun;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(const string& nomor, const string& warna, const string& tahun) {
    Node* newNode = new Node;
    newNode->nomor_polisi = nomor;
    newNode->warna = warna;
    newNode->tahun = tahun;
    newNode->next = nullptr;
    return newNode;
}

// Prosedur untuk menampilkan daftar
void displayList(Node* head) {
    Node* current = head;
    cout << "DATA LIST 1\n \n";
    while (current != nullptr) {
        cout << "Nomor Polisi : " << current->nomor_polisi << endl;
        cout << "Warna        : " << current->warna << endl;
        cout << "Tahun        : " << current->tahun << endl;
        current = current->next;
    }
}


// Prosedur untuk menghapus node pertama
void deleteFirst(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Prosedur untuk menghapus node terakhir
void deleteLast(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

// Prosedur untuk menghapus node setelah node tertentu
void deleteAfter(Node* prec) {
    if (prec == nullptr || prec->next == nullptr) return;
    Node* temp = prec->next;
    prec->next = temp->next;
    delete temp;
}

// Fungsi untuk mencari node berdasarkan nomor polisi
Node* findNode(Node* head, const string& nomor_polisi) {
    Node* current = head;
    while (current != nullptr) {
        if (current->nomor_polisi == nomor_polisi) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Fungsi untuk menghapus node berdasarkan nomor polisi
void deleteByLicenseNumber(Node*& head, const string& nomor_polisi) {
    if (head == nullptr) return;

    // Jika elemen yang akan dihapus adalah elemen pertama
    if (head->nomor_polisi == nomor_polisi) {
        deleteFirst(head);
        cout << "Data dengan nomor polisi " << nomor_polisi << " berhasil dihapus.\n \n";
        return;
    }

    // Mencari node sebelum node yang akan dihapus
    Node* current = head;
    while (current->next != nullptr && current->next->nomor_polisi != nomor_polisi) {
        current = current->next;
    }

    // Jika elemen ditemukan
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Data dengan nomor polisi " << nomor_polisi << " berhasil dihapus.\n \n";
    } else {
        cout << "Nomor Polisi " << nomor_polisi << " tidak ditemukan.\n";
    }
}

// Fungsi utama
int main() {
    // Membuat list
    Node* head = createNode("D004", "kuning", "90");
    head->next = createNode("D003", "merah", "89");
    head->next->next = createNode("D001", "hitam", "90");

    // Menampilkan list awal
    cout << "";
    displayList(head);

    // Meminta nomor polisi yang akan dihapus
    string nomor_dihapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> nomor_dihapus;

    // Menghapus elemen berdasarkan nomor polisi
    deleteByLicenseNumber(head, nomor_dihapus);

    // Menampilkan list setelah penghapusan
    cout << "";
    displayList(head);

    return 0;
}   
