//Михайлов Данила, ИВТ-42-22
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <cmath> // для round

using namespace std;

//В программе, где нужно выделить одну строку, перед её выводом вставляем:
//SetColor(6, 0); Здесь первое число - цвет текста, второе - фон. Интервал: от 0 до 16
//После вывода возвращаем обратно:
//SetColor(7, 0);
// 0-Чёрный; 1-Синий; 2-Зелёный; 3-Серый; 4-Красный; 5-Фиолетовый; 6-Тёмно-жёлтый; 7-Белый; 8-Светло-серый; 9-Тёмно-синий; 10-Салатовый;
void SetColor(int text, int background)
{
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int DayWeek(int Day, int Month, int Year) {
	int DaysInYears, AllDays, DaysInMonths, Weeks, DayWeek;
	if (Month < 3) {
		Month = Month+12;
		Year = Year-1;
	}
	Month = Month+1;
	DaysInMonths = Month*30.6;
	DaysInYears = Year*365.25;
	AllDays = DaysInMonths+DaysInYears+Day-114;
	Weeks = AllDays/7;
	DayWeek = AllDays - Weeks*7;
	
	if (DayWeek == 0) return 6;
	else return DayWeek - 1;
}

int main(int argc, char *arg[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned int holidays[] = { 101, 201, 301, 401, 501, 601, 701, 801, 2302, 803, 105, 905, 1206, 411 };
	unsigned int forSearchHoliday;
	unsigned int numMonth[3];
	const int keyLen = 30;
	int i, j, a, b, M, M1, Y, t, CountDaysM, line, column, week, column2, keyF, Answer, key;
	int massiv[7][6];
	int massivMonth[4][3][7][6] = {0};
	char SA[keyLen] = "";
	const char *NameOfWeeks[7] = {"ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС"};
	const int MaxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char FileName[keyLen] = {'\0'};
	fstream OutputFileStream; 
	keyF = -1; 
	
	const char *NameOfMonth[12] = { "Январь", "Февраль", "Март", "Апрель",
	"Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
		
	for(i = 1; i < argc; i++){
		t = 0;
		for (j = 2; j < strlen(arg[i]); j++){
			SA[t++] = arg[i][j];
		}
		
		if (arg[i][1] == 'M') M = atoi(SA);
		else if (arg[i][1] == 'Y') Y = atoi(SA);
		else if (arg[i][1] == 'F'){
			if (strcmp(SA, "CON") == 0) keyF = 1;
			else {
				keyF = 2;
				strcpy(FileName, SA);
			}					
		}
		else if (arg[i][1] == '?') keyF = 0;
		for (j = 0; j < keyLen; j++)
			SA[j] = 0; //'\0';
	}
	

	if (M*Y == 0) {
		if (keyF != 0) {
			cout << "Введите номер месяца и года (например, 1 2011) ";
			cin >> M >> Y;
		}
	}
	if (keyF != 0) {	
		if (M < 1 || M > 12) {
			keyF = -1;
			cout << "Вы неправильно ввели месяц: M = " << M << endl;
			exit(1);
		} else if(Y < 1){
			keyF = -1;
			cout << "Вы неправильно ввели год: Y = " << Y << endl;
			exit(2);
		}
	}	
	M1 = M;
	if (keyF == -1) {
		cout << "\n Параметры введены верно: \n " << M << " месяц и " << Y << " год\n";
		cout << "Выберите нужное действие: \n\n";
		cout << " 0 - вывод справки о программе" << endl;
		cout << " 1 - вывод календаря на экран" << endl;
		cout << " 2 - запись календаря в файл" << endl;	
		cout << " 3 - завершение программы" << endl;
		cin >> keyF;
		
		if(keyF == 2){			
			cout << "Введите имя файла, куда будет помещён календарь: \n";
			cin >> FileName;
		} else if (keyF == 3) exit(3);
	}
	

	b = 0;
	for(i = 1; i < 32; i++){
		a = DayWeek(i, M, Y);
		massiv[a][b] = i;
		if (a==6) b++;
	}
	

	massivMonth[0][0][0][0] = 0;
	
	for (i = 0; i < 12; i++){
		line = i / 3;
		column = i % 3;
		
		CountDaysM = MaxDay[M-1];
		if ((M == 2) && ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))) CountDaysM = 29;
		
		column2 = 0;
		for (j = 1; j <= CountDaysM; j++){
			week = DayWeek(j, M, Y);
	 		massivMonth[line][column][week][column2] = j;

			if (week==6) column2++;
	 	}
	 	

	 	M++;
	 	if (M == 13) {M = 1; Y++;}
	}
		
	cout << "\n";
	
	if (keyF == 0) {
		cout << "\nЭта программа отображает календарь на год," << endl
		<< "начиная с любого месяца данного года и заканчивая в следующем году." << endl
		<< "Для работы с программой необходимо ввести в командной строке следующие параметры: "
		<< endl << "/M(число)-месяц, " << endl << "/Y(число)-год, " << endl
		<< "/F(FileName.txt)-название файла, расширение, куда поместится календарь. " << endl
		<< "или" << endl << "/FCON - если нужно вывести календарь на экран." << endl << endl;
		SetColor(4, 0);
		cout<< "Таким цветом ";
		SetColor(7, 0);
		cout << "выделяются выходные дни." << endl << endl;
		SetColor(6, 0);
		cout<< "А таким цветом ";
		SetColor(7, 0);
		cout << "выделяются праздники." << endl;
		
	}
	
	else if (keyF == 1) {
		SetColor(7, 0);
		
		if (M1 == 1) {			
			cout << setw(35) << Y - 1 << " год" << endl;
		}
		else {
			cout << setw(35) << Y - 1 << "/" << Y << " год" << endl;
		}
	
		for (i = 0; i < 4; i++){
			for (t = 0; t < 3; t++){
				cout << setw(10) << " " << left << setw(14) << NameOfMonth[M1-1];
				numMonth[t] = M1;
				M1++;
				if (M1 == 13) M1 = 1;
			}
			
			cout << "\n";
			
			for (j = 0; j < 7; j++){		
				for (a = 0; a < 3; a++){ 
					if (j == 5 || j == 6) SetColor(4, 0);
					else SetColor(7, 0);
							
					cout << right << setw(4) << NameOfWeeks[j] << " ";
					
					for (b = 0; b < 6; b++){	
						if (massivMonth[i][a][j][b] == 0) cout << setw(3) << " ";
						else {
							forSearchHoliday = massivMonth[i][a][j][b]*100 + numMonth[a];
									
							if (count(begin(holidays), end(holidays), forSearchHoliday) > 0) SetColor(6, 0);
							else if (j == 5 || j == 6) SetColor(4, 0);
							else SetColor(7, 0);
							
							cout << setw(3) << massivMonth[i][a][j][b];
						}
					}
					
					cout << " ";
				}
				cout << endl;
			}
			SetColor(7, 0);
		} cout << endl;
	}
	
	else if (keyF == 2){
				
			OutputFileStream.open(FileName, ios::in);
			
			if (OutputFileStream){
				OutputFileStream.close();
									
				cout << "\nФайл c таким именем существует: \""
			     << FileName << "\"";
				cout << "\n Перезаписать? [Да:1 , Нет:0] ";
				cin >> Answer;
				
				if (Answer != 1) { 
					cout << "\nФайл не будет перезаписан";
					exit(3);
				}
			}			
			
			if (!OutputFileStream || Answer == 1) {
				OutputFileStream.open(FileName, ios::out);
				
				if (!OutputFileStream) {
					cout << "Неверное имя файла" << endl;
					exit(4);
				}	
			}
			
			if (M1 == 1) OutputFileStream << setw(35) << Y - 1 << " год" << endl;
			else OutputFileStream << setw(35) << Y - 1 << "/" << Y << " год" << endl;
		
			for (i = 0; i < 4; i++){
				for (t = 0; t < 3; t++){
					OutputFileStream << setw(10) << " " << left << setw(14) << NameOfMonth[M1-1] ;
					
					M1++;
					if (M1 == 13) M1 = 1;
				}
				
				OutputFileStream << endl;
				
				for (j = 0; j < 7; j++){
					for (a = 0; a < 3; a++){
						OutputFileStream << right << setw(4) << NameOfWeeks[j] << " ";
						
						for (b = 0; b < 6; b++){
							if (massivMonth[i][a][j][b] == 0) OutputFileStream << setw(3) << " ";
							else OutputFileStream << setw(3) << massivMonth[i][a][j][b];
						}
						
						OutputFileStream << " ";
					}
					
					OutputFileStream << endl;
				}
				
				OutputFileStream << endl;
			}
			
			OutputFileStream.close();
		cout << "Файл " << FileName << " создан.";	
	}
		
	return 0;
}