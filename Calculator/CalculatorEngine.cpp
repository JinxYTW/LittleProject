#include "CalculatorEngine.h"

#include <iostream>
#include <sstream>

namespace CalculatorEngine {
    
            double CalculatorEngine::processExpression(const std::string& expression)
            {
                std::vector<std::string> tokens = tokenize(expression);
                return evaluateExpression(tokens);
            }

        

            double CalculatorEngine::add(double a, double b)
            {
                return a + b;
            }

            double CalculatorEngine::subtract(double a, double b)
            {
                return a - b;
            }

            double CalculatorEngine::multiply(double a, double b)
            {
                return a * b;
            }

            double CalculatorEngine::divide(double a, double b)
            {
                return a / b;
            }

            double CalculatorEngine::evaluateExpression(const std::vector<std::string>& tokens)
            {
                double result = 0.0;
                double current = 0.0;
                std::string operation = "+";

                for (const std::string& token : tokens)
                {
                    if (token == "+" || token == "-" || token == "*" || token == "/")
                    {
                        operation = token;
                    }

                    else
                    {
                        double value = std::stod(token); //stod convertit cette chaîne en un double et assigne la valeur résultante à la variable value.

                        switch (operation[0])
                        {
                            case '+':
                                result = add(result, current);
                                current = value;
                                break;
                            case '-':
                                result = subtract(result, current);
                                current = value;
                                break;
                            case '*':
                                current = multiply(current, value);
                                break;
                            case '/':
                                current = divide(current, value);
                                break;
                        }
                    }
                }

                return result + current;
            }

            // Tokenization de l'expression (par exemple "3 + 4" devient ["3", "+", "4"])
            std::vector<std::string> CalculatorEngine::tokenize(const std::string& expression) {
                std::vector<std::string> tokens;
                std::stringstream ss(expression);
                std::string token;
                
                while (ss >> token) { //extrait des données du flux et les stocke dans une variable. Par exemple, ss >> token lit un mot (séparé par des espaces) du flux ss et le stocke dans la variable token.
                    tokens.push_back(token);
                }
                
                return tokens;
            }
    

    

} // namespace CalculatorEngine