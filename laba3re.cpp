#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main ()
{
	float MulF, X;
	int I, N;
	cout << "Specify the argument and the number of multipliers: ";
	cin >> X >> N;
	MulF = 1;
	for (I = 1; I <= N; I++) {
		cout << "\nI="<<I<<" I*X="<<I*X;
		MulF = MulF * cos(I*X);
	}
	cout << "\nComposition cos(i*x)=" << MulF;
	//По бесконечному ряду:
	float SumR, AddR, X_R, Eps;
	int N_R;
	cout << "\nEnter the error: ";
	cin >> Eps;
	MulF = 1;
	for (I = 1; I < N+1; I++) {
		X_R = X*I;
 		SumR = 0; AddR = 1; N_R = 0;
 		do {
 			SumR = SumR+AddR;
 			AddR = AddR*(-1)*(pow(X_R,2) / ((N_R + 1)*(N_R +2)));
			N_R = N_R+2;
		} while (abs(AddR/SumR) >= Eps);
		cout << "\nNumber of terms=" << N_R / 2<< " for the argument X_R=" << X_R;
		MulF = MulF*SumR;
	}
	cout << "\nA product through an infinite series= " << MulF << endl;
	cin.get();
	return 0;
} 

