#pragma once

#include <ctime>	
#include <iomanip>	
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    Date();
    Date(int, int, int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDate(int, int, int);
    bool operator == (const Date&) const; 	      // equality operator
    bool operator != (const Date&) const; 	      // non-equality operator
    string DateToString() const;
    //operator string() const;                        // cast operator (to string)
    ostream& putDataInStream(ostream& os) const;	  // sends Date info into an output stream
    istream& getDataFromStream(istream& is);	      // receives Date info from an input stream
    static const Date now();                        // returns system date
private:
    int day, month, year;
};

ostream& operator << (ostream&, const Date&);
istream& operator >> (istream&, Date&);