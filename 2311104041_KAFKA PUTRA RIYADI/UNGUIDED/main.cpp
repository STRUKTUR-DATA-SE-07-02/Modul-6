#include <iostream>
#include "doublelist.h"
#include "doublelist.cpp"


int main() {
    DoubleLinkedList list;
    std::string noPolisi, warna;
    int tahun;  

    // Input pertama
    std::cout << "masukkan nomor polisi: ";
    std::cin >> noPolisi;
    std::cout << "masukkan warna kendaraan: ";
    std::cin >> warna;
    std::cout << "masukkan tahun kendaraan: ";
    std::cin >> tahun;
    list.tambahKendaraan(noPolisi, warna, tahun);

    // Input kedua
    std::cout << "\nmasukkan nomor polisi: ";
    std::cin >> noPolisi;
    std::cout << "masukkan warna kendaraan: ";
    std::cin >> warna;
    std::cout << "masukkan tahun kendaraan: ";
    std::cin >> tahun;
    list.tambahKendaraan(noPolisi, warna, tahun);

    // Input ketiga (cek duplikat)
    std::cout << "\nmasukkan nomor polisi: ";
    std::cin >> noPolisi;
    std::cout << "masukkan warna kendaraan: ";
    std::cin >> warna;
    std::cout << "masukkan tahun kendaraan: ";
    std::cin >> tahun;
    list.tambahKendaraan(noPolisi, warna, tahun);

    // Input keempat
    std::cout << "\nmasukkan nomor polisi: ";
    std::cin >> noPolisi;
    std::cout << "masukkan warna kendaraan: ";
    std::cin >> warna;
    std::cout << "masukkan tahun kendaraan: ";
    std::cin >> tahun;
    list.tambahKendaraan(noPolisi, warna, tahun);

    // Tampilkan data
    list.tampilkanData();

    return 0;
}
