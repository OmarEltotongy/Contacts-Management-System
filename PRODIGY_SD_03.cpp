/*
 * PRODIGY_SD_03.cpp
 *
 *  Created on: Oct 26, 2024
 *  Author: Omar Eltoutongy
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;
/*Function Protoyptes*/
string phone_check(string& phone);

/*Global Variables*/
int ending_flag = 1;
string first_name;
string last_name;
string phone_number;
string email;


/*Classes*/
class Contact
{
public:

	string first_name = "";
	string last_name = "";
	string phone_number = "";
	string email_address = "";

	/*Constructor with Intialization to creat new contact*/
	Contact()
	{
		first_name = "New";
		last_name = "Contact";
		phone_number = "00000000000000";
		email_address = "new_contact@me";
	}
	Contact(string first_name, string last_name, string phone_num, string email)
		: first_name{ first_name }, last_name{ last_name }, phone_number{ phone_num }, email_address{ email }
	{

	}

	/*Methods*/

	/*Display contact by searching for his phone number*/
	static bool DisplayOneContact(const vector<Contact>& contact_list, const int& index)
	{
		// Check if contact was found
		if (index == -1) {
			cout << "Contact not found.\n";
			return false;
		}

		cout << "Name: " << contact_list[index].first_name << " " << contact_list[index].last_name << endl;
		cout << "Phone: " << contact_list[index].phone_number << endl;
		cout << "Email: " << contact_list[index].email_address << endl;
		cout << "Found at index: " << index << endl;
		cout << endl << endl;

		return true;

	}

	/*Edit contact by searching for his phone number and return status of update*/
	static bool EditExistContact(vector<Contact>& contact_list, const string& phone_num)
	{
		int index = SearchForContact(contact_list, phone_num);

		// Check if contact was found
		if (index == -1) {
			cout << "Contact not found.\n";
			return false;
		}

		string new_first_name = "0";
		string new_last_name = "0";
		string new_phone = "0";
		string new_email = "0";
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
			cin >> new_last_name;
			contact_list[index].last_name = new_last_name;

			cout << endl;
		}
		else if (answer == 'n')
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
			new_phone = phone_check(new_phone);
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
		cout << endl << endl;

