
#include <limits>
#include"bus.h"
#include"fleet.h"

using namespace std;

int checkMaxBusNo(fleet &myFleet);
int showMenu();
void install(fleet& myFleet);
void showReservations (fleet &f1);
void makeReservation(fleet &f1);
void showAvailBuses(fleet &f1);
void showSpecBusInfo(fleet &f1);

int main() {
    int sel;
    bool again = true;

    fleet f1;
    bus b1(1, "Mark", "12:13 PM", "9:00 AM", "Toledo", "Detroit");
    bus b2(2, "David", "7:22 PM", "12:00 PM", "Detroit", "Buffalo");
    bus b3(3, "Chris", "4:55 PM", "10:30 AM", "New York", "Chicago");
    bus b4(4, "Alex", "6:10 PM", "10:30 PM", "Denver", "Grand Junction");
    bus b5(5, "Jacob", "3:15 AM", "12:30 PM", "Ann Arbor", "Grand Rapids");

    f1.addBus(b1);
    f1.addBus(b2);
    f1.addBus(b3);
    f1.addBus(b4);
    f1.addBus(b5);

    f1.display();

    while (again == true) {
        sel = showMenu();

        switch (sel) {
            case 1 :
                install(f1);
                break;
            case 2:
                makeReservation(f1);
                break;
            case 3:
                showReservations(f1);
                break;
            case 4:
                showSpecBusInfo(f1);
                break;
            case 5:
                showAvailBuses(f1);
                break;
            case 6:
                again = false;
                break;
        }
    }

    return 0;
}

void showAvailBuses(fleet &f1) {
    for (bus b : f1.getBuses()) {
        if (!b.reservationsFull())
            b.displayBasic();
    }
}

void makeReservation(fleet& f1) {
    int busNo = 0;
    int seatNo = 0;
    string passName;

    cout << "Enter bus number to reserve: ";
    cin >> busNo;
    cout << endl;

    f1.displayBus(busNo);

    cout << "Which seat would you like to reserve?: ";
    cin >> seatNo;
    cout << endl;

    cout << "What is the name of the passenger?: ";
    cin >> passName;
    cout << endl;

    f1.makeReservation(busNo, seatNo, passName);
}

void showSpecBusInfo(fleet &f1) {
    if (f1.getBuses().empty()) {
        cout << "There are no buses in the fleet." << endl;
        cout << endl;
    }
    int busNoSel = 0;
    bool validBusNum = false;

    while (!validBusNum) {
        vector<int> busNums;
        cout << "Enter bus number to display: ";
        cin >> busNoSel; cout << endl;
        busNums = f1.getAllBusNumbers();
        for (int n : busNums) {
            if (busNoSel == n)
                validBusNum = true;
        }
        f1.displayBus(busNoSel);
    }
}

void showReservations (fleet &f1) {

    if (f1.getBuses().empty()) {
        cout << "There are no buses in the fleet." << endl;
        cout << endl;
    }
    else {
        for (int i = 0; i < f1.getBuses().size(); i++) {
            f1.getBuses()[i].display();
        }
    }
//    int busNoSel = 0;
//    bool validBusNum = false;
//
//    while (!validBusNum) {
//        vector<int> busNums;
//        cout << "Enter bus number to display: ";
//        cin >> busNoSel; cout << endl;
//        busNums = f1.getAllBusNumbers();
//        for (int n : busNums) {
//            if (busNoSel == n)
//                validBusNum = true;
//        }
//        f1.displayBus(busNoSel);
//    }
}

void install(fleet &myFleet) {

    int busNum = 0;
    string driverName, arrival, departure, origin, destination;

    bool validNumber = false;
    int maxBusNum = 0;

    while (!validNumber) {
        cout << "Enter bus number: ";
        cin >> busNum;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << endl;

        maxBusNum = checkMaxBusNo(myFleet);

        if (busNum <= maxBusNum) {
            cout << "Invalid bus number. You must enter a number greater than the current max." << endl;
        }
        validNumber = true;
    }

    cout << "Enter driver's name: ";
    getline(cin, driverName);
    cout << endl;

    cout << "Enter arrival time: ";
    getline(cin, arrival);
    cout << endl;

    cout << "Enter departure time: ";
    getline(cin, departure);
    cout << endl;

    cout << "Enter origin location: ";
    getline(cin, origin);
    cout << endl;

    cout << "Enter destination location: ";
    getline(cin, destination);
    cout << endl;

    bus b1(busNum, driverName, arrival, departure, origin, destination);
    myFleet.addBus(b1);
}

int showMenu(){

    int selection;

    cout << left << "1. Install" << endl;
    cout << left << "2. Make reservation" << endl;
    cout << left << "3. Show all bus info" << endl;
    cout << left << "4. Show specific bus info" << endl;
    cout << left << "5. Buses available" << endl;
    cout << left << "6. Exit" << endl;
    cout << left << "Enter your choice: ";

    cin >> selection;
    cout << endl;

    return selection;
}

int checkMaxBusNo(fleet &myFleet) {

    int maxBusNo = 0;

    for (int i = 0; i < myFleet.getSize(); i++) {
        if (myFleet.getBusNum(i) >= maxBusNo)
            maxBusNo = myFleet.getBusNum(i);
    }
    return maxBusNo;
}

