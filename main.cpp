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
        for (Car &c : lanes[i]) {
            cout << "    ";
            c.print();
     }
    }

    for (int t = 1; t <= 20; t++) {
        cout << "\nTime: " << t << "\n";
       
        for (int i = 0; i <= LANES; i++) { // operations for each lane
        
            cout << "Time: " << t << "\n";

            int r = rand() % 100;

            if (r < 50) {
                cout << "Lane: " << i + 1 << "PaidL ";
                lanes[i].front().print();
                lanes[i].pop_front();
            }
            else {
                Car
            }
        }
    }

    return 0;
}