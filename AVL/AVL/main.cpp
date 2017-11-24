#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include<fstream>
#include "AVLTree.h"

using namespace std;

int main() {
	AVLTree* tree = new AVLTree();
<<<<<<< HEAD
	int i;
	string data[15];

	ifstream inputFile("test2.txt");
=======
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131
	
	ifstream inputFile("test.txt");

	while (!inputFile.eof()) {
		string str, str2;
		getline(inputFile, str);
<<<<<<< HEAD
		istringstream line(str);
		i = 0;
		/*
		for(int i =0; i < str.size();i++){
			if(
			str2 = str[i];


		}
		*/
		while (!line.eof()) {
			getline(line, str2, '\t');
			if (get(str2) == '\t') {

			}
			data[i] = str2;

	
			i++;
=======
		istringstream iss(str);
		while (!iss.eof()) {
			getline(iss, str2, '\t');
			cout << str2 << "\t";
			tree->root=tree->insert(tree->root, stoi(str2));
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131
		}
	}
	cout << endl << "________________________________________________________________________________" << endl;
	
	//tree->root = tree->insert(tree->root,10);
	//tree->root = tree->insert(tree->root,3);
	//tree->root = tree->insert(tree->root,7);
	
	

	cout << "In-order traversal of constructed tree is : \n";
	tree->inOrder(tree->root);
	cout << "\n\n\n";

	tree->root = tree->deleteN(tree->root, 100);
	tree->root = tree->deleteN(tree->root, 10);

	cout << "In-order traversal after del is : \n";
	tree->inOrder(tree->root);
	cout << "\n\n\n";

<<<<<<< HEAD

	string sur, given,phone, temp;
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
	
	
		if (tree->search(temp, phone) != NULL) {
			cout << tree->search(temp, phone)->Country << "\t" << tree->search(temp, phone)->address<< endl;
		}
		else {
			cout << "NO Match Found";
		}
	}
	
	
		
	
	
	
=======
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131
	system("pause");
}