#include "doublelist.h"

int main()
{
    List L;
    CreateList(L);
    Kendaraan kendaraan;
    string nopol;
    int choice;
    address foundNode; // Pindahkan deklarasi ke sini

    while (true)
    {
        // Menampilkan menu
        cout << "===== Menu =====" << endl;
        cout << "1. Tambah Kendaraan" << endl;
        cout << "2. Hapus Kendaraan" << endl;
        cout << "3. Cari Kendaraan" << endl;
        cout << "4. Tampilkan Semua Kendaraan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Tambah Kendaraan
            cout << "Masukkan nomor polisi: ";
            cin >> kendaraan.nopol;
            cout << "Masukkan warna kendaraan: ";
            cin >> kendaraan.warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> kendaraan.thnBuat;

            // Cek jika nomor polisi sudah ada
            {
                address current = L.First;
                bool exists = false;
                while (current != nullptr)
                {
                    if (current->info.nopol == kendaraan.nopol)
                    {
                        exists = true;
                        break;
                    }
                    current = current->next;
                }

                if (exists)
                {
                    cout << "Nomor polisi sudah terdaftar." << endl;
                }
                else
                {
                    insertLast(L, kendaraan);
                    cout << "Kendaraan dengan nomor polisi " << kendaraan.nopol << " berhasil ditambahkan." << endl;
                }
            }
            break;

        case 2: // Hapus Kendaraan
            cout << "Masukkan Nomor Polisi yang akan dihapus: ";
            cin >> nopol;

            // Mencari elemen berdasarkan nomor polisi
            foundNode = findElm(L, nopol);

            if (foundNode != nullptr)
            {
                // Jika ditemukan, hapus node
                if (foundNode == L.First)
                {
                    deleteFirst(L, foundNode);
                }
                else if (foundNode == L.Last)
                {
                    deleteLast(L, foundNode);
                }
                else
                {
                    deleteAfter(L, foundNode->prev, foundNode);
                }
                cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
            }
            else
            {
                cout << "Nomor Polisi tidak ditemukan." << endl;
            }
            break;

        case 3: // Cari Kendaraan
            cout << "Masukkan Nomor Polisi yang dicari: ";
            cin >> nopol;

            // Mencari elemen berdasarkan nomor polisi
            foundNode = findElm(L, nopol);

            if (foundNode != nullptr)
            {
                cout << "Nomor Polisi: " << foundNode->info.nopol << endl;
                cout << "Warna: " << foundNode->info.warna << endl;
                cout << "Tahun: " << foundNode->info.thnBuat << endl;
            }
            else
            {
                cout << "Nomor Polisi tidak ditemukan." << endl;
            }
            break;

        case 4: // Tampilkan Semua Kendaraan
            cout << "DATA LIST 1" << endl;
            printInfo(L);
            break;

        case 5: // Keluar
            cout << "Keluar dari program." << endl;
            return 0;

        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
        cout << endl; // Untuk memberi jarak sebelum menu berikutnya
    }

    return 0;
}
