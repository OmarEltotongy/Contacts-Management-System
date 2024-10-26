/*
 * PRODIGY_SD_03.cpp
 *
 *  Created on: Oct 26, 2024
 *  Author: Omar Eltoutongy
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Global Variables*/

/*Classes*/
class Contact
{
public :
	string first_name = "";
	string last_name = "";
	string phone_number = "";
	string email_address = "";

	/*Constructor with Intialization to creat new contact*/
	Contact()
	{
		first_name = "New";
		last_name = "Contact";
		phone_number = "000";
		email_address = "new_contact@me";
	}
	Contact(string first_name, string last_name, string phone_num, string email)
		: first_name{ first_name }, last_name{ last_name }, phone_number{ phone_num }, email_address{ email }
	{

	}

	/*Methods*/

	/*Methods for defult constructor to creat new contact*/
	bool AssignName(string first, string last)
	{
		first_name = first;
		last_name = last;
		return true;
	}

	bool AssignPhone(string phone_num)
	{
		if (phone_num.size() == 14) /*Ensure exactly 14 digits*/
		{
			phone_number = phone_num;
			return true;
		}
		else
		{
			cout << "The number must be 14 digit with countery code\n";
			return false;
		}
		
	}

	bool AssignEmail(string email)
	{
		email_address = email;
		return true;

	}
	/**************************************************************************/

	/*Display contact by searching for his phone number*/
	bool DisplayOneContact(const vector<Contact>& contact_list, const string& phone_num)
	{
		int index = SearchForContact(contact_list, phone_num);
		// Check if contact was found
		if (index == -1) {
			cout << "Contact not found.\n";
			return false;
		}

		cout << "Name: " << contact_list[index].first_name << " " << contact_list[index].last_name << endl;
		cout << "Phone: " << contact_list[index].phone_number << endl;
		cout << "Email: " << contact_list[index].email_address << endl;
		
		return true;

	}

	/*Edit contact by searching for his phone number and return status of update*/
	bool EditContact( vector<Contact>& contact_list, const string& phone_num)
	{
		int index = SearchForContact( contact_list,phone_num);

		// Check if contact was found
		if (index == -1) {
			cout << "Contact not found.\n";
			return false;
		}

		string new_first_name= "";
		string new_last_name = "";
		string new_phone = "";
		string new_email = "";
		char answer;

		cout << "Do u want change name? (y/n): ";
		while (!(cin >> answer) || (answer != 'y' && answer != 'n'))
		{
			cout << "Invalid input. Please enter 'y' or 'n'.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (answer == 'y')
		{
			cout << "Please enter the new  First Name: ";
			cin >> new_first_name;
			contact_list[index].first_name = new_first_name;
			cout << endl;
			cout << "Please enter the new  Last Name: ";
			cin >>  new_last_name;
			contact_list[index].last_name = new_last_name;

			cout << endl;
		}
		if (answer == 'n')
		{
			/*do nothing*/
		}

		/******************************************************/
		cout << "Do u want change phone number? (y/n): ";
		while (!(cin >> answer) || (answer != 'y' && answer != 'n'))
		{
			cout << "Invalid input. Please enter 'y' or 'n'.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (answer == 'y')
		{
			cout << "Please enter the new  phone number: ";
			cin >> new_phone;
			contact_list[index].phone_number = new_phone;
			cout << endl;

		}
		if (answer == 'n')
		{
			/*do nothing*/
		}

		/******************************************************/

		cout << "Do u want change Email? (y/n): ";
		while (!(cin >> answer) || (answer != 'y' && answer != 'n'))
		{
			cout << "Invalid input. Please enter 'y' or 'n'.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (answer == 'y')
		{
			cout << "Please enter the new  Email: ";
			cin >> new_email;
			contact_list[index].email_address = new_email;
			cout << endl;

		}
		if (answer == 'n')
		{
			/*do nothing*/
		}
		return true;

	}

	/*Search for his phone number in contact list and return index*/
	/*pass by refrence to be faster*/
	int SearchForContact(const vector<Contact>& contact_list, const string& phone_num)
	{
		// Iterate through the contact list
		for (int i = 0; i < contact_list.size(); ++i) {
			// If the phone number matches, return the index
			if (contact_list[i].phone_number == phone_num) {
				return i; // Contact found, return index
			}
		}
		return -1; // Contact not found
	}

	/*Delete contact by searching for his phone number and return with status of delete*/
	bool DeleteContact(vector<Contact>& contact_list, string& phone_num)
	{
		int index = SearchForContact(contact_list, phone_num);
		
		// Check if contact was found
		if (index == -1) {
			cout << "Contact not found.\n";
			return false;
		}
		contact_list.erase(contact_list.begin() + index);  // Erase element at index
		return true;

	}
	void ViewAllContact(const vector<Contact>& contact_list)
	{
		for (int i = 0; i < contact_list.size(); i++) {
			cout << i << ")\n" << contact_list[i].first_name << " " << contact_list[i].last_name << endl;
			cout << contact_list[i].phone_number << endl;
			cout << contact_list[i].email_address << endl;
		}
	}
	
};
int main()
{
	// Creating a vector to store multiple contacts
	vector<Contact> contact_list;
	
   return 0;
}