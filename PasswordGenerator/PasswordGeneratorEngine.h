#ifndef PASSWORDGENERATORENGINE_H
#define PASSWORDGENERATORENGINE_H

namespace PasswordGeneratorEngine
{
    class PasswordGeneratorEngine
    {
    public:
        PasswordGeneratorEngine();
        
        void GeneratePassword();

        void GeneratePassword(int length, bool useLowercase, bool useUppercase, bool useNumbers, bool useSpecialCharacters);

    private:

    int m_length;
        bool m_useLowercase;
        bool m_useUppercase;
        bool m_useNumbers;
        bool m_useSpecialCharacters;

        void GeneratePassword(int length);

        



        

    };
}



#endif // PASSWORDGENERATORENGINE_H