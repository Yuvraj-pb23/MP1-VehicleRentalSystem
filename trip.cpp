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
        this->isCompeted = isCompeted;
    }

    const User & Trip :: getUser() const{return *this->user;}
    const Vehicle & Trip :: getVehicle() const{return *this->vehicle;}
    Date Trip & Trip :: getUser() const{return *this->user;}
    const User & Trip :: getUser() const{return *this->user;}
    const User & Trip :: getUser() const{return *this->user;}
    const User & Trip :: getUser() const{return *this->user;}
    const User & Trip :: getUser() const{return *this->user;}
    