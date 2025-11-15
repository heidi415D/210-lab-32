#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL = 2;

int main() {

    srand(time(0)); // seed random number generator
    deque<Car> line; // toll booth line

    // add initial cars 
    for (int i = 0; i < INITIAL; i++) {
        line.push_back(Car()); // add to back of line
    }

    cout << "Initial line of cars:\n";
    for (Car &c : line) {
        cout << "    ";
        c.print();
    }
    
    // deque operations
    if (!line.empty()) {
        cout << "\n tetsing pop_front(): removing first car:\n";
        line.pop_front();
    }

    cout << "testing push_back(): adding new car...\n";
    line.push_back(Car());

    cout << "\nQueue after testing operations:\n";
    for (Car &c : line) {
        cout << "    ";
        c.print();
    }
    return 0;
}
