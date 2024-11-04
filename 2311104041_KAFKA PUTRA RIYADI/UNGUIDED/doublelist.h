#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <string>

struct Node {
    std::string noPolisi;
    std::string warna;
    int tahun;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
public:
    DoubleLinkedList();
    void tambahKendaraan(const std::string& noPolisi, const std::string& warna, int tahun);
    bool cariKendaraan(const std::string& noPolisi);
    void tampilkanData();

private:
    Node* head;
};

#endif // DOUBLELIST_H
