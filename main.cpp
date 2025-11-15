#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL = 2;

int main() {
    deque<Car> line;

    // add initial cars 
    for (int i = 0; i < INITIAL; ++i) {
        line.push_back(Car());
    }

    cout << "Initial cars in line:\n"; 
    for (int i = 0; i <= line.size(); i++) {
        line[i].print();
    }

    return 0;
}