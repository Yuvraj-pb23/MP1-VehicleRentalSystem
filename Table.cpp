#include"Table.h"
#include<iostream>

using namespace std;

template <class T> Table<T> :: Table (string fileName) throw (MemoryError) {
    this->filename = fileName;
    this->records = new vector<Storable *>();

    if (!this->records) {
        throw MemoryError();
    }
}

template <class T> long Table<T> :: getNextRecordId() const {
    return this -> records -> size() + 1;
}

template <class T> const T * const Table<T> :: addNewRecord(T record) throw (MemoryError,IOError) {

    T * newRecord = new T(record);
    if (!newRecord) {
        throw new MemoryError();
    }

    newRecord->recordId = this->getNextRecordId();
    this->records->push_back(newRecord);

    try{
        this->writeTofile();
    }
    catch (IOError erroe){
        this->records->pop_back();
        delete newRecord;
        throw;
    }
    return newRecord;
}

template <class T> const T * const Table<T> :: addNewRecord (T record) throw (MemoryError,IOError) {
    T * newRecord = new T (record);
    if(!newRecord)
    {
        
    }
}