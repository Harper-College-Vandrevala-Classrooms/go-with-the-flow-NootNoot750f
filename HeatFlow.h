//
// Created by nickh on 11/3/2024.
//

#ifndef HEATFLOW_H
#define HEATFLOW_H
#include <iostream>
#include <iomanip>
using namespace std;
#include <cassert>

class HeatFlow {
private:
    static const int MAX_SECTIONS = 10;
    double temperatures[MAX_SECTIONS];
    bool is_source[MAX_SECTIONS];
    int num_sections;
    double K;

public:

    HeatFlow(double initial_temperature, int sections, double k, int source_index) : num_sections(sections), K(k) {
        assert(sections > 0 && sections <= MAX_SECTIONS);
        assert(source_index >= 0 && source_index < sections);
        for (int i = 0; i < MAX_SECTIONS; i++) {
            if (i < num_sections) {
                temperatures[i] = initial_temperature;
                is_source[i] = false;
                if (i == source_index) {
                    temperatures[i] = 100.0;
                    is_source[i] = true;
                }
            }
        }
    }

    void tick() {
        double new_temperatures[MAX_SECTIONS];
        for (int i = 0; i < num_sections; i++) {
            if (!is_source[i]) {
                double left_temp = (i > 0) ? temperatures[i - 1] : temperatures[i];
                double right_temp = (i < num_sections - 1) ? temperatures[i + 1] : temperatures[i];
                new_temperatures[i] = temperatures[i] + K * (left_temp - 2 * temperatures[i] + right_temp);
            } else {
                new_temperatures[i] = temperatures[i];
            }
        }
        for (int i = 0; i < num_sections; ++i) {
            temperatures[i] = new_temperatures[i];
        }
    }

    void pretty_print() const {

        for (int i = 0; i < num_sections; ++i) {
            cout << "------";
        }
        cout << "\n|";
        for (int i = 0; i < num_sections; ++i) {
            cout << setw(6) << setprecision(2) << fixed << temperatures[i] << " |";
        }
      cout << endl;
        for (int i = 0; i < num_sections; ++i) {
            cout << "------";
        }
        cout << endl;
    }

    const double * get_temperatures() {
        return temperatures;

    };
};


#endif //HEATFLOW_H
