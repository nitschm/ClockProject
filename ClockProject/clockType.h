#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H

#include<iostream>
using namespace std;

class clockType
{
private:
    int hr;
    int min;
    int sec;
public:
    void setH(int h);
    void setM(int m);
    void setS(int s);
    void setTime(int h, int m, int s);
    int getH() { return hr; } //inline function
    int getM() { return min; } //inline function
    int getS() { return sec; } //inline function
    void getTime(int& h, int& m, int& s);
    void printTime() const;
    void incrementH();
    void incrementM();
    void incrementS();
    bool equalTime(const clockType& otherOb) const;
    clockType(); //default constructor
    clockType(int, int, int); //constructor
    ~clockType(); //deconstructor
    friend void frdFun(const clockType& ob);

    //overloaded operators
    bool operator==(const clockType&);
    clockType operator+(const clockType& right);
    clockType operator+(int n);
    bool operator>(const clockType&);
    bool operator<(const clockType&);
    friend ostream& operator<<(ostream&, const clockType&);
    friend istream& operator>>(istream&, clockType&);
    clockType operator++();
    clockType operator++(int);
};

#endif // CLOCKTYPE_H
