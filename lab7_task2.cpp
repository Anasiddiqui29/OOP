#include <iostream>
#include <cmath>

using namespace std ;

class Flight
{
    string schedule[2][5]; // Assuming 2 flights with 5 attributes each

public:
    Flight(string scheduleData[2][5]) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                schedule[i][j] = scheduleData[i][j];
            }
        }
    }

    void display() {
        cout << "Flight Schedule:" << endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << schedule[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool checkAvailability(const string& date, const string& departure, const string& destination, const string& seatType, int numOfSeats) {
        for (int i = 0; i < 2; ++i) {
            if (schedule[i][0] == date && schedule[i][1] == departure && schedule[i][2] == destination) {
                if (seatType == "economy") {
                    int availableSeats = stoi(schedule[i][3]);
                    if (availableSeats >= numOfSeats) {
                        return true;
                    }
                } else if (seatType == "business") {
                    int availableSeats = stoi(schedule[i][4]);
                    if (availableSeats >= numOfSeats) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void updateSeats(const string& date, const string& departure, const string& destination, const string& seatType, int numOfSeats) {
        for (int i = 0; i < 2; ++i) {
            if (schedule[i][0] == date && schedule[i][1] == departure && schedule[i][2] == destination) {
                if (seatType == "economy") {
                    int availableSeats = stoi(schedule[i][3]);
                    availableSeats -= numOfSeats;
                    schedule[i][3] = to_string(availableSeats);
                } else if (seatType == "business") {
                    int availableSeats = stoi(schedule[i][4]);
                    availableSeats -= numOfSeats;
                    schedule[i][4] = to_string(availableSeats);
                }
            }
        }
    }
};

class Reservation 
{

    string clientName;
    string passportNumber;
    string dateOfDeparture;
    string departurePoint;
    string destinationPoint;
    string seatType;

    public:
    Reservation(const string& name, const string& passport, const string& date, const string& departure, const string& destination, const string& seat) :
            clientName(name), passportNumber(passport), dateOfDeparture(date), departurePoint(departure), destinationPoint(destination), seatType(seat) {}

    void makeReservation(Flight& flight)
    {
        if (flight.checkAvailability(dateOfDeparture, departurePoint, destinationPoint, seatType, 1)) 
        {
            cout << "Reservation confirmed for " << clientName << ". Flight details: ";
            flight.display();
            flight.updateSeats(dateOfDeparture, departurePoint, destinationPoint, seatType, 1);
        } 
        else 
        {
            tentativeReservation(flight);
        }
    }

    void tentativeReservation(Flight& flight) 
    {
        cout << "Tentative reservation made for " << clientName << ". Flight details: ";
        flight.display();
    }

    void display()
    {
        cout << "Passenger: " << clientName << ", Passport: " << passportNumber << ". ";
    }
};

int main() 
{
    string scheduleData[2][5] = {{"3/5/24", "New York", "London", "100", "50"}, {"2024-03-06", "London", "New York", "80", "40"}};
    Flight flight(scheduleData);

    Reservation reservation1("John Doe", "AB123456", "3/5/24", "New York", "London", "economy");
    reservation1.makeReservation(flight);

    Reservation reservation2("Alice Smith", "CD789012", "3/6/24", "London", "New York", "business");
    reservation2.makeReservation(flight);

    Reservation reservation3("Bob Johnson", "EF345678", "3/7/24", "Los Angeles", "Paris", "economy");
    reservation3.makeReservation(flight); // Tentative reservation
    return 0;
}

