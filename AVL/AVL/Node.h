#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node{
public:

	string key;
	int height;
	Node* left;
	Node* right;
	string title, surname, givenName, gender, dateOfBirth;
	string	address,city,stateFull,zipCode,Country,teleCountryCode, phoneNumber, emailAddress, occupation, company;
	string* data;

	//constructor
	Node(string* data);


	
	int getHeight(Node* node);
	int max(int left, int right);
	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);
	
	int getBalance(Node* node);
	Node* insert(Node* node, string* data,string key);
	
	//Node* minNode(Node* node);
	//Node* deleteN(Node* node, int key);
	Node* search(string key1,string key2,Node* node);
	//void searchShit(string key, Node* node, int i); 
	//string* addTo2d(Node* node);
};


#endif