// CalculatorDisplay.h
#ifndef CALCULATOR_DISPLAY_H
#define CALCULATOR_DISPLAY_H

#include <string>
#include "CalculatorEngine.h"
namespace CalculatorDisplay{
class CalculatorDisplay {
public:
    CalculatorDisplay();  // Constructeur
    void start();  // Méthode pour démarrer l'application de la calculatrice

private:
    CalculatorEngine::CalculatorEngine engine;
    void displayResult(double result);
    std::string getInput();
};
}

#endif // CALCULATOR_DISPLAY_H
