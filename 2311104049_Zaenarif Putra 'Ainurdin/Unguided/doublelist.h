#ifndef DOUBLIST_H
#define DOUBLIST_H

#include <string>
using namespace std;

class Vehicle {
public:
    string nopol;  
    string warna; 
    int tahun;   
    Vehicle* next; 
    Vehicle* prev;

    Vehicle(string nopol, string warna, int tahun);
};

class VehicleList {
private:
    Vehicle* first;  
    Vehicle* last;   
public:
    VehicleList();
    ~VehicleList();
    void insertLast(Vehicle* P);
    void insertAtPosition(int position, Vehicle* P);
    Vehicle* searchVehicle(string nopol);
    bool deleteVehicle(const string& nopol);
    void printList() const;
    bool isRegistered(string nopol) const;
};

#endif