#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
public:
	int key;
	int height;
	Node* left;
	Node* right;
<<<<<<< HEAD
	string title, surname, givenName, gender, dateOfBirth;
	string	address, city, stateFull, zipCode, Country, teleCountryCode, phoneNumber, emailAddress, occupation, company;

	//constructor
	Node(string* data);


	
	int getHeight(Node* node);
	int max(int left, int right);
	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);
	
	int getBalance(Node* node);
	Node* insert(Node* node, string* data,string key);
	Node* minValueNode(Node* node);
	Node* deleteNode(Node* node);
	Node* search(string key1,string key2,Node* node);
=======
	Node(int d);
>>>>>>> 7305c7379c06ee3e5551e99221ae34d8cb22a131
};


#endif