#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node {
public:
	string key;
	int height;
	int numListNode;

	Node* left;
	Node* right;
	Node* next;

	string title, surname, givenName, gender, dateOfBirth;
	string	address, city, stateFull, zipCode, Country, teleCountryCode, phoneNumber, emailAddress, occupation, company;
	//constructor
	Node(string* data);




	int getHeight(Node* node);
	int max(int left, int right);
	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);

	int getBalance(Node* node);
	Node* insert(Node* node, string* data, string key);



	Node* minValueNode(Node* node);
	Node* deleteN(Node* node);
	Node* search(string key1, string key2, Node* node);

	void insertList(Node* node, string* data);
	Node* insertListNode(Node* node, string* data, int index);


	void deleteListNode(Node* node, string key);

	Node* findListNode(Node* head, string key);
	


};


#endif