// TextAnalyzerDisplay.cpp
#include "TextAnalyzerDisplay.h"
#include <iostream>

using namespace TextAnalyzer;

TextAnalyzerDisplay::TextAnalyzerDisplay() : m_engine() {}

void TextAnalyzerDisplay::Start() {
    std::string userInput;
    
    while (true) {
        DisplayMenu();
        std::getline(std::cin, userInput); // Récupère la saisie de l'utilisateur
        if (userInput == "exit") {
            break;
        }
        ProcessUserInput(userInput);
    }
}

void TextAnalyzerDisplay::DisplayMenu() const {
    std::cout << "\n--- Analyseur de Texte ---" << std::endl;
    std::cout << "Entrez le nom du fichier à analyser ou 'exit' pour quitter : ";
}

void TextAnalyzerDisplay::ProcessUserInput(const std::string& input) {
    try {
        m_engine.OpenFile(input);
        
        m_engine.PrintResults();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
