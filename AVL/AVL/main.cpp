#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include<fstream>
#include "AVLTree.h"

using namespace std;

int main() {
	AVLTree* tree = new AVLTree();
	
	ifstream inputFile("test.txt");

	while (!inputFile.eof()) {
		string str, str2;
		getline(inputFile, str);
		istringstream iss(str);
		while (!iss.eof()) {
			getline(iss, str2, '\t');
			cout << str2 << "\t";
			tree->root=tree->insert(tree->root, stoi(str2));
		}
	}
	cout << endl << "________________________________________________________________________________" << endl;
	
	//tree->root = tree->insert(tree->root,10);
	//tree->root = tree->insert(tree->root,3);
	//tree->root = tree->insert(tree->root,7);
	
	

	cout << "In-order traversal of constructed tree is : \n";
	tree->inOrder(tree->root);


	system("pause");
}