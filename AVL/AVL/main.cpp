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
		string str, *str2;
		getline(inputFile, str);
		istringstream iss(str);
		int i = 0;
		while (!iss.eof()) {
			//Node* newNode = new Node();
			getline(iss, str2[0], '\t');
			getline(iss, str2[1], '\t');
			getline(iss, str2[2], '\t');
			getline(iss, str2[3], '\t');
			getline(iss, str2[4], '\t');
			getline(iss, str2[5], '\t');
			getline(iss, str2[6], '\t');
			getline(iss, str2[7], '\t');
			getline(iss, str2[8], '\t');
			int sum = 0;
			int shit;
			string str3;
			for (unsigned int i = 0; i <str2[1].size(); i++) {
				str3 = str2[1];
				sum += str3[i];
			}
			shit = sum;
			/*sum = 0;
			for (unsigned int i = 0; i <str2[2].size(); i++) {
				str3 = str2[1];
				sum += str3[i];
			}
			shit[1] = sum;
			shit[2] = i + 1;*/
			tree->insert(tree->root,str2,shit);
			i++;
		}
	}
	/*while (!inputFile.eof()) {
		string str, str2;
		getline(inputFile, str);
		istringstream iss(str);
		while (!iss.eof()) {
			getline(iss, str2, '\t');
			cout << str2 << "\t";
			tree->insert(tree->root, stoi(str2));
		}
	}*/
	cout << endl << "________________________________________________________________________________" << endl;
	
	//tree->root = tree->insert(tree->root,10);
	//tree->root = tree->insert(tree->root,3);
	//tree->root = tree->insert(tree->root,7);
	
	

	cout << "In-order traversal of constructed tree is : \n";
	tree->inOrder(tree->root);
	cout << "\n\n\n";

	tree->deleteN(tree->root, 100);
	tree->deleteN(tree->root, 10);

	cout << "In-order traversal after del is : \n";
	tree->inOrder(tree->root);
	cout << "\n\n\n";

	cout << "preorder traversal of constructed tree is : \n";
	tree->preOrder(tree->root);
	cout << "\n\n\n";


	int temp;
	cout << "search for : ";
	cin >> temp;
	cout<<"value:\t"<<tree->search(temp)->key<<"\t height:\t"<<tree->search(temp)->height<<endl;

	system("pause");
}