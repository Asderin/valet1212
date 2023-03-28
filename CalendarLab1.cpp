#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <Windows.h>

/*/? /M /Y /F.txt*/

using namespace std;
const char DayName[7][16] = { "Pn", "Vt", "Sr",
	 "Ht", "Pt", "Sb", "Vs" };
const char MonthName[12][20] = { "January  ", "February ", "March    ","April    ",
 "May      ", "June     ", "July     ", "August   ","September" ,"October  ", "November  " ,"December" }; 
int DayWeek(int Day, int Month, int Year) {
	int DaysInYears, AllDays, DaysInMonths, Weeks, DW;
	if (Month < 3) {
		Month = Month + 12;
		Year = Year - 1;
	}
	Month = Month + 1;
	DaysInMonths = Month * 30.6;
	DaysInYears = Year * 365.25;
	AllDays = DaysInMonths + DaysInYears + Day - 114;
	Weeks = AllDays / 7;
	DW = AllDays - Weeks * 7;
	return DW;
}
int main(int narg, char* arg[])

{	
	int A[7][6] = { 0 }, day = 1, M = -1, Y = -1, DinM, n, temp = 0, k = 0, cikl = 0, term = 0, type = 1, l = 0, overtime = 0;
	bool yearm=false,yeary=false;
	char FileNameOut[16] = { '\0' };
	for (int i = 1; i < narg; i++)
	{
		if (arg[i][0] == '/')
		{
			switch (arg[i][1])
			{
			case 'M':
			{
				string Month = arg[i];
				Month.erase(0, 2);
				M = atoi(Month.c_str());
				if (M < 1 || M>12 || M == 0)
				{
					cout << "Incorrect month parameter, enter the month again: " << endl;
					cin >> M;
					yearm=true;
				}
				break;
			}
			case 'Y':
			{
				string Year = arg[i];
				Year.erase(0, 2);
				Y = atoi(Year.c_str());
				if (Y < 0 || Y == 0)
				{
					cout << "Incorrect year parameter, enter the year again: " << endl;
					cin >> Y;
					yeary=true;
				}
				break;
			}
			case 'F':
			{
				
				for (int j = 2; arg[i][j] != '\0'; j++)
				{
					FileNameOut[j - 2] = arg[i][j];
				}
				break;
			}
			case '?':
				cout << "\n\nThis program displays a calendar for the year," << endl << " starting from any month of this year and ending next year." << endl;
				cout << "To work with the program, you must enter the following parameters in the command line: " << endl << "/M(number)- month, " << endl << "/Y(number)-year, " << endl << "/F(filename)-the name of the file, the extension where the calendar will fit." << endl;
				cout << " Autor: Anatoly Filippov"<<endl;
				break;
			default: break;
			}
		}
	}
	if ((M < 1 || M>12 || M == 0) && 	yearm==true)
	{
		return 3;
	}
	else if (M==-1 && yearm==false)
	{
	cout << "Input month (1-12):  ";
		cin >> M;}
	if ((Y < 0 || Y == 0) && yeary==true )
	{
return 3;
	}
	else if ( Y==-1 && yeary==false)
	{
		cout << "Input Year (1-...): ";
		cin >> Y;
	}
	if (M > 1)
{
if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
cout << setw(47) << "Calendar on: " << Y << "/" << Y + 1 << " years("<< Y <<" - leap year)." << '\n' << '\n';
		else
			cout << setw(47) << "Calendar for: " << Y << "/" << Y + 1 << " years." <<'\n' <<'\n';
}
else
{
if ((Y % 4 == 0 && Y% 100 != 0) || (Y % 400 == 0))
cout << setw(47) << "Calendar for: " << Y << " leap year." << '\n' <<'\n';
		else
			cout << setw(47) << "Calendar for: " << Y << " years." <<'\n' << '\n';
}
	int contrM = M, contrY = Y;
	while (cikl != 3)
{
int M2 = M, M4 = M;
int Y2 = Y;
		while (term != 4)
{
cout << setw(10 + l * 2) << M << "." << MonthName[M - 1];
			l++;
			M++;
			if (M > 12)
			{
				M = M % 12;
			}
			term++;
		}
		M = M2;
		term = 0;
		l = 0;
		cout << endl;
		int tmp;
		while (overtime != 4)//17-ЫЙ ПУНКТ четность учебных недель (весь цикл)
		{
			if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) DinM = 31;
			else if (M == 4 || M == 6 || M == 9 || M == 11) DinM = 30;
			else if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0)) DinM = 29;//учёт високосного года
			else DinM = 28;
			if (M == 2 || M == 3 || M == 4 || M == 5 || M == 9 || M == 10 || M == 11 || M == 12)
			{
				if (M == 2)

					cout << setw(12) << "*" << setw(3) << "**" << setw(3) << "*" << setw(3) << "**" << "   ";

				else if (M == 9 || (M == 12 && DayWeek(1, M - 1, Y) != 5 && DayWeek(1, M - 1, Y) != 0 && DayWeek(1, M - 1, Y) != 6 && DayWeek(1, M - 1, Y) != 4 && DayWeek(1, M - 1, Y) != 3 && DayWeek(1, M - 1, Y) != 2 && DayWeek(1, M - 1, Y) != 1) || (M == 11 && DayWeek(1, M - 1, Y) != 0 && DayWeek(1, M - 1, Y) != 6 && DayWeek(1, M - 1, Y) != 1 && DayWeek(1, M - 1, Y) != 2 && DayWeek(1, M - 1, Y) != 5) || (M == 10 && (DayWeek(1, M - 1, Y) != 6 && DayWeek(1, M - 1, Y) != 0)) || (M == 3 && tmp == 34) || (M == 4 && (DayWeek(1, M - 1, Y) == 5 || DayWeek(1, M - 1, Y) == 6 || DayWeek(1, M - 1, Y) == 0)) || (M == 5 && (DayWeek(1, M - 1, Y) == 6 || DayWeek(1, M - 1, Y) == 0 || DayWeek(1, M - 1, Y) == 1 || DayWeek(1, M - 1, Y) == 2 || DayWeek(1, M - 1, Y) == 3)))

					cout << setw(9) << "*" << setw(3) << "**" << setw(3) << "*" << setw(3) << "**" << setw(3) << "*" << "   ";

				else

					cout << setw(9) << "**" << setw(3) << "*" << setw(3) << "**" << setw(3) << "*" << setw(3) << "**" << "   ";
			}

			if (M == 2 || M == 3 || M == 4 || M == 5 || M == 9 || M == 10 || M == 11 || M == 12)
			{
				tmp = DinM;
			}
			if (M == 1 || M == 6 || M == 7 || M == 8)
				cout << "                        ";
			M++;
			if (M > 12)
			{
				M = M % 12;
				Y++;
			}
			overtime++;
		}
		overtime = 0;
		cout << endl;
		M = M4;
		Y = Y2;
		while (temp != 28)
		{
			if (M < M2)
			{
				Y++;
			}
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 7; j++)
					A[j][i] = 0;
			if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) DinM = 31;
			else if (M == 4 || M == 6 || M == 9 || M == 11) DinM = 30;
			else if ((Y % 4 == 0 && Y% 100 != 0) || (Y % 400 == 0)) DinM = 29;
			n = DayWeek(1, M, Y);
			if (n == 0)
			{
				n = 7;
			}
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 7 && day <= DinM; j++, day++)
				{
					if (n - 1 > 0)
					{
						j = n - 1;
						n = 1;
					}
					A[j][i] = day;
				}
			temp = temp + 1;
			cout << setw(6);
			for (int i = k; i < k + 1; i++)
{
cout << DayName[i];
				for (int j = 0; j < 6; j++)
				{
					if (A[i][j] == 0)
						cout << setw(3) << ' ';
					else
						cout << setw(3) << A[i][j];
				}
			}
			if (M < M2)
			{
				Y--;
			}
			if (temp % 4 == 0)
			{
				cout << endl;
				k++;
				M = M - 4;
				if (M == -3)
					M = 9;
				else if (M == -2)
					M = 10;
				else if (M == -1)
					M = 11;
			}
			M++;
			if (M > 12)
			{
				M = M % 12;
			}
			day = 1;
		}
		temp = 0;
		k = 0;
		cout << '\n';
		M = M + 4;
		if (M > 12)
		{
			Y++;
			M = M % 12;
		}
