#include <iostream>
#include <fstream>
#include <string>
#include "Contact.h"
using namespace std;

int main()
{
  int choiceNumber;
  Contact User;
  while (true)
  {
    cout << "\n\n--------------Welcome to the Contact Management System----------------\n\n" << endl;
    cout << "\t\tWhat do you like to do ?\n" << endl;
    cout << "\t\t1. Add new Contact\n" << endl;
    cout << "\t\t2. Edit exisiting Contact\n" << endl;
    cout << "\t\t3. View all Contacts\n" << endl;
    cout << "\t\t4. Delete Contact\n" << endl;
    cout << "\t\tEnter choice: ";
    cin >> choiceNumber;
    switch (choiceNumber)
    {
    case 1:
      User.createContact();
      break;
    case 2:
      User.editContact();
      break;
    case 3:
      User.viewContacts();
      break;
    case 4:
      User.deleteContact();
      break;
    default:
      cout << "Wrong Choice" << endl;
      break;
    }
  }
  return 0;
}