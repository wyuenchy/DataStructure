#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include<fstream>
#include "AVLTree.h"

using namespace std;

int main() {
	AVLTree* tree = new AVLTree();
	int sumS,sumG;

	ifstream inputFile("test2.txt");
	string data[15];

	while (!inputFile.eof()) {
		string str, str2;
		getline(inputFile, str);
		istringstream line(str);
		int i = 0;
		sumS = 0;
		sumG = 0;

		while (!line.eof()) {
			getline(line, str2, '\t');
			//cout << str2 << "\t";

			data[i] = str2;
			
			
			//insert(tree->root,unique key,tree->root->data[i])
			//tree->root=tree->insert(tree->root, stoi(str2))
			
			//cout << data[i] << "\n";
			i++;
		}

		for (int x = 0; x < data[1].size();x++) {
			sumS += data[1][x];
		}
		cout << sumS << "\t";
		
		for (int x = 0; x < data[2].size(); x++) {
			sumG += data[2][x];
		}
		cout << sumG << "\t";
		cout << endl<<endl;
		
	}

	
	cout << endl << "________________________________________________________________________________" << endl;
	

	
	
	/*
	cout << "In-order traversal of constructed tree is : \n";
	tree->inOrder(tree->root);
	cout << "\n\n\n";

	tree->root = tree->deleteN(tree->root, 100);
	tree->root = tree->deleteN(tree->root, 10);

	cout << "In-order traversal after del is : \n";
	tree->inOrder(tree->root);
	cout << "\n\n\n";*/

	system("pause");
}