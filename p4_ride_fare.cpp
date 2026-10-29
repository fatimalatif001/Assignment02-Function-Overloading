#include <iostream>
#include <fstream>
using namespace std;

double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);

int main() {
    cout << "fare(10) = " << fare(10) << endl;
    cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
    cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
    cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
    cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
    cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;

    // ---- Part B: write your code below this line ----
    int totalRides;
    cout << "How many rides? ";
    cin >> totalRides;

    ofstream outFile("rides.txt");
    double totalCollected = 0;

    for (int i = 1; i <= totalRides; i++) {
        char vehicle;
        double km;
        int promo;
        cout << "Ride " << i << " vehicle (B/R/C), km, promo %: ";
        cin >> vehicle >> km >> promo;

        double currentFare;
        if (promo == 0) {
            currentFare = fare(km, vehicle);
        } else {
            currentFare = fare(km, vehicle, promo);
        }

        totalCollected += currentFare;
        outFile << "Ride " << i << " (" << vehicle << "), " << km << " km -> Rs. " << currentFare << endl;
    }

    outFile << "Total collected: Rs. " << totalCollected << endl;
    outFile.close();

    // fare(10, 40);
    // Error : call of overloaded 'fare(int, int)' is ambiguous
    // Reason: 40 can convert to both double and char, so compiler gets confused.
    // Fix 1 : fare(10, 40.0);
    // Fix 2 : fare(10, (double)40);

    return 0;
}

double fare(double km, double ratePerKm) {
    return 100.0 + (km * ratePerKm);
}

double fare(double km, double ratePerKm, bool peakHour) {
    double baseFare = fare(km, ratePerKm);
    if (peakHour) {
        return baseFare * 1.2;
    }
    return baseFare;
}

double fare(double km, char vehicle) {
    double rate = 0;
    if (vehicle == 'B') rate = 25.0;
    else if (vehicle == 'R') rate = 35.0;
    else if (vehicle == 'C') rate = 50.0;
    else return 0;

    return fare(km, rate);
}

double fare(double km, char vehicle, int promoPercent) {
    double baseFare = fare(km, vehicle);
    return baseFare - (baseFare * promoPercent / 100.0);
}
