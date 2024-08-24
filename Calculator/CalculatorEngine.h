// CalculatorEngine.h
#ifndef CALCULATOR_ENGINE_H
#define CALCULATOR_ENGINE_H

#include <string>
#include <vector>
namespace CalculatorEngine {

class CalculatorEngine {
public:
    // Méthode pour traiter une expression mathématique et renvoyer le résultat
    double processExpression(const std::string& expression);

private:
    // Méthodes pour effectuer les calculs spécifiques
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    // Méthode pour analyser l'expression et déterminer l'opération
    double evaluateExpression(const std::vector<std::string>& tokens);
    
    // Méthode pour tokenizer une expression
    std::vector<std::string> tokenize(const std::string& expression);
};

} // namespace CalculatorEngine

#endif // CALCULATOR_ENGINE_H
