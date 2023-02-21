#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>

using namespace std;

void printCalendar(int year)
{

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthList[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    int current_year = 1900 + local_time->tm_year;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;

    cout << " -----------------------------------" << endl;
    cout << "\033[1;33m"
         << "           Calendar - " << year
         << "\033[0m" << endl;
    cout << " -----------------------------------" << endl;

    int days;
    int startingGap;

    int tempY = year - 1;
    startingGap = (tempY + tempY / 4 - tempY / 100 + tempY / 400 + 1) % 7;

    for (int i = 0; i < 12; i++)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            days = 29;
        else
            days = monthDays[i];

        cout << endl;
        if (year == current_year && current_month == i + 1)
        {
            cout << "\033[1;1;32m"
                 << "  ------------" << monthList[i] << "-------------"
                 << "\033[0m" << endl;
        }
        else if (year < current_year || (year == current_year && i + 1 < current_month))
        {
            cout << "\033[31m"
                 << "  ------------" << monthList[i] << "-------------"
                 << "\033[0m" << endl;
        }
        else
        {
            cout << "  ------------" << monthList[i] << "-------------"
                 << endl;
        }

        if (year < current_year || (year == current_year && i + 1 <= current_month))
        {
            cout << "\033[35m"
                 << "  Sun"
                 << "\033[0m";
            cout << "\033[1;33m"
                 << "  Mon  Tue  Wed  Thu  Frid";
            cout << "\033[35m"
                 << "  Sat"
                 << "\033[0m" << endl;
        }
        else
        {
            cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
        }
        int k;
        for (k = 0; k < startingGap; k++)
            cout << "     ";

        for (int j = 1; j <= days; j++)
        {
            k++;
            if (year == current_year && current_month == i + 1 && current_day == j)
            {
                cout << "\033[1;1;32m" << setw(5) << j << "\033[0m";
            }
            else if (year < current_year || (year == current_year && i + 1 < current_month) || (year == current_year && i + 1 == current_month && j < current_day))
            {
                cout << "\033[31m" << setw(5) << j << "\033[0m";
            }
            else
            {
                cout << setw(5) << j;
            }
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
    int year;
    while (1)
    {
        cout << "------------------------------------------------" << endl;
        cout << "Enter a year or type anything else to quit: ";
        cin >> year;
        cout << "------------------------------------------------" << endl;
        if (std::cin.fail())
            break;
        printCalendar(year);
    }

    return 0;
}