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
	const char PolStr[2][4] = {"���", "���"};
	const char PointsStr[3][6] = {"�����", "���", "���"} ;
	const char LocationStr[3][14] ={"���", "���������", "������� �����"} ;
	int countStud, Num, i;
	cout << " ����� ��������� (�� " << countMax << "): ";
	cin >> countStud ;
	if (countStud>countMax) countStud=countMax;
	if (countStud<1) countStud=1;
	
	for(Num=0 ; Num<countStud ; Num++)
	{
		cout << "������� � " << Num+1 << ".\n" ;
		cout << "������� - " ;
		cin >> group[Num].surname ;
		cout << "���� ��������(�� �� ����) - " ;
		cin >> group[Num].birthday.day >> i >> group[Num].birthday.year ;
		group[Num].birthday.month = Months(i) ;
		cout << "���(���-0, ���-1) - " ;
		cin >> i ;
		group[Num].pol = Pol(i) ;
		group[Num].pol=Pol(group[Num].pol & 1);
		cout << "����� ����������(���=1, ���������=2, ������� �����=3) - " ;
		cin >> i ; group[Num].loca = Location(i) ;
		cout << "������� ���� �������� - " ;
		cin >> group[Num].middle_point ;
		cout << "������ �� 6 ��������� ���������(�������, ���������, ���.����, ����������, �����������, ���������)\n" 
			<< "(�����.=3 ���.=4 ���.=5): " ;
		for (int j=0 ; j<6 ; j++)
		{
			cin >> i ;
			group[Num].points[j] = Points(i) ;
		}
		cout << "������ ��������� - " ;
		cin >> group[Num].stip ;
	}
	cout << "\n������ ������\n"  << setw(3) << "�����" << setw(10) << "���"
	<< setw(15) << "���� ��������" << setw(5) << "���" << setw(18) << "����� ����������" 
	<< setw(11) << "����.����" << setw(11) << "���������" << setw(9) << "�������" << setw(11) 
	<< "���������" << setw(10) << "���.����" << setw(12) << "����������" << setw(13) << "�����������" 
	<< setw(11) << "���������\n" ;
	
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
		bool IsGoodPoints=true ; // �������� �� ������� ������ 3
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
		cout << "\n������ ���������, ������� ������ ���� �����������������\n"  << setw(3) << "�����" << setw(10) << "���"
		<< setw(15) << "���� ��������" << setw(5) << "���" << setw(18) << "����� ����������" 
		<< setw(11) << "����.����" << setw(11) << "���������" << setw(9) << "�������" << setw(11) 
		<< "���������" << setw(10) << "���.����" << setw(12) << "����������" << setw(13) << "�����������" 
		<< setw(11) << "���������\n" ;
		break ;
		}
		else
		{
			if(Num == countStud-1)
			cout << "��� ���������, ������� ������ ���� ����������������" ;
		}
	}
	
	for(Num=0 ; Num<countStud ; Num++)
	{
		bool IsGoodPoints=true ; // �������� �� ������� ������ 3
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
