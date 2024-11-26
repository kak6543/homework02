#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// ksenia: to compile: g++ -std=c++11 -pthread -o Question4 Question4.cpp
// to run: ./Question4

void plotData(const std::vector<double>& x, const std::vector<double>& y) {
    std::ofstream dataFile("beam_bending_data.csv");
    if (dataFile.is_open()) {
        dataFile << "x,y\n";
        for (size_t i = 0; i < x.size(); ++i) {
            dataFile << x[i] << "," << y[i] << "\n";
        }
        dataFile.close();
        std::cout << "Data saved to beam_bending_data.csv. Used MATLAB to visualize the data." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

int main() {
    // beam bending eq'n parameters
    double E = 210e9;  // Young's Modulus in Pa (Steel)
    double I = 8.33e-6;  // moment of inertia in m^4
    double L = 10.0;  // length of the beam in m
    double w = 1000.0;  // load in N/m

    // discretize the beam length
    int num_points = 100;
    std::vector<double> x(num_points);
    std::vector<double> y(num_points);

    for (int i = 0; i < num_points; ++i) {
        x[i] = L * i / (num_points - 1);
        // beam defl'n eq'n for a uniformly loaded cantilever beam: y=(w*x^2/(24*E*I))*(x^2-4*L*x+6*L*L)
        y[i]=(w*x[i]*x[i]/(24*E*I))*(x[i]*x[i]-4*L*x[i]+6*L*L);
    }

    // save the data to a CSV file
    plotData(x, y);

    return 0;
}
