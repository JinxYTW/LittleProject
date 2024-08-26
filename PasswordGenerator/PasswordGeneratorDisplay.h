#ifndef PASSWORDGENERATORDISPLAY_H
#define PASSWORDGENERATORDISPLAY_H

#include "PasswordGeneratorEngine.h"
#include <iostream>
#include <string>

namespace PasswordGeneratorDisplay
{
    class PasswordGeneratorDisplay
    {
    public:
        PasswordGeneratorDisplay();
        void ShowMenu();
        void DisplayPassword();
       
    private:
        PasswordGeneratorEngine::PasswordGeneratorEngine m_engine;

    };
}



#endif // PASSWORDGENERATORDISPLAY_H