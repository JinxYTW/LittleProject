#include "CalculatorDisplay.h"
#include <iostream>


namespace CalculatorDisplay {
    CalculatorDisplay::CalculatorDisplay()
    {
    }

    void CalculatorDisplay::start()
    {
        std::string input;
        while (true)
        {
            input = getInput();
            if (input == "exit")
            {
                break;
            }
            double result = engine.processExpression(input);
            displayResult(result);
        }
    }

    void CalculatorDisplay::displayResult(double result)
    {
        std::cout << "Result: " << result << std::endl;
    }

    std::string CalculatorDisplay::getInput()
    {
        std::string input;
        std::cout << "Enter expression (or 'exit' to quit): ";
        std::getline(std::cin, input); //getline lit une ligne de texte à partir de l'entrée standard et l'assigne à la variable input.
        return input;
    }
}   // namespace CalculatorDisplay