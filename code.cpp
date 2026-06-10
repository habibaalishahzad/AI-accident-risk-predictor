#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string model;
    int speed;

public:
    Vehicle(string model, int speed) {
        this->model = model;
        this->speed = speed;
    }

    virtual void vehicleType() = 0;

    string getModel() {
        return model;
    }

    int getSpeed() {
        return speed;
    }
};

class Car : public Vehicle {
public:
    Car(string model, int speed) : Vehicle(model, speed) {}

    void vehicleType() override {
        cout << "Vehicle Type : Car" << endl;
    }
};

class Driver {
private:
    string name;

public:
    Driver() {
        name = "Unknown";
    }

    Driver(string name) {
        this->name = name;
    }

    Driver(const Driver &d) {
        name = d.name;
    }

    string getName() {
        return name;
    }
};

class RiskAnalyzer {
public:
    string predictRisk(int speed, string weather, string traffic, string road) {
        int score = 0;

        if (speed > 100)
            score += 40;
        else if (speed > 70)
            score += 20;

        if (weather == "Rainy")
            score += 30;

        if (weather == "Foggy")
            score += 40;

        if (traffic == "Heavy")
            score += 20;

        if (road == "Slippery")
            score += 30;

        if (road == "Damaged")
            score += 20;

        if (score >= 80)
            return "HIGH";
        else if (score >= 40)
            return "MEDIUM";
        else
            return "LOW";
    }
};

class AlertSystem {
public:
    void sendAlert(string risk) {
        if (risk == "HIGH") {
            cout << "\nHIGH ACCIDENT RISK!" << endl;
            cout << "Recommendation: Reduce speed immediately." << endl;
        }
        else if (risk == "MEDIUM") {
            cout << "\nMEDIUM ACCIDENT RISK!" << endl;
            cout << "Recommendation: Stay alert and maintain distance." << endl;
        }
        else {
            cout << "\nLOW ACCIDENT RISK" << endl;
            cout << "Recommendation: Safe driving conditions." << endl;
        }
    }
};

int main() {
    try {
        string name;
        int speed;
        string weather;
        string traffic;
        string road;

        cout << "=============================================\n";
        cout << "     AI TRAFFIC ACCIDENT RISK PREDICTOR\n";
        cout << "=============================================\n";

        cout << "Enter Driver Name: ";
        getline(cin, name);

        cout << "Enter Vehicle Speed: ";
        cin >> speed;
        cin.ignore();

        cout << "Enter Weather (Clear/Rainy/Foggy): ";
        getline(cin, weather);

        cout << "Enter Traffic (Low/Medium/Heavy): ";
        getline(cin, traffic);

        cout << "Enter Road Condition (Good/Slippery/Damaged): ";
        getline(cin, road);

        Driver d1(name);
        Driver d2(d1);

        Vehicle* vehicle = new Car("Toyota", speed);

        RiskAnalyzer analyzer;

        string risk = analyzer.predictRisk(
            speed,
            weather,
            traffic,
            road
        );

        string report[6] = {
            d2.getName(),
            vehicle->getModel(),
            weather,
            traffic,
            road,
            risk
        };

        cout << "\n============== REPORT ==============\n";

        cout << "Driver Name    : " << report[0] << endl;
        vehicle->vehicleType();
        cout << "Vehicle Model  : " << report[1] << endl;
        cout << "Speed          : " << speed << " km/h" << endl;
        cout << "Weather        : " << report[2] << endl;
        cout << "Traffic Level  : " << report[3] << endl;
        cout << "Road Condition : " << report[4] << endl;
        cout << "Risk Level     : " << report[5] << endl;

        cout << "\nName Length    : " << name.length() << endl;

        ofstream file("TrafficReport.txt");

        file << "Driver: " << report[0] << endl;
        file << "Vehicle: " << report[1] << endl;
        file << "Weather: " << report[2] << endl;
        file << "Traffic: " << report[3] << endl;
        file << "Road: " << report[4] << endl;
        file << "Risk: " << report[5] << endl;

        file.close();

        AlertSystem alert;
        alert.sendAlert(risk);

        cout << "\n=============================================\n";
        cout << "Prediction Completed Successfully\n";
        cout << "=============================================\n";

        delete vehicle;
    }
    catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}
