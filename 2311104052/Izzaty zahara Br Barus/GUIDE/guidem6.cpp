#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* prev;
        Node* next;
};

class DoublyLinkedList {
    public :
        Node* head;
        Node* tail;

    DoublyLinkedList()  {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if(head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void deleteNode() {
        if(head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while(current != nullptr) {
            if(current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << "";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl; //Menampilkan Penambahan Data
        cout << "2. Delete data" << endl; //Menampilkan Penghapusan Data
        cout << "3. Update data" << endl; //Menampilkan Pembaruan Data
        cout << "4. Clear data" << endl; //Menampilkan Pembersihan Data
        cout << "5. Display data" << endl; //Menampilkan Data Yang Sudah Di Masukkan
        cout << "6. Exit" << endl; //Menampilkan Keluar Dari Program

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
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
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
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
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}