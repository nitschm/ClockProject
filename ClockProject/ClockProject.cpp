#include <iostream>
#include "clockType.h"
using namespace std;

int main()
{
    clockType myClock(20, 55, 50), yourClock(9, 43, 32), Clock3, Clock4;
    int h, m, s;

    cout << "Enter hour, minute and second for a time: ";
    cin >> myClock;
    cout << endl;

    cout << "The time of myClock is " << myClock << endl;
    cout << endl;

    cout << myClock++ << endl;
    cout << "myClock is " << myClock << endl;
    cout << ++myClock << endl;
    cout << "myClock is " << myClock << endl;
    cout << endl;

    cout << "The time of yourClock is " << yourClock << endl;
    cout << endl;

    if (myClock == yourClock)
        cout << "They are equal.";
    else if (myClock < yourClock)
        cout << "myClock is shorter than yourClock." << endl;
    else if (myClock > yourClock)
        cout << "myClock is longer than yourClock." << endl;
    else
        cout << "Error." << endl;

    Clock4 = myClock + 10;
    cout << "The time of Clock4 is ";
    Clock4.printTime();
    cout << endl;

    return 0;
}