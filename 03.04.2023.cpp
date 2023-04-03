#include <iostream> 
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <fstream>
using namespace std;
int DayWeek(int Day, int Month, int Year) {
    int DaysInYears, AllDays, DaysInMonths, Weeks, DayWeek;
    if (Month < 3) {
        Month = Month + 12;
        Year = Year - 1;
    }
    Month = Month + 1;
    DaysInMonths = Month * 30.6;
    DaysInYears = Year * 365.25;
    AllDays = DaysInMonths + DaysInYears + Day - 114;
    Weeks = AllDays / 7;
    DayWeek = AllDays - Weeks * 7;
    if (DayWeek == 0)
        DayWeek = 7;
    return DayWeek;
}
int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "Ru");
    int  year = 0, i = 0, feb = 28;
    string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
    string weekdays[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN"};
    int maxm[12] = { 31,  feb, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };
    cout << "Key input is available" << "\n";
    cout << "Format: /M00, /Y 0000, /? - help, /S - calendar output from a given month of a given year, /Q - finish entering keys, /CON - calendar output to the screen. /F File Name - calendar output to a file." <<"\n";
    char key[20];
    int resy = 0, mm = 0;
    do
    {
        key == "\0";
        cin >> key;
        if (key[0] == '/')
        {
            if (key[1] == 'Y')
            {
                resy = (key[2] - '0') * 1000 + (key[3] - '0') * 100 + (key[4] - '0') * 10 + key[5] - '0';
            }
            if (key[1] == 'M')
            {
                if ((key[2] == '1') and (key[3] == '0' or key[3] == '1' or key[3] == '2'))
                    mm = (key[2] - '0') * 10 + key[3] - '0';
                else
                    mm = key[2] - '0';
            }
            if (key[1] == '?')
				cout << "Instructions for using the calendar.\format: /M00, /Y 0000, /? - help, /S - calendar output from a given month of a given year,\n/Q - finish entering keys, /FCON - calendar output to the screen. /F File Name - calendar output to a file.\n";            if (key[1] == 'S')
            {
                cout <<"\nInput the month and year from which you want to see the calendar: \nMonth ";
                int yyear, m, aaa;
                cin >> m;
                cout << "Year ";
                cin >> yyear;
                if (yyear % 4 == 0)
                    maxm[1] = 29;
                if (yyear < 0)
                    cout << "Wrong year ):";
                else
                {
                    for (; m <= 12; m = m + 3)
                    {
                        cout << "\n" << setw(24) << months[m - 1] << setw(30);
                        if (m <= 11)
                            cout << months[m] << setw(30);
                        if (m + 1 <= 11)
                            cout << months[m + 1] << "\n";
                        if (m >= 11)
                            cout << "\n";
                        i = 9;
                        for (int w = 0; w < 7; w++)
                        {
                            for (int p = 0; p <= 2;)
                            {
                                if (m != 13)
                                    cout << setw(8) << weekdays[w] << setw(4);
                                if (DayWeek(1, m + p, yyear) < w + 2)
                                {
                                    for (int z = 1, s = 0; z <= 6; z++, s = s + 7)
                                    {
                                        int d = w - DayWeek(1, m + p, yyear) + s + 2;
                                        if ((m + p == 1) and (d == 1 or d == 2 or d == 3 or d == 4 or d == 5 or d == 6 or d == 7 or d == 8)
                                            or (m + p == 2) and (d == 23) or (m + p == 3) and (d == 8)
                                            or (m + p == 5) and (d == 1 or d == 9) or (m + p == 6) and (d == 12)
                                            or (m + p == 11) and (d == 4))
                                            SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                        if (d <= maxm[m + p - 1])
                                            cout << d << setw(4);
                                        else
                                            cout << "" << setw(4);
                                        SetConsoleTextAttribute(handle, (WORD)7);
                                    }
                                }
                                else
                                {
                                    cout << setw(8);
                                    for (int z = 1, s = 0; z <= 5; z++, s = s + 7)
                                    {
                                        int dd = i - DayWeek(1, m + p, yyear) + s;
                                        if ((m + p == 1) and (dd == 1 or dd == 2 or dd == 3 or dd == 4 or dd == 5 or dd == 6 or dd == 7 or dd == 8)
                                            or (m + p == 2) and (dd == 23) or (m + p == 3) and (dd == 8)
                                            or (m + p == 5) and (dd == 1 or dd == 9) or (m + p == 6) and (dd == 12)
                                            or (m + p == 11) and (dd == 4))
                                            SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                        if (dd <= maxm[m + p - 1])
                                            cout << dd << setw(4);
                                        else
                                            cout << "" << setw(4);
                                        SetConsoleTextAttribute(handle, (WORD)7);
                                    }
                                }
                                SetConsoleTextAttribute(handle, (WORD)7);
                                if (m + p < 12)
                                    p++;
                                else
                                    break;
                            }
                            cout << endl;
                            i++;
                        }
                        cout << endl;
                    }
                    maxm[1] = 28;
                }
            }
            if (resy > 0 and mm > 0)
            {
                if (resy % 4 == 0)
                    maxm[1] = 29;
                cout << "\n" << setw(18) << months[mm - 1] << "  " << resy << "\n";
                i = 9;
                if (mm >= 1 || mm <= 12 || resy >= 0)
                    for (int w = 0; w < 7; w++)
                    {
                        cout << setw(8) << weekdays[w] << setw(4);
                        if (DayWeek(1, mm, resy) < w + 2)
                        {
                            for (int z = 1, s = 0; z <= 6; z++, s = s + 7)
                            {
                                int d = w - DayWeek(1, mm, resy) + s + 2;
                                if ((mm == 1) and (d == 1 or d == 2 or d == 3 or d == 4 or d == 5 or d == 6 or d == 7 or d == 8)
                                    or (mm == 2) and (d == 23) or (mm == 3) and (d == 8)
                                    or (mm == 5) and (d == 1 or d == 9) or (mm == 6) and (d == 12)
                                    or (mm == 11) and (d == 4))
                                    SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                if (d <= maxm[mm - 1])
                                    cout << d << setw(4);
                                else
                                    cout << "" << setw(4);
                                SetConsoleTextAttribute(handle, (WORD)7);
                            }
                        }
                        else
                        {
                            cout << setw(8);
                            for (int z = 1, s = 0; z <= 5; z++, s = s + 7)
                            {
                                int dd = i - DayWeek(1, mm, resy) + s;
                                if ((mm == 1) and (dd == 1 or dd == 2 or dd == 3 or dd == 4 or dd == 5 or dd == 6 or dd == 7 or dd == 8)
                                    or (mm == 2) and (dd == 23) or (mm == 3) and (dd == 8)
                                    or (mm == 5) and (dd == 1 or dd == 9) or (mm == 6) and (dd == 12)
                                    or (mm == 11) and (dd == 4))
                                    SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                if (dd <= maxm[mm - 1])
                                    cout << dd << setw(4);
                                else
                                    cout << "" << setw(4);
                                SetConsoleTextAttribute(handle, (WORD)7);
                            }
                        }
                        SetConsoleTextAttribute(handle, (WORD)7);
                        cout << endl;
                        i++;
                    }
                resy = 0, mm = 0, maxm[1] = 28;
            }
            if (key[1] == 'F')
            {
                if (key[2] == 'C' and key[3] == 'O' and key[4] == 'N')
                {
                    cout << "Input Year: ";
                    cin >> year;
                    if (year % 4 == 0)
                        feb = 29;
                    int maxm[12] = { 31,  feb, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };
                    if (year < 0)
                        cout << "Wrong year ):";
                    else
                    {
                        for (int m = 1; m <= 10; m = m + 3)
                        {
                            cout << "\n" << setw(24) << months[m - 1] << setw(30) << months[m] << setw(30) << months[m + 1] << "\n";
                            i = 9;
                            for (int w = 0; w < 7; w++)
                            {
                                for (int p = 0; p <= 2; p++)
                                {
                                    cout << setw(8) << weekdays[w] << setw(4);
                                    if (DayWeek(1, m + p, year) < w + 2)
                                    {
                                        for (int z = 1, s = 0; z <= 6; z++, s = s + 7)
                                        {
                                            int d = w - DayWeek(1, m + p, year) + s + 2;
                                            if ((m + p == 1) and (d == 1 or d == 2 or d == 3 or d == 4 or d == 5 or d == 6 or d == 7 or d == 8)
                                                or (m + p == 2) and (d == 23) or (m + p == 3) and (d == 8)
                                                or (m + p == 5) and (d == 1 or d == 9) or (m + p == 6) and (d == 12)
                                                or (m + p == 11) and (d == 4))
                                                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                            if (d <= maxm[m + p - 1])
                                                cout << d << setw(4);
                                            else
                                                cout << "" << setw(4);
                                            SetConsoleTextAttribute(handle, (WORD)7);
                                        }
                                    }
                                    else
                                    {
                                        cout << setw(8);
                                        for (int z = 1, s = 0; z <= 5; z++, s = s + 7)
                                        {
                                            int dd = i - DayWeek(1, m + p, year) + s;
                                            if ((m + p == 1) and (dd == 1 or dd == 2 or dd == 3 or dd == 4 or dd == 5 or dd == 6 or dd == 7 or dd == 8)
                                                or (m + p == 2) and (dd == 23) or (m + p == 3) and (dd == 8)
                                                or (m + p == 5) and (dd == 1 or dd == 9) or (m + p == 6) and (dd == 12)
                                                or (m + p == 11) and (dd == 4))
                                                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                            if (dd <= maxm[m + p - 1])
                                                cout << dd << setw(4);
                                            else
                                                cout << "" << setw(4);
                                            SetConsoleTextAttribute(handle, (WORD)7);

                                        }
                                    }
                                    SetConsoleTextAttribute(handle, (WORD)7);
                                }
                                cout << endl;
                                i++;
                            }
                            cout << "Gotovo"<< endl;
                        }
                    }
                }
                else
                {
                    char filename[18] = "\0";
                    for (int b = 0; b < 18; b++)
                    {
                        filename[b] = key[b + 2];
                    }
                    ofstream kalendarik;
                    kalendarik.open(filename);
                    cout << "Input year: ";
                    cin >> year;
                    if (year % 4 == 0)
                        maxm[1] = 29;
                    if (year < 0)
                        cout << "Wrong year ):";
                    else
                    {
                        kalendarik << setw(48) << year << " Year" << endl;
                        for (int m = 1; m <= 10; m = m + 3)
                        {
                            kalendarik << "\n" << setw(24) << months[m - 1] << setw(30) << months[m] << setw(30) << months[m + 1] << "\n";
                            i = 9;
                            for (int w = 0; w < 7; w++)
                            {
                                for (int p = 0; p <= 2; p++)
                                {
                                    kalendarik << setw(8) << weekdays[w] << setw(4);
                                    if (DayWeek(1, m + p, year) < w + 2)
                                    {
                                        for (int z = 1, s = 0; z <= 6; z++, s = s + 7)
                                        {
                                            int d = w - DayWeek(1, m + p, year) + s + 2;
                                            if ((m + p == 1) and (d == 1 or d == 2 or d == 3 or d == 4 or d == 5 or d == 6 or d == 7 or d == 8)
                                                or (m + p == 2) and (d == 23) or (m + p == 3) and (d == 8)
                                                or (m + p == 5) and (d == 1 or d == 9) or (m + p == 6) and (d == 12)
                                                or (m + p == 11) and (d == 4))
                                                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                            if (d <= maxm[m + p - 1])
                                                kalendarik << d << setw(4);
                                            else
                                                kalendarik << "" << setw(4);
                                            SetConsoleTextAttribute(handle, (WORD)7);
                                        }
                                    }
                                    else
                                    {
                                        kalendarik << setw(8);
                                        for (int z = 1, s = 0; z <= 5; z++, s = s + 7)
                                        {
                                            int dd = i - DayWeek(1, m + p, year) + s;
                                            if ((m + p == 1) and (dd == 1 or dd == 2 or dd == 3 or dd == 4 or dd == 5 or dd == 6 or dd == 7 or dd == 8)
                                                or (m + p == 2) and (dd == 23) or (m + p == 3) and (dd == 8)
                                                or (m + p == 5) and (dd == 1 or dd == 9) or (m + p == 6) and (dd == 12)
                                                or (m + p == 11) and (dd == 4))
                                                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                                            if (dd <= maxm[m + p - 1])
                                                kalendarik << dd << setw(4);
                                            else
                                                kalendarik << "" << setw(4);
                                            SetConsoleTextAttribute(handle, (WORD)7);
                                        }
                                    }
                                    SetConsoleTextAttribute(handle, (WORD)7);
                                }
                                kalendarik << endl;
                                i++;
                            }
                            kalendarik << endl;
                        }
                        maxm[1] = 28;
                    }
                }
            }
        }
        else
            cout << "\nAbsent '/'";
    } while (key[1] != 'Q');
    return 0;
}