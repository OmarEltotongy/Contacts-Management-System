## Contact Management System

### Overview
This program is a console-based Contact Management System written in C++. It allows users to create, view, edit, delete, and search contacts, which are stored in memory during runtime and can be saved to a file (`contacts.txt`) upon exit. The program provides an interactive menu for performing various operations on the contact list.

### Features
- **Add New Contact**: Create a contact with first name, last name, phone number, and email address.
- **Edit Existing Contact**: Modify details of an existing contact by searching for it.
- **View All Contacts**: Display the full list of saved contacts.
- **Search Contact**: Look up a contact by phone number and optionally view its details.
- **Delete Contact**: Remove a contact from the list by index or phone number.
- **Save Contacts**: Save all contacts to `contacts.txt` upon exiting.
- **Load Contacts**: Load contacts from `contacts.txt` at program start.

### File Structure
- **PRODIGY_SD_03.cpp**: Contains all code for managing contacts, including a `Contact` class and functions to support contact operations.
- **contacts.txt**: Stores contact data persistently in a simple format for reloading contacts upon program restart.

### Key Classes and Functions

#### `Contact` Class
The `Contact` class represents each contact with attributes:
- `id`: Unique identifier.
- `first_name` and `last_name`: Contact's name.
- `phone_number`: Contact's phone number.
- `email_address`: Contact's email.

##### Class Methods
- **DisplayOneContact**: Display details of a contact based on a provided index.
- **EditExistContact**: Modify the details of an existing contact found by phone number.
- **EditNewContact**: Edit the details of a contact at a specified index in the contact list.
- **DeleteContact**: Remove a contact by index or phone number.
- **ViewAllContact**: List all contacts in the console.
- **SearchForContact**: Search for a contact by phone number.

### Utility Functions
- **phone_check**: Validates phone numbers to ensure they contain exactly 14 numeric characters.
- **retrieve_contacts**: Loads saved contacts from `contacts.txt`.

### Usage

1. Compile and run `PRODIGY_SD_03.cpp`.
2. Use the menu to perform contact operations:
   - **1**: Add a new contact
   - **2**: Edit an existing contact
   - **3**: Add info of a contact
   - **4**: Delete a contact
   - **5**: View all contacts
   - **6**: Display info of a contact
   - **7**: Search for a contact
   - **8**: Exit and save contacts

3. Upon exiting, contacts will be saved to `contacts.txt` for the next session.

### Requirements
- **C++11** or higher
- **Compiler**: Any C++ compiler (g++, clang, etc.)

### Author
Created by **Omar Eltoutongy** on Oct 26, 2024.

