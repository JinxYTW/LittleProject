#ifndef TEXTANALYZERENGINE_H
#define TEXTANALYZERENGINE_H

#include <string>
#include <vector>
#include <map>


namespace TextAnalyzerEngine
{
    class TextAnalyzerEngine
    {
    public:
        TextAnalyzerEngine();

        void OpenFile(const std::string& fileName);
        void AnalyzeText(const std::string& text);
        void PrintResults() const;

    private:
        void CountWords(const std::string& text);
        void CountLetters(const std::string& text);
        void CountSentences(const std::string& text);
        void CountParagraphs(const std::string& text);
        void FindMostUsedWords(const std::string& text); 
        
        std::vector<std::string> SplitText(const std::string& text, const std::string& delimiter) const;

        std::map<std::string, int> m_wordCount;
        std::map<char, int> m_letterCount;
        int m_sentenceCount;
        int m_paragraphCount;
        std::string m_fileName;
        std::string m_mostUsedWord;
    };
}




#endif // TEXTANALYZERENGINE_H