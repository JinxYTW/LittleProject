// TextAnalyzerDisplay.h
#ifndef TEXTANALYZERDISPLAY_H
#define TEXTANALYZERDISPLAY_H

#include "TextAnalyzerEngine.h"

namespace TextAnalyzer
{
    class TextAnalyzerDisplay
    {
    public:
        TextAnalyzerDisplay();

        void Start();  // Méthode pour démarrer l'analyseur de texte

    private:
        TextAnalyzerEngine::TextAnalyzerEngine m_engine;
        
        void DisplayMenu() const;
        void ProcessUserInput(const std::string& input);
    };
}

#endif // TEXTANALYZERDISPLAY_H
