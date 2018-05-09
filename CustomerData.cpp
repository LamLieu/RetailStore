#include "stdafx.h"
#include "CustomerData.h"
#include <string>
#include <iostream>
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
	PersonData(string l_name, string f_name, string address, string city, string state, int zip, int phone)
	{
		lastName = l_name;
		firstName = f_name;
	}
public:
	const string & getLastName() { return lastName; }
	const string & getFirstName() { return firstName; }
	const string & getAddress() { return address; }
	const string & getCity() { return city; }
	const string & getState() { return state; }
	const int getZip() { return zip; }
	const int getPhone() { return phone; }

	void setLastName(string l_name) {

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
	}
};

static unsigned int numberOfCustomers = 1;
class CustomerData : PersonData {
private:
	unsigned int customerNumber;
	bool mailingList = false;
public:
	CustomerData(string l_name, string f_name, string address, string city, string state, int zip, int phone)
		: PersonData(l_name, f_name, address, city, state, zip, phone) {
		customerNumber = numberOfCustomers;
		numberOfCustomers++;
	}
	void changeMailingList() {
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
			cout << "Error: You did not enter \"Y\" or \"N\"";
		}
	}
};

	class PreferredCustomer : CustomerData {
	private:
		double purchaseAmount;
		double discountLevel;
	public:
		PreferredCustomer(string l_name, string f_name, string address, string city, string state, int zip, int phone)
			: CustomerData(l_name, f_name, address, city, state, zip, phone) {
			purchaseAmount = 0;
			discountLevel = 0;
		}

		void setPlan(double purchaseAmount) {
			if (purchaseAmount >= 500) {
				discountLevel = .05;
			}
			else if (purchaseAmount >= 1000) {
				discountLevel = .06;
			}
			else if (purchaseAmount >= 1500) {
				discountLevel = .07;
			}
			else if (purchaseAmount >= 2000) {
				discountLevel = .1;
			}
		}

		void addSpending(double moneySpent) {
				purchaseAmount += moneySpent;
		}
};