#include <iostream>
#include "doublelist.h"

DoubleLinkedList::DoubleLinkedList() : head(nullptr) {}

void DoubleLinkedList::tambahKendaraan(const std::string& noPolisi, const std::string& warna, int tahun) {
    // Periksa apakah nomor polisi sudah terdaftar
    if (cariKendaraan(noPolisi)) {
        std::cout << "nomor polisi sudah terdaftar\n";
        return;
    }

    // Buat node baru
    Node* newNode = new Node{noPolisi, warna, tahun, nullptr, nullptr};

    // Tambahkan node di depan daftar
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

bool DoubleLinkedList::cariKendaraan(const std::string& noPolisi) {
    Node* temp = head;
    while (temp) {
        if (temp->noPolisi == noPolisi) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DoubleLinkedList::tampilkanData() {
    std::cout << "\nDATA LIST 1\n";
    Node* temp = head;
    while (temp) {
        std::cout << "no polisi : " << temp->noPolisi << "\n";
        std::cout << "warna     : " << temp->warna << "\n";
        std::cout << "tahun     : " << temp->tahun << "\n";
        temp = temp->next;
    }
}
