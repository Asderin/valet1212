#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const int n = 5;
	float a[n][n], b[n][n];
	int row, col;
	char ch;
	cout << "Enter 5 lines of 5 elements each:\n";
	col = 0;
	while (col < n)
	{
		cout << col + 1 << ": ";
		row = 0;
		while (row < n)
		{
			cin >> a[row][col];
			row++;
		}
		do
			cin.get(ch);
		while (ch != '\n');
		col++;
	}
	cout << "\nOutput of array A:\n";
	row = 0;
	for (int i = 1; i < (n + 1); i++)
		cout << setw(5) << i;
	cout << "\n";
	do
	{
		cout << row + 1 << ": ";
		col = 0;
		do
		{
			cout << setw(4) << a[row][col] << " ";
			col++;
		} while (col < n);
		cout << "\n";
		row++;
	} while (row < n);
	cin.get(ch);
	cout << "\nFilling in B: Copying from A:";
	cout << "\nRow and Elements\n";
	for (row = 2; row < n; row++)
	{
		cout << row + 1 << ": ";
		for (col=2; col<n; col++) {
			b[row][col] = a[row][col];
			cout << col << ", ";
		}
		cout << endl;
	}

	cout << "\nProcessing In: Zeroing elements:";
	cout << "\nRow and Elements\n";
	for (row = 0; row < n; row++) {
		cout << row + 1 << ": ";
		for (col=0; (row<2)? col<n: col<n-3; col++) {
			b[row][col] = 0;
			cout << col << ", ";
		}
		cout << endl;
	}
	cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint | ios::right);
	cout << "\nOutput of array B:\n";
	row = 0;
	for (int i = 1; i < (n + 1); i++)
		cout << setw(7) << i;
	cout << "\n";
	do
	{
		cout << row + 1 << ": ";
		col = 0;
		do
		{
			cout << setw(6) << b[row][col] << " ";
			col++;
		} while (col < n);
		cout << "\n";
		row++;
	} while (row < n);

}
