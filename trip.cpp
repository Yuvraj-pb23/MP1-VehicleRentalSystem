#include "trip.h"
#include "string_helper.h"

#include<iostream>

const char DELIMETER = ';' ;

Trip :: Trip (const Vehicle * vehicle, const User * user, Date startDate, Date endDate, long recordId,
    long startReading, long endReading, double fare, bool isCompeted) : Storable (recordId)
    {
        this->vehicle = vehicle;
        this->user = user;
        this->startDate = startDate;
        this->endDate = endDate;
        this->startReading = startReading;
        this->endReading = endReading;
        this->fare = fare;
        this->completed = isCompeted;
    }

    const User & Trip :: getUser() const{return *this->user;}
    const Vehicle & Trip :: getVehicle() const{return *this->vehicle;}
    Date Trip :: getStartDate( ) const{return this->startDate;}
    Date Trip :: getEndDate( )const{return this->endDate;}
    long Trip :: getStartReading( ) const{return this->startReading;}
    long Trip :: getEndReading( ) const{return this->startReading;}
    long Trip :: getFare() const{return this->fare;}
    bool Trip :: isCompeted() const{return this->completed;}
  
  void Trip :: startTrip (long startReading)
  {
    this->startReading = startReading;
  }

  double Trip :: completeTrip (long endReading)
  {
    if (this->completed)
    {
        return this->fare;
    }

    this->endReading = endReading;
    this->fare = (this->endReading - this->startReading) * this->vehicle->getPricePerKm();
    this->completed = true;

    return this->fare;
  }

  void Trip :: display ( ) const 
  { 
    cout << "Vehicle Details : "    <<endl;
    cout << "Regestration no. : "   << this->vehicle->getRegistrationNumber()  <<endl;
    cout << "Vehicle Type : "       << this->vehicle->getVehicleTypeName()  <<endl;
    cout << "Company name : "       << this->vehicle->getCompanyName()  <<endl;
    cout << "Price per km : "       << this->vehicle->getPricePerKm() << "Rs/Km" <<endl;
 
    cout << endl; 
     
    cout << "User Details : "       <<endl;
    cout << "Name : "               <<this->user->getName() <<endl;
    cout << "Contact : "            <<this->user->getContact() <<endl; 

    cout << endl;

    cout << "Trip Details : "       <<endl;
    cout << "Start date : "         <<this->startDate.toString() <<endl;
    cout << "End date : "           <<this->endDate.toString() <<endl;

    string tripStatus = "Not started";

    if ( this->startReading != 0 )
    {
        tripStatus = "on going";
        cout << "Start Reading : "  <<this->startReading << endl;
    }

    if ( this->completed)
    {
        tripStatus = "Completed";
        cout << "End reading : "    <<this->endReading  <<endl;
        cout << "Total run : "      <<this->endReading - this->startReading  <<endl;
        cout << "Total fare : "     <<this->fare << endl;
    }

    cout << "Trip status : "        <<tripStatus <<endl;
 }

 string Trip :: toString()  const
 {
    stringstream ss;
    ss << recordId << DELIMETER
       << vehicle->getRecordId() << DELIMETER
       << user->getRecordId() << DELIMETER
       << startDate.toString() << DELIMETER
       << endDate.toString() << DELIMETER
       << startReading << DELIMETER
       << endReading << DELIMETER
       << fare << DELIMETER
       << completed;

    return ss.str();   
 }

 void Trip :: setDataFrom (Storable * s)
 {
    Trip * t = static_cast<Trip*> ( s );

    if ( t )
    {
        this->vehicle = t->vehicle;
        this->user = t->user;
        this->startDate = t->startDate;
        this->endDate = t->endDate;
        this->startReading = t->startReading;
        this->endReading = t->endReading;
        this->fare = t->fare;
        this->completed = t->completed;
    }
 }
    