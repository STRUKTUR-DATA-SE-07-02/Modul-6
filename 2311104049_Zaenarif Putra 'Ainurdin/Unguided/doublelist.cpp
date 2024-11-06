#include "doublelist.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string nopol, string warna, int tahun) {
    this->nopol = nopol;
    this->warna = warna;
    this->tahun = tahun;
    this->next = nullptr;
    this->prev = nullptr;
}

VehicleList::VehicleList() {
    first = nullptr;
    last = nullptr;
}

VehicleList::~VehicleList() {
    Vehicle* current = first;
    while (current != nullptr) {
        Vehicle* nextVehicle = current->next;
        delete current;  
        current = nextVehicle;
    }
}

void VehicleList::insertLast(Vehicle* P) {
    if (first == nullptr) {
        first = P;
        last = P;
    } else {
        last->next = P;
        P->prev = last;
        last = P;
    }
}

void VehicleList::insertAtPosition(int position, Vehicle* P) {
    if (position == 1) {
        if (first == nullptr) {
            first = P;
            last = P;
        } else {
            P->next = first;
            first->prev = P;
            first = P;
        }
    } else {
        Vehicle* current = first;
        int index = 1;
        while (current != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }
        if (current == nullptr || current->next == nullptr) {
            insertLast(P);
        } else {
            P->next = current->next;
            P->prev = current;
            current->next->prev = P;
            current->next = P;
        }
    }
}

Vehicle* VehicleList::searchVehicle(string nopol) {
    Vehicle* P = first;
    while (P != nullptr) {
        if (P->nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

bool VehicleList::deleteVehicle(const string& nopol) {
    Vehicle* current = first;
    while (current != nullptr) {
        if (current->nopol == nopol) {
            if (current == first) {
                first = current->next;
                if (first != nullptr) first->prev = nullptr;
            } else if (current == last) {
                last = current->prev;
                if (last != nullptr) last->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;  
            return true;  
        }
        current = current->next;
    }
    return false;
}

void VehicleList::printList() const {
    Vehicle* P = first;
    int i = 1;
    while (P != nullptr) {
        cout << "DATA LIST " << i << endl;
        cout << "Nomor polisi : " << P->nopol << endl;
        cout << "Warna     : " << P->warna << endl;
        cout << "Tahun     : " << P->tahun << endl;
        P = P->next;
        i++;
    }
}

bool VehicleList::isRegistered(string nopol) const {
    Vehicle* P = first;
    while (P != nullptr) {
        if (P->nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}
