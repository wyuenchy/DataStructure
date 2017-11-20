#include <ctime>
#include <sstream>
#include <string>
#include<iostream>
#include<fstream>
#include "BTree.h"
using namespace std;


int main() {
	BTree tree(3);
	ifstream inputFile("test.txt");

	while (!inputFile.eof()) {
		string str, str2;
		getline(inputFile, str);
		istringstream iss(str);
		while (!iss.eof()) {
			getline(iss, str2, '\t');
			cout << str2 << "\t";
			tree.insert(stoi(str2));
		}
	}
	cout << endl<<"________________________________________________________________________________"<<endl;

	

	cout << "Traversal of the constucted tree is ";
	tree.traverse();
	
	int k = 98;
	(tree.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";

	k = 100;
	(tree.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";
	system("pause");
}
