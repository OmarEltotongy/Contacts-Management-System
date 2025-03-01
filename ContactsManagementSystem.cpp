/*
 * PRODIGY_SD_03.cpp
 *	Contacts Management System
 *  Created on: Oct 26, 2024
 *  Author: Omar Eltoutongy
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream> // For file input/output
#include <sstream> // For parsing the line
#include <algorithm> // For std::all_of
#include <cctype>    // For ::isdigit


using namespace std;
/*Function Protoyptes for class*/
string phone_check(string& phone);

/*Global Variables*/
string first_name;
string last_name;
string phone_number;
string email;

/*Classes*/
class Contact
{
public:
	int id;
	string first_name;
	string last_name;
	string phone_number;
	string email_address;
	static int Class_index;
	string index_str;

	/*Constructor with Intialization to creat new contact*/
	Contact() : id(Class_index), first_name("New "), last_name("Contact" + to_string(Class_index)), phone_number(string(14, '0')), email_address("new_contact@me" + to_string(Class_index)) {
		Class_index++;
	}

	Contact(string first_name, string last_name, string phone_num, string email)
		: id(Class_index), first_name{ first_name }, last_name{ last_name }, phone_number{ phone_num }, email_address{ email }
	{
		Class_index++;
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
	static bool DeleteContact(vector<Contact>& contact_list)
	{
		char answer;
		int index;
		string phone_number;
		cout << "Is the contact have info or empty? (press i for info and e for empty): ";
		while (!(cin >> answer) || (answer != 'i' && answer != 'e'))
		{
			cout << "Invalid input. Please enter 'i' or 'e'.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (answer == 'i')
		{
			cout << "Please enter a phone number to search with (included the global code): ";
			cin >> phone_number;
			cout << endl << endl;

			phone_number = phone_check(phone_number);

			int index = SearchForContact(contact_list, phone_number);

			// Check if contact was found
			if (index == -1) {
				cout << "Contact not found.\n";
				return false;
			}

			cout << endl << endl;
			contact_list.erase(contact_list.begin() + index);  // Erase element at index
			cout << "Deletion is done\n\n";

			return true;


		}
		if (answer == 'e')
		{
			cout << "Please, enter the index of the contact u want to delete.\nI will show u the list of the contacts:\n\n";
			ViewAllContact(contact_list);
			cout << endl;
			cout << "Index: ";
			cin >> index;
			cout << endl;

			if (index < 0 || index >= contact_list.size()) {
				cout << "Invalid index!" << endl;
				return false;

			}
			else
			{

				cout << endl;
				contact_list.erase(contact_list.begin() + index);  // Erase element at index
				cout << "Deletion is done\n\n";
				return true;
			}

		}


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

/*Function Protoyptes for program*/

void retrieve_contacts(vector<Contact>& contact_list);

/*Intialzation of static counter*/
int Contact::Class_index = 0;

int main()
{
	int ending_flag = 1;
	// Creating a vector to store multiple contacts
	vector<Contact> contact_list;
	int choice = 0;
	char answer;
	int add_counter = 0;
	int index = 0;


	cout << "Welcome to our Contact Management System\n\n";

	retrieve_contacts(contact_list);
	add_counter = Contact::Class_index;


	do {


		cout << "Please Enter a number from this menu:\n\n";
		cout << "1. Add a new contact\n" /*done*/
			"2. Edit an existing contact\n"
			"3. Add info of Contact\n"
			"4. Delete a contact\n"
			"5. View all contacts\n"
			"6. Display info of contact\n"
			"7. Search for a contact\n"
			"8. Exit\n";
		cout << endl;

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
			cout << endl;
			cout << "Index: ";
			cin >> index;
			cout << endl << endl;

			if (index < 0 || index >= contact_list.size()) {
				cout << "Invalid index!" << endl;
				break;
			}


			Contact::EditNewContact(contact_list, index);
			break;

		case 4: /*Delete Contact*/

			Contact::DeleteContact(contact_list);
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

			// Open a file for writing
			ofstream outfile("contacts.txt", ios::trunc);

			// Check if the file is open
			if (!outfile.is_open()) {
				cout << "Error: Could not open file for saving contacts.\n";
				break;
			}

			// Loop through the contact list and write each contact's details to the file
			for (const auto& contact : contact_list) {
				outfile << contact.id + 1 << ") Name: " << contact.first_name << " "
					<< contact.last_name << " Phone: "
					<< contact.phone_number << " Email: "
					<< contact.email_address << "\n";
			}




			// Close the file
			outfile.close();

			cout << "Contacts saved successfully!\n";
			ending_flag = 0;
			break;
		}

	} while (ending_flag != 0);
	return 0;
}


string phone_check(string& phone)
{
	while (phone.size() != 14 || !std::all_of(phone.begin(), phone.end(), ::isdigit)) {
		cout << "Please enter a valid phone number with 14 digits (global code included) and numeric only: ";
		cin >> phone;
		cout << endl;
	}
	return phone;
}

void retrieve_contacts(vector<Contact>& contact_list) {
	ifstream infile("contacts.txt");

	if (!infile.is_open()) {
		cout << "No Contacts are found\n";
		return;
	}

	string line;
	while (getline(infile, line)) {
		stringstream ss(line);

		// Variables to hold extracted values
		int id;
		string temp, first_name, last_name, phone_number, email;

		// Parse the line
		ss >> id;              // Read contact ID (1)
		ss.ignore(2);           // Ignore ") "
		ss >> temp >> first_name >> last_name;  // Read "Name: First Last"
		ss.ignore(8);           // Ignore ", Phone: "
		ss >> phone_number;     // Read phone number
		ss.ignore(8);           // Ignore ", Email: "
		ss >> email;            // Read email address

		// Add the contact to the list
		contact_list.push_back(Contact(first_name, last_name, phone_number, email));
	}

	cout << contact_list.size() << " contacts retrieved from file.\n\n";

	infile.close();
}
