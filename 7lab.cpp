#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	const int countMax = 25;
	enum Pol { Male, Female };
	enum Points { satisfactory = 3, good, excellent };
	struct TStud {
		string surname;
		Pol pol;
		Points points[6];
	};
	TStud group[countMax];
	const char PolStr[2][7] = {"Муж", "Жен"};
	const char PointsStr[3][7] = { "Уд", "Хор", "Отл" };
	int countStud, Num, vvPol, i;
	cout << " Число студентов (до " << countMax << "): ";
	cin >> countStud;
	if (countStud > countMax) countStud = countMax;
	if (countStud < 1) countStud = 1;

	for (Num = 0; Num < countStud; Num++)
	{
		cout << "Студент № " << Num + 1 << ".\n";
		cout << "Фамилия - ";
		cin >> group[Num].surname;
		cout << "Пол(Муж-0, Жен-1) - ";
		cin >> i;
		group[Num].pol = Pol(i);
		group[Num].pol = Pol(group[Num].pol & 1);
		cout << "Оценки по 6 предметам аттестата(алгебра, геометрия, рус.язык, литература, информатика, география)\n"
			<< "(Удовл.=3 Хор.=4 Отл.=5): ";
		for (int j = 0; j < 6; j++)
		{
			cin >> i;
			group[Num].points[j] = Points(i);
		}
	}
	cout << "\nСписок группы\n" << setw(3) << "Номер" << setw(10) << "Имя" << setw(15) << "Пол" << setw(10) << "Алгебра" << setw(10) << "Геометрия"
		<< setw(10) << "Рус.язык" << setw(12) << "Литература" << setw(12) << "Информатика" << setw(12) << "География\n";

	for (Num = 0; Num < countStud; Num++)
	{
		cout << setw(5) << Num + 1 << setw(10) << group[Num].surname << setw(15) << PolStr[group[Num].pol]
			<< setw(10) << PointsStr[group[Num].points[0] - 3] << setw(10) << PointsStr[group[Num].points[1] - 3]
			<< setw(10) << PointsStr[group[Num].points[2] - 3] << setw(12) << PointsStr[group[Num].points[3] - 3] << setw(12) << PointsStr[group[Num].points[4] - 3]
			<< setw(11) << PointsStr[group[Num].points[5] - 3] << "\n";
	}
		cout << "\nВыберите пол: " << "\n Мужской - 0" << "\n Женский - 1\n";
		do
		{
			cout << "Введите 0 или 1: ";
			cin >> vvPol;
		} while (!((vvPol >= 0) and (vvPol <= 1)));

		cout << "\nСписок группы\n" << setw(3) << "Номер" << setw(10) << "Имя" << setw(15) << "Пол" << setw(10) << "Алгебра" << setw(10) << "Геометрия"
			<< setw(10) << "Рус.язык" << setw(12) << "Литература" << setw(12) << "Информатика" << setw(12) << "География\n";

		for (Num = 0; Num < countStud; Num++)
		{
			bool IsGoodPoints = true; // Проверка на наличие оценки 3
			for (int i = 0; i < 6; i++)
			{
				if (group[Num].points[i] == 3)
				{
					IsGoodPoints = false;
					break; } }
			if (IsGoodPoints)
				if (group[Num].pol == vvPol)
			{
				cout << setw(5) << Num + 1 << setw(10) << group[Num].surname << setw(15) << PolStr[group[Num].pol]
					<< setw(10) << PointsStr[group[Num].points[0] - 3] << setw(10) << PointsStr[group[Num].points[1] - 3]
					<< setw(10) << PointsStr[group[Num].points[2] - 3] << setw(12) << PointsStr[group[Num].points[3] - 3] << setw(12) << PointsStr[group[Num].points[4] - 3]
					<< setw(11) << PointsStr[group[Num].points[5] - 3] << "\n";
			} } return 0;
}