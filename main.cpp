#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


double functionA(int n) {
	clock_t startTime = clock();

	//
	
	clock_t endTime = clock();
	return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

int main(){

	ifstream inputFile("Contacts for Project.txt");

	while (!inputFile.eof()) {
		string str;
		getline(inputFile, str,'\t');
		cout << str;
	}

	/*
	int N = 150000;
	cout << "Time for function A in seconds" << endl;
	cout << "------------------------------" << endl;
	cout << "n=150000,  time: " << functionA(N) << "s" << endl;
	
	cout << endl;*/

	system("pause");
}
