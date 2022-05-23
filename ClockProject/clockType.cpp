#include "clockType.h"
#include <iostream>
using namespace std;

void clockType::setTime(int h, int m, int s)
{
    if (h >= 0 && h < 24)
        hr = h;
    else
        hr = 0;

    if (0 <= m && m < 59)
        min = m;
    else
        min = 0;

    if (0 <= s && s < 60)
        sec = s;
    else
        sec = 0;
}

void clockType::getTime(int& h, int& m, int& s)
{
    h = hr;
    m = min;
    s = sec;
}

void clockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";

    if (min < 10)
        cout << "0";
    cout << min << ":";

    if (sec < 10)
        cout << "0";
    cout << sec;
}

void clockType::incrementH()
{
    hr++;
    if (hr > 23)
        hr = 0;
}

void clockType::incrementM()
{
    min++;
    if (min > 59)
    {
        incrementH();
        min = 0;
    }
}

void clockType::incrementS()
{
    sec++;
    if (sec > 59)
    {
        incrementM();
        sec = 0;
    }
}

bool clockType::equalTime(const clockType& otherOb) const
{
    return (hr == otherOb.hr && min == otherOb.min && sec == otherOb.sec);
}

clockType::clockType()
{
    hr = min = sec = 0;
}

clockType::clockType(int h, int m, int s)
{
    setTime(h, m, s);
}

clockType::~clockType()
{
    //cout << "bye" << endl;
}

void frdFun(const clockType& ob)
{
    if (ob.hr < 10)
        cout << "0";
    cout << ob.hr << ":";

    if (ob.min < 10)
        cout << "0";
    cout << ob.min << ":";

    if (ob.sec < 10)
        cout << "0";
    cout << ob.sec;
}

bool clockType::operator==(const clockType& right)
{
    return (hr == right.hr && min == right.min && sec == right.sec);
}


clockType clockType::operator+(const clockType& right)
{
    clockType temp;

    temp.hr = hr + right.hr;
    temp.min = min + right.min;
    temp.sec = sec + right.sec;

    temp.min += temp.sec / 60;
    temp.sec = temp.sec % 60;
    temp.hr += temp.min / 60;
    temp.min = temp.min % 60;
    temp.hr = temp.hr % 24;

    return temp;
}

clockType clockType::operator+(int n)
{
    clockType tempClock;

    tempClock.hr = hr;
    tempClock.min = min;
    tempClock.sec = sec + n;

    tempClock.min += tempClock.sec / 60;
    tempClock.sec = tempClock.sec % 60;
    tempClock.hr += tempClock.min / 60;
    tempClock.min = tempClock.min % 60;
    tempClock.hr = tempClock.hr % 24;

    return tempClock;
}


bool clockType::operator<(const clockType& right)
{
    if (hr < right.hr)
        return true;
    else if (hr == right.hr && min < right.min)
        return true;
    else if (hr == right.hr && min == right.min && sec < right.sec)
        return true;
    else
        return false;
}

bool clockType::operator>(const clockType& right)
{
    if (hr > right.hr)
        return true;
    else if (hr == right.hr && min > right.min)
        return true;
    else if (hr == right.hr && min == right.min && sec > right.sec)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& os, const clockType& ob)
{
    if (ob.hr < 10)
        os << "0";
    os << ob.hr << ":";

    if (ob.min < 10)
        os << "0";
    os << ob.min << ":";

    if (ob.sec < 10)
        os << "0";
    os << ob.sec;

    return os;
}

istream& operator>>(istream& is, clockType& ob)
{
    is >> ob.hr >> ob.min >> ob.sec;
    return is;
}

clockType clockType::operator++() //prefix: ++ob
{
    incrementS();
    return (*this);
}

clockType clockType::operator++(int) //postfix: ob++
{
    clockType temp(hr, min, sec);
    incrementS();
    return temp;
}
