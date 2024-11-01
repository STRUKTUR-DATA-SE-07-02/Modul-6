#include <iostream>

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class DLinkedList
{
public:
    Node *head;
    Node *tail;

    // Konstruktor
    DLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Tambah elemen ke pertama
    void insert_first(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;

        new_node->prev = nullptr;
        new_node->next = head;

        // Else akan berlaku jika head (baca: list) sama dengan null
        if (head != nullptr)
        {
            head->prev = new_node;
        }
        else
        {
            tail = new_node;
        }
        head = new_node;

        std::cout << "Insert at first successfully performed" << '\n';
    }

    // Hapus elemen pertama
    void delete_first()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // Jika hanya ada satu elemen di list
        }

        delete temp;
        std::cout << "Delete at first successfully performed" << '\n';
    }

    // Perbarui data
    bool update(int old_data, int new_data)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == old_data)
            {
                current->data = new_data;
                return true; // Jika ditemukan
            }
            current = current->next;
        }
        return false; // Jika tidak ditemukan
    }

    // Hapus semua elemen
    void delete_list()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;

        std::cout << "List has been deleted" << '\n';
    }

    // Tampilkan semua elemen
    void print_list()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << '\n';
    }
};

int main()
{
    DLinkedList list;

    // Akan membuat program terus berjalan sampai pilihan "6" dimasukkan
    while (true)
    {
        std::cout << "1. Add data" << '\n';
        std::cout << "2. Delete data" << '\n';
        std::cout << "3. Update data" << '\n';
        std::cout << "4. Delete list" << '\n';
        std::cout << "5. Print list" << '\n';
        std::cout << "6. Exit" << '\n';

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            std::cout << "Enter data to add: ";
            std::cin >> data;
            list.insert_first(data);
            std::cout << '\n';
            break;
        }
        case 2:
        {
            list.delete_first();
            std::cout << '\n';
            break;
        }
        case 3:
        {
            int old_data, new_data;
            std::cout << "Enter old data: ";
            std::cin >> old_data;
            std::cout << "Enter new data: ";
            std::cin >> new_data;
            bool updated = list.update(old_data, new_data);
            if (!updated)
            {
                std::cout << "Data not found" << '\n';
            } else {
                std::cout << "Data successfully updated" << '\n';
            }

            std::cout << '\n';
            break;
        }
        case 4:
        {
            list.delete_list();
            std::cout << '\n';
            break;
        }
        case 5:
        {
            list.print_list();
            std::cout << '\n';
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            std::cout << "Invalid choice" << '\n';
            std::cout << '\n';
            break;
        }
        }
    }
    return 0;
}
