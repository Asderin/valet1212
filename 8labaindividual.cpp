#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(int argc, char* argv[]) {
    char answer, otvet;
    cout << "Vy hotite vipolnit programy? (1-da/0-net): ";
    cin >> answer;
    if (answer == '1') {
        char input_filename[256], output_filename[256], replace1[256], replace2[256];
        if (argc >= 5) {
            strcpy(input_filename, argv[1]);
            strcpy(output_filename, argv[2]);
            strcpy(replace1, argv[3]);
            strcpy(replace2, argv[4]); 
			} else {
            cout << "Vvedite imya vhodnogo file: ";
            cin >> input_filename;
            cout << "Vvedite imya vihodnogo file: ";
            cin >> output_filename;
        	cout << "Posledovatelbnostb symbols kotorie nyjno zamenitb: ";
        	cin >> replace1;
        	cout << "Posledovatelbnostb symbols na kotorie nyjno zamenitb posledovatelbnostb replace1: ";
        	cin >> replace2; }
        ///////////////////////	
	    ifstream input_file(input_filename);
	    if (!input_file) {
	        cout << "Error: Ne ydalos otkrit vhodnoy file" << endl;
	        return 1; }
	        
	    cout << "Vy hotite perezapisatb file? (1-da/0-net): "; 
		cin >> otvet;
		if (otvet == '1') {
	    ofstream output_file(output_filename);
	    if (!output_file) {
	        cout << "Error: Ne ydalos otkrit vihodnoy file" << endl;
	        return 1; }
	        
        ///////////////////////
        char line[256];
        cout << "\nProcess obrabotki: "  << endl;
        while (input_file.getline(line, 256)) {
            cout << "Bx:   " << line << endl;
            if (strlen(replace1) > 256) {
                cout << "Dlina stroki prevyshaet 256 symbols";
                break;
            }
            int line_len = strlen(line);
            for (int i = 0; i < line_len; i++) {
                char c = line[i];
                int index = -1;
                for (int j = 0; j < strlen(replace1); j++) {
                    if (c == replace1[j]) {
                        index = j;
                        break; } }
                if (index != -1) {
                    line[i] = replace2[index]; } }
            cout << "Bblx: " << line << endl;
            output_file << line << endl; }     
	ifstream input_file1(input_filename);
	int line_number = 0;
	cout << "\nVhodnoy file: " << endl;
	while (input_file1.getline(line, 256)) {
	    line_number++;
	    cout << line_number << ": " << line << endl; }
	ifstream output_file1(output_filename);
	int page_number = 1;
	line_number = 1;
	cout << "\nVihodnoy file: " << endl;
	while (output_file1.getline(line, 256)) {
	    if (line_number % 10 == 1) {
	    	system("pause"); 
	    	system("cls");   
            cout << "page: " << page_number++ << endl; }    
        cout << line_number << ": " << line<< endl;
        line_number++; } }
		
		else { 
		exit(1); } }
else {
	cout << "Programma otkazalas ot vipolneniya" << endl;
		return 0; }
	return 0; }