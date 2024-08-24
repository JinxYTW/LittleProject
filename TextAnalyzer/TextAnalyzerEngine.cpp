#include "TextAnalyzerEngine.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>


namespace TextAnalyzerEngine{

    TextAnalyzerEngine::TextAnalyzerEngine(): m_sentenceCount(0), m_paragraphCount(0) {}

    void TextAnalyzerEngine::OpenFile(const std::string& fileName){
        m_fileName = fileName;
        std::ifstream file(fileName);
        if(!file.is_open()){
            std::cerr << "Erreur : Impossible d'ouvrir le fichier " << fileName << std::endl;
            return;
        }
        
        //Gère la lecture du fichier puis l'insère dans un buffer que l'on convertit en string
        std::stringstream buffer;
        buffer << file.rdbuf(); //
        std::string text = buffer.str();

        AnalyzeText(text);
    }

    void TextAnalyzerEngine::AnalyzeText(const std::string& text){
        CountWords(text);
        CountLetters(text);
        CountSentences(text);
        CountParagraphs(text);
        FindMostUsedWords(text);
    }

    void TextAnalyzerEngine::PrintResults() const{
        std::cout << "Nombre de mots : " << m_wordCount.size() << std::endl;
        std::cout << "Nombre de lettres : " << m_letterCount.size() << std::endl;
        std::cout << "Nombre de phrases : " << m_sentenceCount << std::endl;
        std::cout << "Nombre de paragraphes : " << m_paragraphCount << std::endl;
        std::cout << "Mot le plus utilisé : " << m_mostUsedWord << std::endl;
    }

    void TextAnalyzerEngine::CountWords(const std::string& text){
        std::vector<std::string> words = SplitText(text, " ");
        for(const std::string& word : words){
            m_wordCount[word]++; //l'opérateur [] de std::map a un comportement spécial : s'il accède à une clé qui n'existe pas encore dans la map, il insère cette clé avec une valeur par défaut (dans ce cas, 0 pour un int). Ensuite, l'opérateur ++ incrémente cette valeur.
        }
    }

    void TextAnalyzerEngine::CountLetters(const std::string& text){
        for(char c : text){
            if(std::isalpha(c)){
                m_letterCount[c]++;
            }
        }
    }

    void TextAnalyzerEngine::CountSentences(const std::string& text){
        for(char c : text){
            if(c == '.' || c == '!' || c == '?'){
                m_sentenceCount++;
            }
        }
    }

    void TextAnalyzerEngine::CountParagraphs(const std::string& text){
        for(char c : text){
            if(c == '\n'){
                m_paragraphCount++;
            }
        }
    }

    void TextAnalyzerEngine::FindMostUsedWords(const std::string& text) {
        std::string mostUsedWord; // Variable pour stocker le mot le plus utilisé
        int maxCount = 0; // Variable pour stocker le nombre maximum d'occurrences

            // Boucle sur chaque paire (mot, nombre d'occurrences) dans m_wordCount
            for (const auto& pair : m_wordCount) {
                // Si le nombre d'occurrences du mot actuel est supérieur à maxCount
                if (pair.second > maxCount) {
                    mostUsedWord = pair.first; // Met à jour le mot le plus utilisé
                    maxCount = pair.second; // Met à jour le nombre maximum d'occurrences
                }
            }

            m_mostUsedWord = mostUsedWord; // Stocke le mot le plus utilisé dans m_mostUsedWord
    }

    

    std::vector<std::string> TextAnalyzerEngine::SplitText(const std::string& text, const std::string& delimiter) const{
        std::vector<std::string> words;
        size_t start = 0;
        size_t end = text.find(delimiter);
        while(end != std::string::npos){
            words.push_back(text.substr(start, end - start));
            start = end + delimiter.size();
            end = text.find(delimiter, start);
        }
        words.push_back(text.substr(start, end));
        return words;
    }







}


    
