#ifndef database_cpp
#define database_cpp
#include"database.h"
#include"string_helper.h"
#include<iostream>

using namespace std;

const char DELIMETER = ';';
Database::Database() throw (IOError, MemoryError) 
{
	try 
	{
		this->vehicleTable = new Table<Vehicle>("vehicles.txt");
		this->userTable = new Table<User>("users.txt");
		this->tripTable = new Table<Trip>("trips.txt");

		this->fetchAllVehicles();
		this->fetchAllUsers();
		this->fetchAllTrips();
	}
	catch (...) 
	{
		throw;
	}
}

void Database::fetchAllVehicles() throw (IOError, MemoryError) 
{
	this->vehicleTable->fileStream.open(this->vehicleTable->fileName);
	if (!this->vehicleTable->fileStream)
	{
		throw IOError();
	}
	for (string line; getline(this->vehicleTable->fileStream, line);)
	{
		vector<string> components = split(line, DELIMETER);
		auto recordId                   = stol(components[0]);
		auto registrationNumber         = components[1];
		auto type                       = VehicleType(stoi(components[2]));
		auto seats                      = stoi(components[4]);
		auto companyName                = components[4];
		auto pricePerKm                 = stod(components[5]);
		auto PUCExpirationDate          = Date(components[6]);

		Storable*record = new Vehicle (registrationNumber, type, seats, companyName, pricePerKm, PUCExpirationDate, recordId);

	}
}
#endif