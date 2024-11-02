#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // Constructor untuk inisialisasi head dan tail
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan elemen di depan list 
    void insert(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode; // Jika list kosong, tail juga mengarah ke node baru
        }
        head = newNode;
        cout << "Data " << data << " berhasil ditambahkan.\n";
    }

    // Fungsi untuk menghapus elemen dari depan list 
    void deleteNode() {
        if (head == nullptr) {
            cout << "List kosong. Tidak ada data untuk dihapus.\n";
            return; // Jika list kosong
        }
        Node* temp = head;
        cout << "Data " << temp->data << " berhasil dihapus.\n";
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // Jika hanya satu elemen di list
        }
        delete temp; // Hapus elemen
    }

    // Fungsi untuk mengupdate data di list
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                cout << "Data " << oldData << " berhasil diupdate menjadi " << newData << ".\n";
                return true; // Jika data ditemukan dan diupdate
            }
            current = current->next;
        }
        cout << "Data " << oldData << " tidak ditemukan.\n";
        return false; // Jika data tidak ditemukan
    }

    // Fungsi untuk menghapus semua elemen di list
    void deleteAll() {
        if (head == nullptr) {
            cout << "List sudah kosong.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        cout << "Semua data berhasil dihapus.\n";
    }

    // Fungsi untuk menampilkan semua elemen di list
    void display() {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }
        Node* current = head;
        cout << "Data dalam list: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "\n===== Menu =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Update Data\n";
        cout << "4. Hapus Semua Data\n";
        cout << "5. Tampilkan Data\n";
        cout << "6. Keluar\n";
        cout << "Pilih Menu: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Masukkan data yang akan ditambahkan: ";
                cin >> data;
                list.insert(data);
                break;
            }
            case 2: {
                list.deleteNode();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Masukkan data yang akan diupdate: ";
                cin >> oldData;
                cout << "Masukkan data baru: ";
                cin >> newData;
                list.update(oldData, newData);
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                cout << "Keluar dari program.\n";
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid.\n";
                break;
            }
        }
    }
    return 0;
}
