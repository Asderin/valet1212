#include <iostream>
#include <fstream>
using namespace std;
const int LPG = 10, LSTR = 80, NLEN = 20;
ifstream Prg;
ofstream List;
char Name[NLEN], Chr;
int I, Len, NoExist = 0, NextChar;
int main()
{
	setlocale(LC_ALL, "rus");
	List.open("PRN1.txt");
	do {
		cout << "\nInput file name ";
		cin >> Name;
		Prg.open(Name);
		if (Prg) {
			while (Prg.get(Chr)) {
				for (I = 1; I <= LPG; I++) {
					NextChar = Prg.peek();
					if (NextChar == EOF) {
						cout << "\nLast page - not full \n";
						I = LPG;
					}
					else
						do {
							List << Chr;
							Prg.get(Chr);
						} 
						while (Chr != '\n' && !Prg.eof());
				}
			}
			cout << "END OF SINGLE FILE OUTPUT";
		}
		else NoExist = 1;
		Prg.close();
	} 
	while (!NoExist);
	List.close();
	return 0;
}
