#include "PasswordGeneratorEngine.h"    
#include <iostream>
#include <string>
#include <vector>
#include <random>


namespace PasswordGeneratorEngine
{
    PasswordGeneratorEngine::PasswordGeneratorEngine()
    {
    }

    void PasswordGeneratorEngine::GeneratePassword()
    {
        GeneratePassword(8, true, true, true, true);
    }

    void PasswordGeneratorEngine::GeneratePassword(int length)
    {
        GeneratePassword(length, true, true, true, true);
    }

    void PasswordGeneratorEngine::GeneratePassword(int length, bool useLowercase, bool useUppercase, bool useNumbers, bool useSpecialCharacters)
    {
        std::string password = "";
        std::vector<char> characters;

        if (useLowercase)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                characters.push_back(c);
            }
        }

        if (useUppercase)
        {
            for (char c = 'A'; c <= 'Z'; c++)
            {
                characters.push_back(c);
            }
        }

        if (useNumbers)
        {
            for (char c = '0'; c <= '9'; c++)
            {
                characters.push_back(c);
            }
        }

        if (useSpecialCharacters)
        {
            for (char c = '!'; c <= '/'; c++)
            {
                characters.push_back(c);
            }

            for (char c = ':'; c <= '@'; c++)
            {
                characters.push_back(c);
            }

            for (char c = '['; c <= '`'; c++)
            {
                characters.push_back(c);
            }

            for (char c = '{'; c <= '~'; c++)
            {
                characters.push_back(c);
            }
        }

        std::random_device rd;//Cette ligne génère un nombre aléatoire pour le générateur de nombres pseudo-aléatoires aka la seed

        std::mt19937 gen(rd());//Cette ligne crée un générateur de nombres pseudo-aléatoires utilisant la seed

        std::uniform_int_distribution<> dis(0, characters.size() - 1);//Cette ligne crée une distribution uniforme d'entiers aka la distribution de probabilité

        for (int i = 0; i < length; i++)
        {
            password += characters[dis(gen)];
        }

        std::cout << password << std::endl;
    }
}