#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date();
    Date(int m, int d, int y);
    int getMonth();
    int getDays();
    int getYear();
    void setMonth(int m);
    void setDays(int d);
    void setYear(int y);

private:
    int month;
    int days;
    int year;
};

#endif // DATE_H
