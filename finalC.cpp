// finalC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>

class Address {
    string city;
    int postCode;
public:
    Address();

    Address(string city, int postCode);

    void toString();
};

Address::Address() {
    city = "Istanbul";
    postCode = 343434;
}

Address::Address(string city, int postCode) {
    this->city = city;
    this->postCode = postCode;
}

void Address::toString() {
    cout << "City is " << city << ", post code is " << postCode;
}

class Accomodation {
    string name;
    Address address;

public:
    Accomodation(string name, Address address);

    void toString();

    string getName();
};

Accomodation::Accomodation(string name, Address address) {
    this->name = name;
    this->address = address;
}

void Accomodation::toString() {
    cout << "Name is " << name << ", ";
    address.toString();
}

string Accomodation::getName() {
    return name;
}


class Hotel : public Accomodation {
    int oneNight = 100;

    double price();

public:
    int stars;
    int beds;

    Hotel(string name, Address address, int stars, int beds);

    double getPrice();

    void invoice();

};

Hotel::Hotel(string name, Address address, int stars, int beds) :Accomodation(name, address) {
    this->stars = stars;
    this->beds = beds;
}

double Hotel::getPrice() {
    return price();
}

void Hotel::invoice() {
    Accomodation::toString();
    cout << ", Star is " << stars << ", number of beds are " << beds + ", total price is " << getPrice() << " TL"<<endl;
}

double Hotel::price() {
    double total = 0;
    if (beds > 2 && stars < 3) {
        total = beds * oneNight * stars * 0.8;
    }
    else if (beds > 4 && stars > 4)
        total = beds * oneNight * stars * 0.7;
    else
        total = beds * oneNight;

    return total;
}

void printInfo(Hotel hotels[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << i << ". Hotel's name: " << hotels[i].getName() << " and price: " << hotels[i].getPrice() << endl;
    }
}

int main()
{
    Address address("Istanbul", 12345);
    Hotel hotel("Grand Istanbul", address, 3, 2);
    hotel.invoice();
    cout << hotel.getName() << endl;
    cout << hotel.getPrice() << endl;

    Address a2("Ankara", 12346);
    Address a3("Izmir", 123457);
    Address a4("Mugla", 123458);
    Address a5("Antalya", 123459);

    Hotel h2("Grand Ankara", a2, 7, 6);
    Hotel h3("Grand Izmir", a3, 5, 3);
    Hotel h4("Grand Mugla", a4, 2, 3);
    Hotel h5("Grand Antalya", a5, 1, 2);

    Hotel hotels[] = { hotel,h2,h3,h4,h5 };
    printInfo(hotels, 5);
}
