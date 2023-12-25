Major Project - 1.
Vehicle Rental System.
Reference: Object Orinted Programming with C++(E Balagurusamy) Book(8th Edition.



File name                                    Class/Struct Name                         Description

serializable.cpp                               Serializable                            Any class which is derived from this class can be converted into string.
Storable.cpp                                   Storable                                Any subclasses of this can be stored in a file. As all data stored in a file must be serialized, this class is derived from Serializable class.
error.cpp                                      Error                                   This class is used for exception handeling.
string_helper.h, string_heplper.cpp            -                                       It comprises Helper methods related to strings.
date.h,date.cpp                                Date                                    This class helps in dealing with date and time data. it i derived from serializable class.
vehicle.h, vehicle.cpp                         Vehicle                                 This class represents a vehicle. The objects of this class can be stored in a file, so it is derived from storable class.
user.h, user.cpp                               User                                    This class represents a User. The objects of this class can be stored in a file, so it is derived from storable class.
trip.h, trip.cpp                               Trip                                    This class represents a trip. The objects of this class can be stored in a file, so it is derived from storable class.
table.h, table.cpp                             Table                                   it is a generic class which represents in-memory table. Table can be of any class derived from Storable. This class is friend of storage class.
database.h, database.cpp                       Database                                This class helps in handeling low-level file operations. Database contains all Tables. This class is a friend of Storable and Table classes.
database_templates.cpp                         -                                       The templated functions of Database class go in this file.
application.h, application.cpp                 Application                             This class Handles menu and all front-end operations related to this application.
main.cpp                                       -                                       This is the main entry point of this application.
