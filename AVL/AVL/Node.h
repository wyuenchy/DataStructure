#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node{
public:
	int key;
	int height;
	string data[15];
	int ID[3];
	//string title, surname, givenName, dateOfBirth, address, phoneNumber, emailAddress, occupation, company;
	//int surnameID, givenNameID, ID;
	Node* left;
	Node* right;
	Node(int k);
	Node(int k, string* data);
};


#endif