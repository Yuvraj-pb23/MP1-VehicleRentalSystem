#include "vehicle.h"
#include "string_helper.h"

const char DELIMITER = ';' ;

Vehicle :: Vehicle(string registrationNumber, VehicleType type, int seats;
     string companyName, double pricePerkm, Date PUCExpirationDate,
    long recordId) : Storable (recordId)
    {
      this->registrationNumber = registrationNumber;
      this->type = type;
      this->seats = seats;
      this->companyName = companyName;
      this->pricePerkm = pricePerkm;
      this->PUCExpirationDate = PUCExpirationDate;
    }

    string Vehicle :: getRegistrationNumber ( ) const {return this->registrationNumber;}
    VehicleType Vehicle :: getVehicleType ( ) const {return this->type;}
    int Vehicle :: getSeats ( ) const {return this->seats;}
    string Vehicle :: getCompanyName ( ) const {return this->companyName;}
    double Vehicle :: getPricePerKm ( ) const {return this->pricePerkm;}
    Date Vehicle :: getPUCExpirationDate ( ) const {return this->PUCExpirationDate;}
    void Vehicle :: setPricePerKm (double newPrice) {this->pricePerkm = newPrice;}
    string Vehicle :: getVehicleTypeName ( ) const
    {
        switch(this->type)
        {
            case VehicleType :: bike:
            return "Bike";
            case VehicleType :: car:
            return "Car";
            case VehicleType :: towera:
            return "Towera";
            defaylt:
            return "";
        }
    }

void Vehicle :: display ( ) const
{
    
}
