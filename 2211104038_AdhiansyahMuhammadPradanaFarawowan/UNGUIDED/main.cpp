#include "doublelist.cpp"

int main()
{
    TwoWayList L;
    create_list(L);
    Kendaraan vehikel;

    for (int i = 0; i < 4; i = i + 1)
    {
        std::cout << "Masukkan nomor polisi\t\t: ";
        std::cin >> vehikel.nopol;

        std::cout << "Masukkan warna kendaraan\t: ";
        std::cin >> vehikel.warna;

        std::cout << "Masukkan tahun kendaraan\t: ";
        std::cin >> vehikel.tahun_buat;

        if (find_elm(L, vehikel) != nullptr)
        {
            std::cout << "Elemen sudah ada. Diabaikan." << '\n';
            continue;
        }

        ElmList *P = alloc_elm(vehikel);
        insert_last(L, P);
        std::cout << '\n';
    }

    std::cout << "Data kendaraan:" << '\n';
    print_info(L);

    std::cout << '\n';

    Kendaraan k_pengguna;
    std::cout << "Masukkan nopol yang ingin dicari: ";
    std::cin >> k_pengguna.nopol;

    ElmList *elm_result = find_elm(L, k_pengguna);
    if (elm_result != nullptr)
    {
        std::cout << "Kendaraan ditemukan." << '\n';
        std::cout << "Nomor polisi: " << elm_result->info.nopol << '\n';
        std::cout << "Warna kendaraan: " << elm_result->info.warna << '\n';
        std::cout << "Tahun kendaraan: " << elm_result->info.tahun_buat << '\n';
    }
    else
    {
        std::cout << "Kendaraan dengan nomor polisi " << k_pengguna.nopol << " tidak ditemukan." << '\n';
    }
    std::cout << '\n';

    ElmList *firstt;
    delete_first(L, firstt);
    std::cout << "Setelah elemen pertama hilangg:" << '\n';

    print_info(L);

    ElmList *lastt;
    delete_last(L, lastt);
    std::cout << "Setelah elemen terakhir hilangg:" << '\n';

    print_info(L);

    if (L.first != nullptr)
    {
        ElmList *afterr;
        delete_after(L.first, afterr);
        std::cout << "Setelah hapus:" << '\n';
        print_info(L);
    }
    ElmList *P = L.first;
    while (P != nullptr)
    {
        ElmList *next = P->next;
        dealloc_elm(P);
        P = next;
    }

    return 0;
}