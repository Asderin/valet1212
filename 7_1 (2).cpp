#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus") ;
	const int countMax=25;
	enum Pol {Male, Female};
	enum Location{House=1, Hostel, R_house};
	enum Months {January=1, February, March, April, May, June,
				July, August, September, October, November, December};
	enum Points {satisfactory=3 , good , excellent};
	
	struct TDate{
		int day;
		Months month;
		int year;
	};
	
	struct TStud{
		string surname;
		TDate birthday;
		Pol pol;
		Location loca;
		double middle_point ;
		Points points[6] ;
		double stip ;
	};
	TStud group[countMax];
	const char PolStr[2][4] = {"Муж", "Жен"};
	const char PointsStr[3][6] = {"Удовл", "Хор", "Отл"} ;
	const char LocationStr[3][14] ={"Дом", "Общежитие", "Съемное жилье"} ;
	int countStud, Num, i;
	cout << " Число студентов (до " << countMax << "): ";
	cin >> countStud ;
	if (countStud>countMax) countStud=countMax;
	if (countStud<1) countStud=1;
	
	for(Num=0 ; Num<countStud ; Num++)
	{
		cout << "Студент № " << Num+1 << ".\n" ;
		cout << "Фамилия - " ;
		cin >> group[Num].surname ;
		cout << "Дата рождения(ДД ММ ГГГГ) - " ;
		cin >> group[Num].birthday.day >> i >> group[Num].birthday.year ;
		group[Num].birthday.month = Months(i) ;
		cout << "Пол(Муж-0, Жен-1) - " ;
		cin >> i ;
		group[Num].pol = Pol(i) ;
		group[Num].pol=Pol(group[Num].pol & 1);
		cout << "Место жительства(дом=1, общежитие=2, съемное жилье=3) - " ;
		cin >> i ; group[Num].loca = Location(i) ;
		cout << "Средний балл аттесата - " ;
		cin >> group[Num].middle_point ;
		cout << "Оценки по 6 предметам аттестата(алгебра, геометрия, рус.язык, литература, информатика, география)\n" 
			<< "(Удовл.=3 Хор.=4 Отл.=5): " ;
		for (int j=0 ; j<6 ; j++)
		{
			cin >> i ;
			group[Num].points[j] = Points(i) ;
		}
		cout << "Размер стипендии - " ;
		cin >> group[Num].stip ;
	}
	cout << "\nСписок группы\n"  << setw(3) << "Номер" << setw(10) << "Имя"
	<< setw(15) << "Дата рождения" << setw(5) << "Пол" << setw(18) << "Место жительства" 
	<< setw(11) << "Сред.балл" << setw(11) << "Стипендия" << setw(9) << "Алгебра" << setw(11) 
	<< "Геометрия" << setw(10) << "Рус.язык" << setw(12) << "Литература" << setw(13) << "Информатика" 
	<< setw(11) << "География\n" ;
	
	for(Num=0 ; Num<countStud ; Num++)
	{
	cout << setw(5) << Num+1 << setw(10) << group[Num].surname 
	<< setw(7) << group[Num].birthday.day << '.'
	<< setw(2) << group[Num].birthday.month << '.'
	<< setw(4) << group[Num].birthday.year 
	<< setw(5) << PolStr[group[Num].pol] << setw(18) << LocationStr[group[Num].loca-1] << setw(11) << group[Num].middle_point 
	<< setw(11) << group[Num].stip << setw(9) << PointsStr[group[Num].points[0]-3] << setw(11) << PointsStr[group[Num].points[1]-3] 
	<< setw(10) << PointsStr[group[Num].points[2]-3] << setw(12) << PointsStr[group[Num].points[3]-3] << setw(13) << PointsStr[group[Num].points[4]-3] 
	<< setw(10) << PointsStr[group[Num].points[5]-3] << "\n\n" ;
	}
	
	for(Num=0 ; Num<countStud ; Num++)
	{
		bool IsGoodPoints=true ; // Проверка на наличие оценки 3
		for(int i=0; i<6; i++)
		{
			if(group[Num].points[i]==3)
			{
				IsGoodPoints=false;
				break;
			}
		}
		
		if(IsGoodPoints)
		{
		cout << "\nСписок студентов, имеющих оценки выше удовлетворительно\n"  << setw(3) << "Номер" << setw(10) << "Имя"
		<< setw(15) << "Дата рождения" << setw(5) << "Пол" << setw(18) << "Место жительства" 
		<< setw(11) << "Сред.балл" << setw(11) << "Стипендия" << setw(9) << "Алгебра" << setw(11) 
		<< "Геометрия" << setw(10) << "Рус.язык" << setw(12) << "Литература" << setw(13) << "Информатика" 
		<< setw(11) << "География\n" ;
		break ;
		}
		else
		{
			if(Num == countStud-1)
			cout << "Нет студентов, имеющих оценки выше удовлетвориельно" ;
		}
	}
	
	for(Num=0 ; Num<countStud ; Num++)
	{
		bool IsGoodPoints=true ; // Проверка на наличие оценки 3
		for(int i=0; i<6; i++)
		{
			if(group[Num].points[i]==3)
			{
				IsGoodPoints=false;
				break;
			}
		}
		
		if(IsGoodPoints)
		{
			cout << setw(5) << Num+1 << setw(10) << group[Num].surname 
			<< setw(7) << group[Num].birthday.day << '.'
			<< setw(2) << group[Num].birthday.month << '.'
			<< setw(4) << group[Num].birthday.year 
			<< setw(5) << PolStr[group[Num].pol] << setw(18) << LocationStr[group[Num].loca-1] << setw(11) << group[Num].middle_point 
			<< setw(11) << group[Num].stip << setw(9) << PointsStr[group[Num].points[0]-3] << setw(11) << PointsStr[group[Num].points[1]-3] 
			<< setw(10) << PointsStr[group[Num].points[2]-3] << setw(12) << PointsStr[group[Num].points[3]-3] << setw(13) << PointsStr[group[Num].points[4]-3] 
			<< setw(10) << PointsStr[group[Num].points[5]-3] << "\n\n" ;
		}
	}
	return 0;
}
