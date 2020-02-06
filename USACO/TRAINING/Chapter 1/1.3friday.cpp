/*
ID: sah2020
PROG: friday
LANG: C++14
*/
#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream cin ("friday.in");
//    ofstream cout ("friday.out");
    int n;
    cin >> n;
    int days[15];
    days[0] = days[1] = days[2] = days[3] = days[4] = days[5] = days[6] = 0;
    int day = 1;
    int week = 0;
    int year = 1900;
    int month = 1;
    while(year < n + 1900)
    {
        if (day == 13)
        {
            days[week]++;
        }
        if (month == 2 && day == 28 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)))
        {
            month++;
            day = 0;
        }
        else if (month == 2 && day == 29)
        {
            month++;
            day = 0;
        }
        if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        {
            month++;
            day = 0;
        }
        if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 ||
                          month == 8 || month == 10))
        {
            month++;
            day = 0;
        }
        if (day == 31 && month == 12)
        {
            month = 1;
            day = 0;
            year++;
        }
        day++;
        week = (week + 1) % 7;
    }
    cout << days[5] << " " << days[6] << " " << days[0] << " " << days[1] << " "
         << days[2] << " " << days[3] << " " << days[4] << "\n";
}
