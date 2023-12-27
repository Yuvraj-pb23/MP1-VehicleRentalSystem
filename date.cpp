#include"date.h"
#include"string_helper.h"

const char DELIMITER = '/';

Date :: date( )
{
    time_t now = time(NULL);
    this->empty = false;
    this->date = *localtime(&now);
}

Date :: Date (string date)
{
    if(date.length() < 8)
    {
        this->empty = true;
        return;
    }
    
    this->empty = false;

    vector<string> dateComponents = split(date,DELIMITER);
    int day = stoi(dateComponents[0]);
    int month = stoi(dateComponents[1]);
    int year = stoi(dateComponents[2]);

    time_t now = time(NULL);
    this->date = *localtime(&now);
this->date.tm_year = year -1900;
this->date.tm_mon = month -1;
this->date.tm_mday = day;

mktime(&this->date);

}

bool Date :: isEmpty ( ) const
{
    return this->empty;
}

string Date :: toString ( ) const
{
    if (this->empty)
    {
        return "";
    }

    stringstream ss;
    ss << this->date.tm_mday << "/" << this->date.tm_mon + 1 << "/" << this->date.tm_year + 1900;
    return ss.str();
}

Date Date :: operator + (int days)
{
    Date newDate = *this;

    if(newDate.isEmpty())
    {
        return newDate;
    }

    newDate.date.tm_mday += days;
    time_t adjustedDate = mktime(&newDate.date);
    newDate.date = *localtime(&adjustedDate);

    return newDate;
}

bool Date :: operator > (Date date) const
{
    
}
}