cikl++;
}
cout << '\n';

cikl = 0;
	M = contrM;
	Y = contrY;
	fstream outfStream;
	bool isexsist = false;
	if (FileNameOut[2] == '\0')
{
cout << "Enter the name of the file where the calendar will be placed: " << endl;
		cin >> FileNameOut;
		outfStream.open(FileNameOut, ios_base::in);
		if (outfStream)
		{
cout <<"\n File exists: \"" <<FileNameOut << "\"";
			cout << "\n Overwrite? [Yes:1 , No:0] ";
			isexsist = true;
			int userChoice = 0;
			cin >> userChoice;
			outfStream.close();
			if (!userChoice)
			{
				return 1;
			}

		}
		outfStream.open(FileNameOut, ios::out);

	}
	else
	{
		outfStream.open(FileNameOut, ios_base::in);
		if (outfStream.is_open())
		{
cout <<"\n File exists: \"" <<FileNameOut << "\"";
			cout << "\n Overwrite? [Yes:1 , No:0] \n\n";
			isexsist = true;
			int userChoice = 0;
			cin >> userChoice;
			outfStream.close();
			if (!userChoice)
			{
				return 1;
			}

		}
outfStream.open(FileNameOut, ios::out);
}
if(M > 1)
outfStream << setw(47) << "Calendar for: " << Y << "/" << Y + 1 << " years." << '\n' <<'\n';
	else
