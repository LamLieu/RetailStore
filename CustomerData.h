#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class PersonData {
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	int zip;
	int phone;
	PersonData();
protected:
	PersonData(string l_name, string f_name, string address, string city,
		string state, int zip, int phone);
public:
	const string & getLastName() { return lastName; }
	const string & getFirstName() { return firstName; }
	const string & getAddress() { return address; }
	const string & getCity() { return city; }
	const string & getState() { return state; }
	const int getZip() { return zip; }
	const int getPhone() { return phone; }

	void setLastName(string l_name) {
		lastName = l_name;
	}
	void setFirstName(string f_name) {
		firstName = f_name;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setCity(string city) {
		this->city = city;
	}
	void setState(string state) {
		this->state = state;
	}
	void setZip(int zip) {
		this->zip = zip;
	}
	void setPhone(int phone) {
		this->phone = phone;
	}
};

class CustomerData : PersonData {
private:
	unsigned int customerNumber;
	bool mailingList;
public:
	CustomerData();

	void changeMailingList();
};

class PreferredCustomer : CustomerData {
private:
	double purchaseAmount;
	double discountLevel;
public:
	PreferredCustomer();

	void setPlan(double purchaseAmount);
	void addSpending(double moneySpent);
};