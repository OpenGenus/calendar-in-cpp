#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>

using namespace std;

void printCalendar(int year)
{

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthList[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << " -----------------------------------" << endl;
    cout << "           Calendar - " << year << endl;
    cout << " -----------------------------------" << endl;

    int days;
    int startingGap;

    int tempY = year - 1;
    startingGap = (tempY + tempY / 4 - tempY / 100 + tempY / 400 + 1) % 7;

    for (int i = 0; i < 12; i++)
    {
        if (i == 1)
        {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                days = 29;
            else
                days = monthDays[i];
        }
        else
            days = monthDays[i];

        cout << endl
             << "  ------------" << monthList[i] << "-------------" << endl;

        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
        int k;
        for (k = 0; k < startingGap; k++)
            cout << "     ";

        for (int j = 1; j <= days; j++)
        {
            k++;
            cout << setw(5) << j;
            if (k > 6)
            {
                k = 0;
                cout << endl;
            }
        }
        if (k)
            cout << endl;
        startingGap = k;
    }
    return;
}

int main()
{
    char option;
    do
    {
        cout << "Calendar Menu" << endl;
        cout << "1. Enter y/Y to see calendar" << endl;
        cout << "2. Enter n/N to quit" << endl
             << endl;
        cout << "Enter your option" << endl;
        cin >> option;

        switch (option)
        {
        case 'Y':
        case 'y':
            int year;
            cout << "Enter the calendar year: ";
            cin >> year;
            cout << endl;
            printCalendar(year);
            break;
        }
    } while (option != 'N' && option != 'n');

    return 0;
}