outfStream << setw(47) << "Calendar for: " << Y << " year." <<'\n' << '\n';
	while (cikl != 3)
	{
		int M3 = M, M5 = M;
		int Y1 = Y;
		while (term != 4)
		{
			outfStream << setw(10 + l * 2) << M << "." << MonthName[M - 1];
			l++;
			M++;
			if (M > 12)
			{
				M = M % 12;
			}
			term++;
		}
		M = M3;
		term = 0;
		l = 0;
		outfStream << endl;
		int tympe;
		while (overtime != 4)
		{
			if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) DinM = 31;
			else if (M == 4 || M == 6 || M == 9 || M == 11) DinM = 30;
			else if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0)) DinM = 29;
			else DinM = 28;
			if (M == 2 || M == 3 || M == 4 || M == 5 || M == 9 || M == 10 || M == 11 || M == 12)
			{
				if (M == 2)

					outfStream << setw(12) << "*" << setw(3) << "**" << setw(3) << "*" << setw(3) << "**" << "   ";

				else if (M == 9 || (M == 12) || (M == 11 && DayWeek(1, M - 1, Y) != 0 && DayWeek(1, M - 1, Y) != 6 && DayWeek(1, M - 1, Y) != 1 && DayWeek(1, M - 1, Y) != 2 && DayWeek(1, M - 1, Y) != 5) || (M == 10 && (DayWeek(1, M - 1, Y) != 6 && DayWeek(1, M - 1, Y) != 0)) || (M == 3 && tympe == 34) || (M == 4 && (DayWeek(1, M - 1, Y) == 5 || DayWeek(1, M - 1, Y) == 6 || DayWeek(1, M - 1, Y) == 0)) || (M == 5 && (DayWeek(1, M - 1, Y) == 6 || DayWeek(1, M - 1, Y) == 0 || DayWeek(1, M - 1, Y) == 1 || DayWeek(1, M - 1, Y) == 2 || DayWeek(1, M - 1, Y) == 3)))

					outfStream << setw(9) << "*" << setw(3) << "**" << setw(3) << "*" << setw(3) << "**" << setw(3) << "*" << "   ";

				else

					outfStream << setw(9) << "**" << setw(3) << "*" << setw(3) << "**" << setw(3) << "*" << setw(3) << "**" << "   ";
			}

			if (M == 2 || M == 3 || M == 4 || M == 5 || M == 9 || M == 10 || M == 11 || M == 12)
			{
				tympe = DinM;
			}
			if (M == 1 || M == 6 || M == 7 || M == 8)
				outfStream << "                        ";
			M++;
			if (M > 12)
			{
				M = M % 12;
				Y++;
			}
			overtime++;
		}
		overtime = 0;
		outfStream << endl;
		M = M5;
		Y = Y1;
		while (temp != 28)
		{
			if (M < M3)
			{
				Y++;
			}
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 7; j++)
					A[j][i] = 0;
			if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) DinM = 31;
			else if (M == 4 || M == 6 || M == 9 || M == 11) DinM = 30;
			else if ((Y % 4 == 0 && Y% 100 != 0) || (Y % 400 == 0)) DinM = 29;
			else DinM = 28;
			n = DayWeek(1, M, Y);
			if (n == 0)
			{
				n = 7;
			}
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 7 && day <= DinM; j++, day++)
				{
					if (n - 1 > 0)
					{
						j = n - 1;
						n = 1;
					}
					A[j][i] = day;
				}
			temp = temp + 1;
			outfStream << setw(6);
			for (int i = k; i < k + 1; i++)
			{
				outfStream << DayName[i];
				for (int j = 0; j < 6; j++)
				{
					if (A[i][j] == 0)
						outfStream << setw(3) << ' ';
					else
						outfStream << setw(3) << A[i][j];
				}
			}
			if (M < M3)
			{
				Y--;
			}
			if (temp % 4 == 0)
			{
				outfStream << endl;
				k++;
				M = M - 4;
				if (M == -3)
					M = 9;
				else if (M == -2)
					M = 10;
				else if (M == -1)
					M = 11;
			}
			M++;
			if (M > 12)
			{
				M = M % 12;
			}
			day = 1;
		}
		temp = 0;
		k = 0;
		outfStream << '\n';
		M = M + 4;
		if (M > 12)
		{
			Y++;
			M = M % 12;
		}
		cikl++;
	}
	outfStream << '\n';
	outfStream << '\n';
	outfStream.close();
if (isexsist)
cout << "The file is overwritten.\n\n";
	else
		cout << "The file has been created.\n\n";
	return 0;
}

