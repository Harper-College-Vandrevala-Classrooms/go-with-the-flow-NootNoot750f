//
// Created by nickh on 11/3/2024.
//

#include "HeatFlow.h"
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    double initial_temperature = 10.0;
    int number_of_sections = 5;
    double K = 0.1;
    int source_index = 0;

    HeatFlow h(initial_temperature, number_of_sections, K, source_index);
    h.pretty_print();

    const double* temperatures = h.get_temperatures();
    for (int i = 0; i < number_of_sections; ++i) {
        assert(temperatures[i] == (i == source_index ? 100.0 : initial_temperature));
    }

    h.tick();
    h.pretty_print();


    assert(temperatures[0] == 100.0);
    cout << "Passed Test 1" << endl;
    assert(temperatures[1] == 19.0);
    cout << "Passed Test 2" << endl;
    assert(temperatures[2] == 10.0);
    cout << "Passed Test 3" << endl;
    assert(temperatures[3] == 10.0);
    cout << "Passed Test 4" << endl;
    assert(temperatures[4] == 10.0);
    cout << "Passed Test 5" << endl;

    h.tick();
    h.pretty_print();


    assert(temperatures[0] == 100.0);
    cout << "Passed Test 6" << endl;
    assert(temperatures[1] == 26.2);
    cout << "Passed Test 7" << endl;
    assert(temperatures[2] == 10.9);
    cout << "Passed Test 8" << endl;
    assert(temperatures[3] == 10.0);
    cout << "Passed Test 9" << endl;
    assert(temperatures[4] == 10.0);
    cout << "Passed Test 10" << endl;

    return 0;
}