#ifndef vehicle_h
#define vehicle_h

#include "date.h"
#include "storable.cpp"
#include<string>

using namespace std;

typedf enum {bike = 1,car = 2,towera = 3} VehicleType;

class Vehicle : public Storable
{

private:

    string registrationNumber;
    VehicleType type;
    
    int seats;
    string companyName;

    double pricePerkm;
    Date PUCExpirationDate;


public:
    
    Vehicle(string registrationNumber, VehicleType type, int seats;
     string companyName, double pricePerkm, Date PUCExpirationDate,
      long recordId = 0);

    string getRegistrationNumber ( ) const;
    VehicleType getVehicleType ( ) const;
    string getVehicleTypeName ( ) const;
    int getSeats ( ) const;
    string getCompanyName ( ) const;
    double getPricePerKm ( ) const;
    Date getPUCExpirationDate ( ) const;

    void setPricePerKm (double newPrice);
    void display ( ) const;
    string toString ( ) const;
    void setDataFrom (Storable * s);
};

#endif