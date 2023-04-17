#include <iostream>
#include <iomanip>
using namespace std;

typedef bool * Arr4Ptr[4];
Arr4Ptr* Arr3Ptr[3];

float Val; 
int Row, Col;
void OutArr(); 

int main() {
    cout << "Default structure contents\n" << endl;
    OutArr();
	
	cout << "\nStructure creation and data entry\n";
 	cout << "Enter real values:\n";
    for (Row=0; Row<3; Row=Row+1){
		cout << setw(3) << "Row " << Row << ": ";
		Arr3Ptr[Row] = new Arr4Ptr [1];
		for (Col=0; Col<4; Col=Col+1)
			if (Row==1 && Col==1|| Col==3) 
				(*Arr3Ptr[Row])[Col] = nullptr;
			else { 
				(*Arr3Ptr[Row])[Col] = new bool;
				cin >> Val;
				*(*Arr3Ptr[Row])[Col] = Val;
			};
		};
	
	cout << "\nMemory contents after creation"
 		<< " structure and data entry\n";
    OutArr();

	cout << "\nEnter the component [1][1]: ";
	
	(*Arr3Ptr[1])[1] = new bool;
    cin >> Val;
    *(*Arr3Ptr[1])[1] = Val;
    
	cout << "Memory contents after adding"
 		<< " component\n"; 
    OutArr();
	
	cout << "\nRemoving the component [0][0]\n";
    delete (*Arr3Ptr[0])[0];

    (*Arr3Ptr[0])[0] = nullptr;
	
	cout << "Memory contents after deletion "
 		<< "componenta\n"; 
    OutArr();
	
	cout << "\nChange component [2][0] \n";
	cout << "Enter a new value:";
    cin >> Val;
    *(*Arr3Ptr[2])[0] = Val;
	
	cout << "\nMemory contents after modification"
 		<< " componenta\n"; 
    OutArr();

    for (Row = 0; Row < 3; Row++)
        if (Arr3Ptr[Row] != nullptr) {
            for (Col = 0; Col < 4; Col++)
                if ((*Arr3Ptr[Row])[Col] != nullptr) {
                    delete (*Arr3Ptr[Row])[Col];
                    (*Arr3Ptr[Row])[Col] = nullptr;
                }
            delete [] Arr3Ptr[Row];
            Arr3Ptr[Row] = nullptr; 
        }
	
	cout << "\nConclusion to check - is everything released?\n";
    OutArr();

    cin.get();
    return 0;
}

void OutArr() {
    char Row, Col;
    for (Col = 0; Col < 4; Col++)
        cout << setw(12) << int(Col);
    cout << endl;

    for (Row = 0; Row < 3; Row++) {
        cout << setw(3) << int(Row); 
        if (Arr3Ptr[Row] == nullptr)
            cout << setw(15) << "empty" << setw(20) << "line";
        else
            for (Col = 0; Col < 4; Col += 1)
                if ((*Arr3Ptr[Row])[Col] == nullptr)
                    cout << setw(12) << "null"; 
 				else
 					cout << setw(12)<< *(*Arr3Ptr[Row])[Col];
 		cout << endl;
 	};
 	return;
}