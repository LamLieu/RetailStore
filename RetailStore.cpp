#include "stdafx.h"
#include "CustomerData.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string l_name, f_name, streetNumber, streetName, streetType, city, state, zip, phone;

	cout << "What is your first name?" << endl << "-->";
	cin >> f_name;
	cout << "What is your last name?" << endl << "-->";
	cin >> l_name;
	cout << "What is your address?" << endl << "-->";
	cin >> streetNumber >> streetName >> streetType;
	cout << "What is your city?" << endl << "-->";
	cin >> city;
	cout << "What is your state?" << endl << "-->";
	cin >> state;
	cout << "What is your zip code?" << endl << "-->";
	cin >> zip;
	cout << "What is your phone number?" << endl << "-->";
	cin >> phone;

	PreferredCustomer customer(l_name, f_name, streetName, streetType, city, state, streetNumber, zip, phone);

	customer.changeMailingList();

	customer.increasePurchaseAmount();

	customer.print();

    return 0;
}