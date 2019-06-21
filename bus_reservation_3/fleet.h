#pragma once
#include<vector>
#include"bus.h"

using namespace std;

class fleet {
private:
    int size;
    vector<bus> buses;
    vector<int> busNumsVec;
public:
    fleet() {size = 0;};

    vector<bus> getBuses() {
        return buses;
    }
    void addBus(bus b1) {
        buses.push_back(b1);
        size++;
    }
    void display() {
        cout << "Number of buses: " << buses.size() << endl;
        for (bus b : buses) {
            b.display();
        }
    }
    int getSize() {
        return this->size;
    }
    int getBusNum(int index) {
        return buses[index].getBusNum();
    }
        vector<int> getAllBusNumbers() {
        for (bus b : buses) {
            busNumsVec.push_back(b.getBusNum());
            return busNumsVec;
        }
    }
    void displayBus(int busNum) {
        buses[busNum - 1].display();
    }
    void makeReservation(int busNum, int seatNum, string name) {
        buses[busNum - 1].reserveSeat(seatNum, name);
    }
};