		return true;

	}

	static bool EditNewContact(vector<Contact>& contact_list, int index)
	{
		// Check if contact was found
		if (index == -1) {
			cout << "Contact not found.\n";
			return false;
		}

		string new_first_name = "";
		string new_last_name = "";
		string new_phone = "";
		string new_email = "";
		char answer;

		cout << "Please enter the new  First Name: ";
		cin >> new_first_name;
		contact_list[index].first_name = new_first_name;
		cout << endl;
		cout << "Please enter the new  Last Name: ";
		cin >> new_last_name;
		contact_list[index].last_name = new_last_name;
		cout << endl;


		/******************************************************/

		cout << "Please enter the new  phone number: ";
		cin >> new_phone;
		new_phone = phone_check(new_phone);
		contact_list[index].phone_number = new_phone;
		cout << endl;



		/******************************************************/


		cout << "Please enter the new  Email: ";
		cin >> new_email;
		contact_list[index].email_address = new_email;
		cout << endl;

		return true;

	}

	/*Search for his phone number in contact list and return index*/
	/*pass by refrence to be faster*/
	static int SearchForContact(const vector<Contact>& contact_list, const string& phone_num)
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
	static bool DeleteContact(vector<Contact>& contact_list, string& phone_num)
	{
		int index = SearchForContact(contact_list, phone_num);

		// Check if contact was found
		if (index == -1) {
			cout << "Contact not found.\n";
			return false;
		}
		contact_list.erase(contact_list.begin() + index);  // Erase element at index
		cout << "Deletion is done\n\n";
		return true;

	}

	static void ViewAllContact(const vector<Contact>& contact_list)
	{
		if (contact_list.size() == 0)
		{
			cout << "The countiner is empty\n\n";
		}
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
	int choice = 0;
	char answer;
	int add_counter = 0;
	int index = 0;


	cout << "Welcome to our Contact Management System\n\n";
	/*TODO: Retreiveing elements from text file*/
	do {


		cout << "Please Enter a number from this menu:\n";
		cout << "1. Add a new contact\n" /*done*/
			"2. Edit an existing contact\n"
			"3. Add info of Contact\n"
			"4. Delete a contact\n"
			"5. View all contacts\n"
			"6. Display info of contact\n"
			"7. Search for a contact\n"
			"8. Exit\n";
		cout << endl << endl;

		cin >> choice;

		// Check while input is invalid (choice not in 1-8 or input fails)
		while (cin.fail() || choice < 1 || choice > 8) {
			cin.clear(); // Clear the error flag set by cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Invalid choice! Please enter a number between 1 and 8: ";
			cin >> choice;
			cout << endl;
		}
		switch (choice) {
		case 1:/*Add a new contact*/
			cout << "Do u want to add his info now (y/n): ";
			cin >> answer;
			cout << endl << endl;
			while (cin.fail() || (answer != 'y' && answer != 'n'))
			{
				cout << "Invalid input. Please enter 'y' or 'n'.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (tolower(answer) == 'y')
			{
				cout << "You chose to add info.\n\n";
				cout << "Please enter a first name: ";
				cin >> first_name;
				cout << endl;

				cout << "Please enter a last name: ";
				cin >> last_name;
				cout << endl;

				cout << "Please enter a phone number to search with (included the global code): ";
				cin >> phone_number;
				phone_number = phone_check(phone_number);
				cout << endl;

				cout << "Please enter an email address: ";
				cin >> email;
				cout << endl;

				/*Creating object*/
				contact_list.push_back(Contact(first_name, last_name, phone_number, email));
				add_counter++;
				cout << "Counter ++ is done. Counter is: " << add_counter << endl;
			}
			else {
				cout << "You chose not to add info. U will be able to edit the contact in edit section\n";
				contact_list.push_back(Contact());
				add_counter++;

			}
			break;

		case 2: /*Edit Existing Contact*/
			cout << "Please enter a phone number to search with (included the global code):";
			cin >> phone_number;
			phone_number = phone_check(phone_number);
			cout << endl;
			Contact::EditExistContact(contact_list, phone_number);
			break;

		case 3: /*Add info of Contact*/
			cout << "Please, enter the index of the contact u want to edit.\nI will show u the list of the contacts:\n\n";
			Contact::ViewAllContact(contact_list);
			cout << endl << endl;
			cin >> index;
			cout << endl << endl;

			Contact::EditNewContact(contact_list, index);
			break;

		case 4: /*Delete Contact*/
			cout << "Please enter a phone number to search with (included the global code): ";
			cin >> phone_number;
			cout << endl << endl;

			phone_number = phone_check(phone_number);
			Contact::DeleteContact(contact_list, phone_number);
			add_counter--;

			break;
		case 5: /*View all Contacts*/
			Contact::ViewAllContact(contact_list);
			cout << endl << endl;
			break;

		case 6: /*Display info of contact*/
			cout << "Please enter a phone number to search with (included the global code): ";
			cin >> phone_number;
			cout << endl << endl;

			phone_number = phone_check(phone_number);
			index = Contact::SearchForContact(contact_list, phone_number);

			Contact::DisplayOneContact(contact_list, index);
			break;

		case 7: /*Search on Contact*/
			cout << "Please enter a phone number to search with (included the global code): ";

			cin >> phone_number;
			cout << endl << endl;

			phone_number = phone_check(phone_number);

			index = Contact::SearchForContact(contact_list, phone_number);
			if (index == -1)
				cout << "Contact is not Found\n\n";
			else
			{
				cout << "Contact is found at index: " << index << endl << endl;
				cout << "Do u wanna show its info? (y/n): ";
				cin >> answer;
				cout << endl << endl;
				while (cin.fail() || (answer != 'y' && answer != 'n'))
				{
					cout << "Invalid input. Please enter 'y' or 'n'.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (tolower(answer) == 'y')
				{
					Contact::DisplayOneContact(contact_list, index);
					cout << endl << endl;

				}
				else
				{
					/*Do nothing*/
					cout << "OKAY! \n\n";
				}

			}
			break;

		case 8: /*Exit*/
			cout << "Good luck, see u soon\n\n";
			/*TODO: Storing elements in text file*/

			ending_flag = 0;
			break;
		}

	} while (ending_flag != 0);
	return 0;
}


string phone_check(string& phone)
{
	if (phone.size() == 14)
	{
		return phone;
	}
	else
	{
		while (phone.size() != 14)
		{
			cout << "Please enter a valid phone number with 14 digit (global code included): ";
			cin >> phone;
			cout << endl;
		}
		return phone;
	}
}
