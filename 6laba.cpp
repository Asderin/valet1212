#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{ 
	bool sign = false, is16Digit ;
	char ch ;
	long long chislo = 0 ;
	const int Len = 16 ;
	char InputString[Len] = {'\0'} ;
	int ostatok, i ;
	//Часть 1. Преобразуем строку в число.
	cout << "Enter a signed 16-digit number:" ;
	cin.get(ch) ;
	sign = (ch=='-') ;
	i=0 ;
	if(sign)
	{
		InputString[i++] = ch ;
		cin.get(ch) ;
	}
	cout << "\nConverting a number from 16 CC to 10" ;
	int zifra ;
	is16Digit = ((ch>='0' && ch<='9') || (ch>='a' && ch<='f') || (ch>='A' && ch<='F'));
	while(is16Digit)
	{
		InputString[i++] = ch ;
		if(ch>='0' && ch<='9') zifra=ch-48 ;
		if(ch>='a' && ch<='f') zifra=ch-87 ;
		if(ch>='A' && ch<='F') zifra=ch-55 ;
		chislo = chislo*16 + zifra ;
		
		cout << "\n\tSymbol - " << ch << ", Sign - " << zifra << ", Number -  " << chislo ;
		cin.get(ch) ;
		is16Digit = ((ch>='0' && ch<='9') || (ch>='a' && ch<='f') || (ch>='A' && ch<='F'));
	}
	if (sign) chislo = -chislo ;
	cout << "\nResult"
			"\n\tAt the input line 16: " << InputString 
			<< "\n\tThe output number is 10: " << chislo ;
			
			
	//Часть 2. Число преобразуем в строку.
	char OutputString[Len]{} ;
	cout <<"\n\nReverse conversion: Numbers from 10 CC to 16" ;
	cout << "\n\tThe input number:" << chislo ;
	sign = chislo<0 ;
	chislo = abs(chislo) ;
	i=0 ;
	do
	{
	ostatok = chislo%16 ;
	chislo = chislo/16 ;
	if(ostatok<=9)
		OutputString[i++] = ostatok + 48 ;
	else
		OutputString[i++] = ostatok + 55 ;
	cout << "\n\tAnother figure - " << ostatok << ", Number - " << OutputString ;
	}
	while(chislo!=0);
	if(sign) OutputString[i] = '-' ;
	for (i=0; i<strlen(OutputString)/2; i++) {
	ch=OutputString[i];
	OutputString[i]=OutputString[strlen(OutputString)-1-i];
	OutputString[strlen(OutputString)-1-i]=ch;
	}
	cout << "\nThe output line is:" << OutputString;
	return 0;
}
