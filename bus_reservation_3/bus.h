#pragma once

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class bus {
private:
    int busNum;
    string driver, arrivalTime, departureTime, origin ,destination;
    string reservations[32];
    int emptySeats;
public:
    bus(int busNum, string driver, string arrivalTime, string departureTime,
            string origin, string destination){

        this->busNum = busNum;
        this->driver = driver;
        this->arrivalTime = arrivalTime;
        this->departureTime = departureTime;
        this->origin = origin;
        this->destination = destination;

        emptySeats = 32;

        for (int i = 0; i < 32; i++ ){
            reservations[i] = "Empty";
        };
    }
    void trimReservationNames(){
        for (string s : reservations) {
            if (s.length() > 12) {
                s = s.substr(0, 12);
            }
        }
    }
    void printReservations() {

        trimReservationNames();


        cout << setw(5) << right;
        for (int i = 0; i < 32;) {
            cout << setw(5) <<  i+1 << ":" << setw(12) << right << reservations[i];
            cout << setw(5) <<  i+2 << ":" << setw(12) << right << reservations[i+1];
            cout << setw(5) <<  i+3 << ":" << setw(12) << right << reservations[i+2];
            cout << setw(5) <<  i+4 << ":" << setw(12) << right << reservations[i+3];
            cout << endl;
            i += 4;
        }
    }
    int getBusNum() {
        return this->busNum;
    }

    bool reservationsFull() {
        int numOfRes = 0;

        for (string s : reservations) {
            if (s != "Empty") {
                numOfRes++;
            }
        }
        if (numOfRes == 32)
            return true;
        else
            return false;
    }

    void displayBasic() {
        cout << left << setw(15) << "Bus no:" << busNum << endl;
        cout << left << setw(15) << "Driver:" << left << setw(15) << driver << left << setw(15) << "Arrival time:" << left << setw(15)  << arrivalTime;
        cout << left << setw(15) << "Departure time:" << left << setw(15) <<  departureTime << endl;
        cout << left << setw(15) << "From:" << left << setw(15) << origin << left << setw(15) << "To:" << left << setw(15) << destination << endl;
        cout << "This bus has " << emptySeats << " empty seats." << endl;
        cout << endl;
    }

    void display() {
        cout << "*********************************************************************************************" << endl;

        cout << left << setw(15) << "Bus no:" << busNum << endl;
        cout << left << setw(15) << "Driver:" << left << setw(15) << driver << left << setw(15) << "Arrival time:" << left << setw(15)  << arrivalTime;
        cout << left << setw(15) << "Departure time:  " << left << setw(15) <<  departureTime << endl;
        cout << left << setw(15) << "From:" << left << setw(15) << origin << left << setw(15) << "To:" << left << setw(15) << destination << endl;

        cout << "*********************************************************************************************" << endl;

        printReservations();

        cout << endl;
        cout << "There are " << emptySeats << " seats empty in bus number: " << busNum << endl;

        for (int i = 0; i < 32; i++) {
            if (reservations[i] != "Empty") {
                cout << "The seat number " << i + 1 << " is reserved for " << reservations[i] << "." << endl;
            }
        }
        cout << endl;

    }
    void reserveSeat(int seatNo, string name) {

        if(reservations[seatNo - 1] == "Empty") {
            reservations[seatNo - 1] = name;
            emptySeats--;
        } else {
            cout << "That seat is reserved." << endl;
            cout << endl;
        }
    }
};