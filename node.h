#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "string.h"
using namespace std;


class Node {
public:
	string title, surname, givenName, dateOfBirth, address, phoneNumber, emailAddress, occupation, company;
	int surnameID, givenNameID, ID;
};
#endif
