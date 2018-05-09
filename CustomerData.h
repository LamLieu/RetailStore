#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class PersonData {
private:
	string lastName;
	string firstName;
	string streetName, streetType;
	string city;
	string state;
	string zip;
	string phone;
	string streetNumber;
	PersonData() {};
protected:
	PersonData(string l_name, string f_name, string streetName, string streetType,
		string city, string state, string streetNumber, string zip, string phone);
public:
	const string & getLastName();
	const string & getFirstName();
	const string & getAddress();
	const string & getCity();
	const string & getState();
	const string & getZip();
	const string & getPhone();

	void setLastName(string l_name);
	void setFirstName(string f_name);
	void setAddress(string streetNumber, string streetName, string streetType);
	void setCity(string city);
	void setState(string state);
	void setZip(string zip);
	void setPhone(string phone);
};

class CustomerData : public PersonData {
private:
	unsigned int customerNumber;
	bool mailingList;
public:
	CustomerData(string l_name, string f_name, string streetName, string streetType,
		string city, string state, string streetNumber, string zip, string phon);

	void changeMailingList();
};

class PreferredCustomer : public CustomerData {
private:
	double purchaseAmount;
	double discountLevel;
	double moneySpent;
public:
	PreferredCustomer(string l_name, string f_name, string streetName, string streetType,
		string city, string state, string streetNumber, string zip, string phone);

	void setPlan();
	void increasePurchaseAmount();
	void print();
};