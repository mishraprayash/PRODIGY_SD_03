#include <iostream>
#include <string>
#include <fstream>
class Contact
{
private:
    std::string firstName, lastName, email;
    bool isFound;
    long long phoneNumber;

public:
    Contact()
    {
        isFound = false;
    }
    void createContact()
    {
        std::cout << "\t\tEnter your Firstname: ";
        std::cin >> firstName;

        std::cout << "\t\tEnter your Lastname: ";
        std::cin >> lastName;

        std::cout << "\t\tEnter your email: ";
        std::cin >> email;

        std::cout << "\t\tEnter your phoneNumber: ";
        std::cin >> phoneNumber;

        if (firstName.empty() || lastName.empty() || email.empty() || !phoneNumber)
        {
            std::cout << "Please all the inputs" << std::endl;
            return;
        }
        // opeing a file for writing operation
        std::fstream outFile("user.dat", std::ios_base::out | std::ios_base::app);
        if(!outFile){
            std::cout<<"\n\t\tError Opening File"<<std::endl;
        }
        outFile << firstName << " " << lastName << " " << email << " " << phoneNumber << std::endl;
        outFile.close();
    }
    void viewContacts()
    {
        std::ifstream inFile("user.dat");
        std::string allcontacts;
        std::cout << "\n\n----------------All Contacts----------------" << std::endl;
        while (!inFile.eof())
        {
            getline(inFile, allcontacts);
            std::cout << allcontacts << std::endl;
        }
        inFile.close();
    }
    void editContact()
    {
        long long number;
        std::cout << "\n\t\tEnter the phoneNumber of the contact you want to edit: ";
        std::cin >> number;
        std::ifstream inFile("user.dat");
        std::ofstream outFile("temp.dat");
        if (!inFile || !outFile)
        {
            std::cout << "Error Opening File" << std::endl;
            exit(EXIT_FAILURE);
        }
        Contact contact;
        while (inFile >> contact.firstName >> contact.lastName >> contact.email >> contact.phoneNumber)
        {
            if (contact.phoneNumber == number)
            {
                isFound = true;
                std::cout << "\n\t\tEnter firstname: ";
                std::cin >> contact.firstName;
                std::cout << "\t\tEnter lastname: ";
                std::cin >> contact.lastName;
                std::cout << "\t\tEnter email: ";
                std::cin >> contact.email;
                std::cout << "\t\tEnter phoneNumber: ";
                std::cin >> contact.phoneNumber;
                outFile << contact.firstName << " " << contact.lastName << " " << contact.email << " " << contact.phoneNumber << std::endl;
            }
            else
            {
                outFile << contact.firstName << " " << contact.lastName << " " << contact.email << " " << contact.phoneNumber << std::endl;
            }
        }
        if (!isFound)
        {
            std::cout << "\n\t\tContact Doesnot Exist" << std::endl;
        }
        isFound = false;
        inFile.close();
        outFile.close();
        remove("user.dat");
        rename("temp.dat", "user.dat");
    }
    void deleteContact()
    {
        long long number;
        std::cout << "\n\t\tEnter the phoneNumber of the contact you want to delete: ";
        std::cin >> number;
        std::ifstream inFile("user.dat");
        std::ofstream outFile("temp.dat");
        if (!inFile || !outFile)
        {
            std::cout << "Error Opening File" << std::endl;
            exit(EXIT_FAILURE);
        }
        Contact contact;
        while (inFile >> contact.firstName >> contact.lastName >> contact.email >> contact.phoneNumber)
        {
            if (contact.phoneNumber == number)
            {
                isFound = true;
            }
            else
            {
                outFile << contact.firstName << " " << contact.lastName << " " << contact.email << " " << contact.phoneNumber<<std::endl;
            }
        }
        if (!isFound)
        {
            std::cout << "\n\t\tContact Not Found" << std::endl;
        }
        isFound = false;
        inFile.close();
        outFile.close();
        remove("user.dat");
        rename("temp.dat", "user.dat");
    }
};
