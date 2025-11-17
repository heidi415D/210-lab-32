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

    for (int i = 0; i < LANES; i++) { // populate lanes
        for(int j = 0; j < 2; j++) {
            lanes[i].push_back(Car());
        }
    }

    cout << "Initial lanes:\n"; // print initial lanes
    for (int i = 0; i < LANES; i++) {
        cout << "Lane " << (i + 1) << ":\n";
        for (Car &c : lanes[i]) {
            cout << "    ";
            c.print();
     }
    }

    for (int t = 1; t <= 20; t++) { // start time loop

        cout << "\nTime: " << t << "\n";
       
        for (int i = 0; i < LANES; i++) { // operations for each lane
        
            if (lanes[i].empty()) { // empty lane - 50/50
                int r = rand() % 100;

                  if (r < 50) {
                Car newCar;
                cout << "Lane: " << i + 1 << " Joined: ";
                newCar.print();
                lanes[i].push_back(newCar); 
             } 
            else {
                cout << "Lane: " << i + 1 << " No action\n";
            }
      }
            else { // non-empty lane - 50% paid, 50% joined
                int r = rand() % 100;

                if (r < 50) {
                    cout << "Lane: " << i + 1 << " Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                } else {
                    Car newCar;
                    cout << "Lane: " << i + 1 << " Joined: ";
                    newCar.print();
                    lanes[i].push_back(newCar);
                }
                
            }
        }
    
        // print queues for all lanes
        for (int i = 0; i < LANES; i++) {
            cout << "Lane " << i + 1 << " Queue:\n";
            if (lanes[i].empty()) {
                cout << "    empty\n";
            }
            else {
                for (Car &c : lanes[i]) {
                    cout << "    ";
                    c.print();
                 }
            }
        }
    }
    
       return 0;
}