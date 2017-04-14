#include "date.h"

Date::Date(int m, int d, int y)
{
    month = m;
    days  = d;
    year  = y;
}


int Date::getMonth()
{
    return month;
}

int Date::getDays()
{
    return days;
}

int Date::getYear()
{
    return year;
}

void Date::setMonth(int m)
{
    month = m;
}

void Date::setDays(int d)
{
    days = d;
}

void Date::setYear(int y)
{
    year = y;
}
