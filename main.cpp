#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL = 2;
const int LANES = 4;

int main() {

    srand(time(0)); // seed random number generator
    deque<Car> lanes[LANES]; // creates lanes, each is a deque<Car>

    for (int i = 0; i < LANES; i++) {
        for(int j = 0; j < 2; j++) {
            lanes[i].push_back(Car());
        }
    }

    cout << "Initial lanes:\n";
    for (int i = 0; i < LANES; i++) {
        cout << "Lane " << (i + 1) << ":\n";
      

    // add initial cars 
    for (int i = 0; i < INITIAL; i++) {
        line.push_back(Car()); // add to back of line
    }

    // queue display
    cout << "Initial queue:\n";
    for (Car &c : line) {
        cout << "    ";
        c.print();
    }

    int timeStep = 1;

    // run simulation until line is empty
    while (!line.empty()) {
        
        int r = rand() % 100; 

        if (r < 55) {
            cout << "\nTime: " << timeStep << " Operation: Car paid: ";
            line.front().print();
            line.pop_front();
        }
        else { // 45% chance a new car arrives
            Car newCar;
            cout << "\nTime: " << timeStep << " Operation: Joined lane: ";
            newCar.print();
            line.push_back(newCar);
        }

        // print queue after operation
        cout << "Queue:\n";
        if (line.empty()) {
            cout << "    Empty\n";
        }
        else {
            for (Car &c : line) {
                cout << "    ";
                c.print();
            }
        }

        timeStep++;
    }

    return 0;
}
