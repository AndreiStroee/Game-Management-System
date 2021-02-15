#include "Date.h"
#include <ctime>

Date::Date()
{
    *this = now();
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

bool Date::operator==(const Date& rhs) const
{
    return day == rhs.day && month == rhs.month && year == rhs.year;
}

bool Date::operator!=(const Date& rhs) const
{
    return !(*this == rhs);
}

std::string Date::DateToString() const
{
    ostringstream os;
    os << setfill('0');
    os << setw(2) << day << "/";
    os << setw(2) << month << "/";
    os << setw(4) << year;
    return os.str();
}

ostream& Date::putDataInStream(ostream& os) const
{
    // date formatted output (DD/MM/YY)
    os << setfill('0');
    os << setw(2) << day << "/";
    os << setw(2) << month << "/";
    os << setw(4) << year;
    return os;
}

istream& Date::getDataFromStream(istream& is)
{
    // read in date as DD/MM/YY
    char ch;
    is >> day >> ch >> month >> ch >> year;
    return is;
}

ostream& operator<<(ostream& os, const Date& aDate)
{
    return aDate.putDataInStream(os);
}

istream& operator>>(istream& is, Date& aDate)
{
    return aDate.getDataFromStream(is);
}

const Date Date::now()
{
    // makes a Date using the current system datetime
    time_t now = time(0);
    struct tm t;
    localtime_s(&t, &now);
    return Date(static_cast<int>(t.tm_mday), static_cast<int>(t.tm_mon + 1), static_cast<int>(t.tm_year + 1900));
}