#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include<fstream>
#include "AVLTree.h"

using namespace std;

void displayRecord(AVLTree* tree) {
	cout << "In-order traversal of constructed tree is : \n";
	tree->inOrder(tree->root);
	cout << "\n\n\n";
}

/*
void deleteRecord(AVLTree* tree) {
	int idk = 0;
	string sur, given, phone,temp;
	Node* result;
	
		cout << "search node and delete node : ";
		cin >> sur;
		cin >> given;
		cout << "\n phone : ";
		cin.ignore();
		getline(cin, phone);
		cout << endl << "________________________________________________________________________________" << endl;
		temp = sur + given;
		cout << phone << endl;
		if (tree->search(temp, phone) != NULL) {
			result = tree->search(temp, phone);
			cout << tree->search(temp, phone)->Country << "\t" << tree->search(temp, phone)->address << endl;

			tree->deleteN(tree->root);
			cout << "node deleted" << endl;
		}
		else {
			cout << "NO Match Found";
		}

		cout << "\n\n\n";
		cout << "In-order traversal of constructed tree is : \n";
		tree->inOrder(tree->root);
		cout << "\n\n\n";
	
}*/

void searchRecord(AVLTree* tree) {
	string sur, given, phone, temp;
	int idk = 0;
	while (idk < 1) {
		cout << "search for : ";
		cin >> sur;
		cin >> given;
		cout << "\n phone : ";
		cin.ignore();
		getline(cin, phone);
		cout << endl << "________________________________________________________________________________" << endl;

		temp = sur + given;
		cout << phone << endl;

		if (tree->search(temp, phone) != NULL) {
			cout << tree->search(temp, phone)->Country << "\t" << tree->search(temp, phone)->address << endl;

		}
		else {
			cout << "NO Match Found";
		}
	}
}

void insertBatch(AVLTree* tree) {
	int i, j = 0;
	string data[15];

	ifstream inputFile("test4.txt");

	while (!inputFile.eof()) {
		string str, str2;
		getline(inputFile, str);

		istringstream line(str);
		i = 0;

		while (!line.eof()) {
			getline(line, str2, '\t');

			data[i] = str2;


			i++;
		}
		j++;
		tree->insert(tree->root, data);
	}
	cout << endl << "________________________________________________________________________________" << endl;
}



int main() {
	AVLTree* tree = new AVLTree();

	insertBatch(tree);
	displayRecord(tree);
	searchRecord(tree);
	//deleteRecord(tree);


	system("pause");
}