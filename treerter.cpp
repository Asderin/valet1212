#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
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
	const char PolStr[4][10] = {"Male", "Female"};
	const char PointsStr[6][14] = {"udovl", "horosho", "Otl"} ;
	const char LocationStr[6][28] ={"Dom", "Obshejitie", "Rental"} ;
	int countStud, Num, VVEDITEPOL, i;
	cout << " Number of students (up to " << countMax << "): ";
	cin >> countStud ;
	if (countStud>countMax) countStud=countMax;
	if (countStud<1) countStud=1;

for(Num=0 ; Num<countStud ; Num++)
{
	cout << "Student № " << Num+1 << ".\n" ;
	cout << "Familia - " ;
	cin >> group[Num].surname ;
	cout << "Date of birth (DD MM GGGG) - " ;
	cin >> group[Num].birthday.day >> i >> group[Num].birthday.year ;
	group[Num].birthday.month = Months(i) ;
	cout << "Gen(Male-0, Fem-1) - " ;
	cin >> i ;
	group[Num].pol = Pol(i) ;
	group[Num].pol=Pol(group[Num].pol & 1);
	cout << "Mesto jitelstva (Dom=1, Obshejitie=2, Rental=3) - " ;
	cin >> i ; group[Num].loca = Location(i) ;
	cout << "Sr ball atestata - " ;
	cin >> group[Num].middle_point ;
	cout << "Grades in 6 subjects of the certificate(algebra, geometry, ruski, literatura, informatica, geography)\n" 
		<< "(udovl.=3 horosho.=4 Otl.=5): " ;
	for (int j=0 ; j<6 ; j++)
	{
		cin >> i ;
		group[Num].points[j] = Points(i) ;
	}
	cout << "Razmer stependii - " ;
	cin >> group[Num].stip ;
}
cout << "\nSpisok grupp\n"  << setw(3) << "Nomer" << setw(10) << "Name" << setw(15) << "Date of birth" << setw(5) << "Gen" << setw(18) << "Mesto jitelstva" 
<< setw(11) << "Sr ball" << setw(11) << "Stependia" << setw(9) << "algebra" << setw(11) << "geometry" << setw(10) << "ruski" << setw(12) << "literatura" 
<< setw(13) << "Иinformatica" << setw(11) << "geography\n" ;

for(Num=0 ; Num<countStud ; Num++)
{
cout << setw(5) << Num+1 << setw(10) << group[Num].surname 
<< setw(7) << group[Num].birthday.day << '.'
<< setw(2) << group[Num].birthday.month << '.'
<< setw(4) << group[Num].birthday.year 
<< setw(5) << PolStr[group[Num].pol] << setw(18) << LocationStr[group[Num].loca-1] << setw(11) << group[Num].middle_point 
<< setw(11) << group[Num].stip << setw(9) << PointsStr[group[Num].points[0]-3] << setw(11) << PointsStr[group[Num].points[1]-3] 
<< setw(10) << PointsStr[group[Num].points[2]-3] << setw(12) << PointsStr[group[Num].points[3]-3] << setw(13) << PointsStr[group[Num].points[4]-3] 
<< setw(10) << PointsStr[group[Num].points[5]-3] << "\n" ;
}

for(Num=0 ; Num<countStud ; Num++)
{ // Проверка на наличие оценки 3
	bool IsGoodPoints=true ; 
	for(int i=0; i<6; i++)
	{
		if(group[Num].points[i]==3)
		{
			IsGoodPoints=false;
			break;
		}
	}
}

// Запрос пола
cout << "\nChoose gender: " << "\n Male - 0" << "\n Female - 1\n";
do 
{
	cout << "Input 0 or 1: ";
	cin >> VVEDITEPOL;
} while (!((VVEDITEPOL >=0) and (VVEDITEPOL <=1)));
							    
cout << "\nStudents of the selected gender who have grades above satisfactory\n";
	  	cout << setw(3) << "Number" << setw(10) << "Name" << setw(15) << "Date of birth" << setw(5) << "Gender" << setw(18) << "mesto jitelstva" 
		<< setw(11) << "Sr ball" << setw(11) << "Stependia" << setw(9) << "algebra" << setw(11) 	<< "geometry" << setw(10) << "ruski"
	    << setw(12) << "literatura" << setw(13) << "informatica" << setw(11) << "geography\n" ;		
 // Проверка на наличие оценки 3
{ 	bool IsGoodPoints=true ; 
		for(int i=0; i<6; i++)
		{
			if(group[Num].points[i]==3)
			{
				IsGoodPoints=false;
				break;
			}
		}
// Вывод результата		
if (VVEDITEPOL == 0) 
	for(Num=0 ; Num<countStud ; Num++)
	{
		
		if(IsGoodPoints && group[Num].pol == 0 && VVEDITEPOL == 0)
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
		break;
	}							
if (VVEDITEPOL == 1)
	for(Num=0 ; Num<countStud ; Num++)
	{
			
		if(IsGoodPoints && group[Num].pol == 1 && VVEDITEPOL == 1)
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
	return 0; }
}


