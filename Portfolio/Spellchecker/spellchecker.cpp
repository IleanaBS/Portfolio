/*----------------------------------------------------------
 * Project: Spell Checker
 *
 * Date: 29-Nov-2023
 * Authors:
 *           A01798528 Jocelyn Balderas
 *           A01747396 Marisol Ramírez
 *----------------------------------------------------------*/

// Using unordered_multimap

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <regex>
#include <chrono>

// Complexity: O(1)
struct word {
    std::string text;
    int line;
    int column;
};

// Complexity: O(N)
// N is the total length of the file
bool read_words(
        const std::string input_file_name,
        std::vector<word>& words)
{
    std::ifstream input_file(input_file_name);
    if (input_file.fail()) {
        return false;
    }
    std::regex reg_exp("[a-zA-Z]+");
    std::smatch match;
    std::string text;
    int line = 0;
    int column = 0;
    while (std::getline(input_file, text)) {
        ++line;
        column = 1;
        while (std::regex_search(text, match, reg_exp)) {
            column += match.position();
            words.push_back({match.str(), line, column});
            column += match.length();
            text = match.suffix().str();
        }
    }
    return true;
}

// Complexity: O(N)
// N is the length of the input word
std::string soundex(const std::string& word) {
    if (word.empty()) {
        return "";
    }

    // Convert the input word to uppercase
    std::string upperWord = word;
    std::transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);

    // Step 1: retain the initial letter
    std::string soundexCode(1, upperWord[0]);

    // Encode the consonants
    for (size_t i = 1; i < upperWord.length() && soundexCode.length() < 8; ++i) {
        char currentChar = upperWord[i];

        // Drop the vowels, h, w, and y
        if (currentChar == 'A' || currentChar == 'E' || currentChar == 'I' ||
            currentChar == 'O' || currentChar == 'U' || currentChar == 'H' ||
            currentChar == 'W' || currentChar == 'Y') {
            continue;
        }

        // Step 2: encode the consonants
        if (currentChar == 'B' || currentChar == 'F' || currentChar == 'P' || currentChar == 'V') {
            soundexCode += '1';
        } else if (currentChar == 'C' || currentChar == 'G' || currentChar == 'J' ||
                   currentChar == 'K' || currentChar == 'Q' || currentChar == 'S' ||
                   currentChar == 'X' || currentChar == 'Z') {
            soundexCode += '2';
        } else if (currentChar == 'D' || currentChar == 'T') {
            soundexCode += '3';
        } else if (currentChar == 'L') {
            soundexCode += '4';
        } else if (currentChar == 'M' || currentChar == 'N') {
            soundexCode += '5';
        } else if (currentChar == 'R') {
            soundexCode += '6';
        }
    }

    // Drop all the vowels
    soundexCode.erase(std::remove_if(soundexCode.begin() + 1, soundexCode.end(),
                                     [](char c) { return c == 'A' || c == 'E' || c == 'I' ||
                                                  c == 'O' || c == 'U'; }), soundexCode.end());

    // Step 3: make the code length 7
    while (soundexCode.length() < 8) {
        soundexCode += '0';
    }

    // truncate if length exceeds 7
    soundexCode = soundexCode.substr(0, 7);

    return soundexCode;
}

// Complexity: O(N)
// N is the total length of the file
void read_file(const std::string& file_name, const std::unordered_set<std::string>& correctWords,
                 std::unordered_multimap<std::string, std::string>& soundexMap) {
    std::vector<word> words;

    if (!read_words(file_name, words)) {
        std::cerr << "Unable to read file: " << file_name << "\n";
        std::exit(1);
    }

    // Set to keep track of reported misspelled words
    std::unordered_set<std::string> reportedMisspellings;

    for (const auto& w : words) {
        // Convert the word to lowercase
        std::string lowercaseWord = w.text;
        std::transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);

        if (correctWords.find(lowercaseWord) == correctWords.end() &&
            reportedMisspellings.find(lowercaseWord) == reportedMisspellings.end()) {
            // Mark the word as reported
            reportedMisspellings.insert(lowercaseWord);

            std::cout << "Unrecognized word: \"" << w.text << "\" . First found at line "
                      << w.line << ", column " << w.column << "\n" << "Suggestions: ";

            // Find suggestions using Algorithm Soundex
            std::string wordSoundex = soundex(w.text);
            auto range = soundexMap.equal_range(wordSoundex);
            std::vector<std::string> suggestions;
            for (auto it = range.first; it != range.second; ++it) {
                // Exclude the original word from suggestions
                if (it->second != w.text) {
                    suggestions.push_back(it->second);
                }
            }
            // Display sorted suggestions
            if (suggestions.empty()) {
                std::cout << "No suggestions.";
            } else {
                std::sort(suggestions.begin(), suggestions.end());
                for (size_t i = 0; i < suggestions.size(); ++i) {
                    std::cout << suggestions[i];
                    if (i + 1 < suggestions.size()) {
                        std::cout << ", ";
                    }
                }
            }
            std::cout << "\n\n";
        }
    }
}

// Complexity: O(N)
// N is the total length of the file
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>\n";
        return 1;
    }

    // Start time tracking of the program's execution
    auto start = std::chrono::high_resolution_clock::now();

    std::unordered_set<std::string> correctWords;
    std::ifstream wordsFile("words.txt");
    std::string correctWord;
    while (wordsFile >> correctWord) {
        correctWords.insert(correctWord);
    }

    // Store the unique Soundex codes and corresponding set of words
    std::unordered_multimap<std::string, std::string> soundexMap;
    for (const auto& word : correctWords) {
        soundexMap.insert({soundex(word), word});
    }

    std::string file_name = argv[1];  // Get the input file name from the command line

    read_file(file_name, correctWords, soundexMap); // Calling function read_file

    // Measuring total time of program's execution
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1000000.0;

    std::cout << "Total time = " << total_time << " seconds\n";

    return 0;
}