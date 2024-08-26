#include "PasswordGeneratorDisplay.h"
#include <iostream>
#include <limits>

namespace PasswordGeneratorDisplay
{
    PasswordGeneratorDisplay::PasswordGeneratorDisplay()
    {
    }

    void PasswordGeneratorDisplay::ShowMenu()
    {
        std::cout << "Password Generator" << std::endl;
        std::cout << "1. Generate Password" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Cette ligne permet de vider le buffer de cin.A faire après chaque cin pour éviter les erreurs


        switch (choice)
        {
        case 1:
            DisplayPassword();
            break;
        case 2:
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

    void PasswordGeneratorDisplay::DisplayPassword()
    {
        std::string length;
        std::string useLowercase;
        std::string useUppercase;
        std::string useNumbers;
        std::string useSpecialCharacters;

        std::cout << "Enter password length: ";
        std::getline(std::cin, length);
        std::cout << "Use lowercase letters? (y/n): ";
        std::getline(std::cin, useLowercase);
        std::cout << "Use uppercase letters? (y/n): ";
        std::getline(std::cin, useUppercase);
        std::cout << "Use numbers? (y/n): ";
        std::getline(std::cin, useNumbers);
        std::cout << "Use special characters? (y/n): ";
        std::getline(std::cin, useSpecialCharacters);

        int lengthInt = std::stoi(length); //stoi for string to int
        bool useLowercaseBool = useLowercase == "y";
        bool useUppercaseBool = useUppercase == "y";
        bool useNumbersBool = useNumbers == "y";
        bool useSpecialCharactersBool = useSpecialCharacters == "y";

        m_engine.GeneratePassword(lengthInt, useLowercaseBool, useUppercaseBool, useNumbersBool, useSpecialCharactersBool);



    }

    
}