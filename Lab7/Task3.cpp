#include<iostream>
#include<string>
using namespace std;

class Ticket
{
protected:
    int ticketID;
    string passengerName;
    float ticketPrice;
    string destination;
    string date;

public:
    Ticket(int id, string name, float price, string dest, string date)
    {
        ticketID = id;
        passengerName = name;
        ticketPrice = price;
        destination = dest;
        this->date = date;
    }

    virtual void reserveTicket()
    {
        cout << "Ticket Reserved" << endl;
    }

    virtual void cancelTicket()
    {
        cout << "Ticket Cancelled" << endl;
    }

    virtual void display()
    {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Ticket Price: " << ticketPrice << endl;
        cout << "Destination: " << destination << endl;
        cout << "Date: " << date << endl;
    }
};

class FlightTicket: public Ticket
{
    string airlineName;
    int flightNumber;
    string seatclass;

public:
    FlightTicket(int id, string name, float price, string dest, string date, string airline, int flight, string seat): Ticket(id, name, price, dest, date)
    {
        airlineName = airline;
        flightNumber = flight;
        seatclass = seat;
    }

    void display() override
    {
        Ticket::display();
        cout << "Airline Name: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatclass << endl;
    }
};

class TrainTicket: public Ticket
{
    int trainNumber;
    string coachType;
    string departureTime;
    int seatNumber;

public:
    TrainTicket(int id, string name, float price, string dest, string date, int train, string coach, string time): Ticket(id, name, price, dest, date)
    {
        trainNumber = train;
        coachType = coach;
        departureTime = time;
        seatNumber = 0;
    }

    void reserveTicket() override
    {
        seatNumber = rand() % 300 + 1;
    }

    void display() override
    {
        Ticket::display();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket: public Ticket
{
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, float price, string dest, string date, string company): Ticket(id, name, price, dest, date)
    {
        busCompany = company;
        seatNumber = 0;
    }

    void cancelTicket() override
    {
        cout << "Ticket Cancelled and money refunded" << endl;
    }

    void display() override
    {
        Ticket::display();
        cout << "Bus Company: " << busCompany << endl;
    }
};

class ConcertTicket: public Ticket
{
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, float price, string dest, string date, string artist, string place, string seat): Ticket(id, name, price, dest, date)
    {
        artistName = artist;
        venue = place;
        seatType = seat;
    }

    void display() override
    {
        Ticket::display();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main()
{
    FlightTicket f2(5, "Michael Scott", 3000, "Los Angeles", "15/03/2023", "American Airlines", 567, "Economy");
    TrainTicket t2(6, "Pam Beesly", 800, "Boston", "16/03/2023", 101, "Second Class", "10:30 AM");
    BusTicket b2(7, "Dwight Schrute", 600, "Philadelphia", "17/03/2023", "Greyhound");
    ConcertTicket c2(8, "Jim Halpert", 1500, "Miami", "18/03/2023", "Coldplay", "Wembley Arena", "Front Row");

    f2.display();
    cout << endl;
    t2.display();
    cout << endl;
    b2.display();
    cout << endl;
    c2.display();
    cout << endl;

    f2.reserveTicket();
    t2.reserveTicket();
    b2.cancelTicket();
    c2.cancelTicket();

    return 0;
}
