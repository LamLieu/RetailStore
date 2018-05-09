#include "stdafx.h"
#include "CustomerData.h"
#include <string>
#include <iostream>
using namespace std;

PersonData::PersonData(string l_name, string f_name, string streetName, string streetType, 
	string city, string state, string streetNumber, string zip, string phone) {
	lastName = l_name;
	firstName = f_name;
	this->streetNumber = streetNumber;
	this->streetName = streetName;
	this->streetType = streetType;
	this->city = city;
	this->state = state;
	this->zip = zip;
	this->phone = phone;
}
const string & PersonData::getLastName() { return lastName; }
const string & PersonData::getFirstName() { return firstName; }
const string & PersonData::getAddress() { return streetNumber + " " + streetName + " " + streetType; }
const string & PersonData::getCity() { return city; }
const string & PersonData::getState() { return state; }
const string & PersonData::getZip() { return zip; }
const string & PersonData::getPhone() { return phone; }

void PersonData::setLastName(string l_name) {
	lastName = l_name;
}
void PersonData::setFirstName(string f_name) {
	firstName = f_name;
}
void PersonData::setAddress(string streetNumber, string streetName, string streetType) {
	this->streetNumber = streetNumber;
	this->streetName = streetName;
	this->streetType = streetType;
}
void PersonData::setCity(string city) {
	this->city = city;
}
void PersonData::setState(string state) {
	this->state = state;
}
void PersonData::setZip(string zip) {
	this->zip = zip;
}
void PersonData::setPhone(string phone) {
	this->phone = phone;
}

static unsigned int numberOfCustomers = 1;
CustomerData::CustomerData(string l_name, string f_name, string streetName, string streetType,
	string city, string state, string streetNumber, string zip, string phone)
	: PersonData(l_name, f_name, streetName, streetType, city, state, streetNumber, zip, phone) {
	customerNumber = numberOfCustomers;
	numberOfCustomers++;
}
void CustomerData::changeMailingList() {
	string userAnswer;
	cout << "Would you like to be on the mailing list? (Y/N)" << endl << "-->";
	cin >> userAnswer;
	if (userAnswer.at(0) == 'Y' || userAnswer.at(0) == 'y') {
		mailingList = true;
	}
	else if (userAnswer.at(0) == 'N' || userAnswer.at(0) == 'n') {
		mailingList = false;
	}
	else {
		cout << "Error: You did not enter \"Y\" or \"N\"" << endl;
	}
}

PreferredCustomer::PreferredCustomer(string l_name, string f_name, string streetName, string streetType,
	string city, string state, string streetNumber, string zip, string phone)
	: CustomerData(l_name, f_name, streetName, streetType, city, state, streetNumber, zip, phone) {
	purchaseAmount = 0;
	discountLevel = 0;
}

void PreferredCustomer::setPlan() {
	if (purchaseAmount >= 500) {
		discountLevel = .05;
	}
	if (purchaseAmount >= 1000) {
		discountLevel = .06;
	}
	if (purchaseAmount >= 1500) {
		discountLevel = .07;
	}
	if (purchaseAmount >= 2000) {
		discountLevel = .1;
	}
}

void PreferredCustomer::increasePurchaseAmount() {
	cout << "How much did you spend in the store?" << endl;
	cin >> moneySpent;
	purchaseAmount += moneySpent;
	setPlan();
}

void PreferredCustomer::print() {
	cout << "The total amount of money spent in the store is " << purchaseAmount << endl;
	cout << "Your discount level is " << discountLevel << endl;
}