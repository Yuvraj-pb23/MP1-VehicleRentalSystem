#include "vehicle.h"
#include "string_helper.h"

const char DELIMITER = ';' ;

Vehicle :: Vehicle (string registrationNumber, VehicleType type, int seats,
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
cout << "Vehicle Details : "        << endl;
cout << "Registration no. : "       << this->registrationNumber << endl;
cout << "Vehicle type : "           << this->getVehicleTypeName() <<endl;
cout << "No of seats : "            << this->seats << endl;
cout << "Company Name : "           << this->companyName << endl; 
cout << "Price per km : "           << this->pricePerkm << "Rs/Km" << endl;
cout << "PUC Expiration Date : "    << this->PUCExpirationDate.toString() << endl;
}

string Vehicle :: toString ( ) const
{
    stringstream ss;
    ss  << recordId << DELIMITER
        << registrationNumber << DELIMITER
        << type << DELIMITER
        << seats << DELIMITER
        << companyName << DELIMITER
        << to_string (pricePerkm) << DELIMITER
        << PUCExpirationDate.toString();

    return ss.str();    
}

void Vehicle :: setDataFrom ( Storable * s)
{
    Vehicle * v = dynamic_cast<Vehicle*> ( s );

    if ( v )
    {
        this->registrationNumber = v->registrationNumber;
        this->type = v->type;
        this->seats = v->seats;
        this->companyName = v->companyName;
        this->pricePerkm = v->pricePerkm;
        this->PUCExpirationDate = v->PUCExpirationDate;
    }
}