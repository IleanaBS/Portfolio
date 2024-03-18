#include <iostream>
#include <algorithm>

// std::string soundex(const std::string& word) {
//     if (word.empty()) {
//         return "";
//     }

//     // Convert the input word to uppercase
//     std::string upperWord = word;
//     std::transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);

//     // Step 1: Retain the initial letter
//     std::string soundexCode(1, upperWord[0]);

//     // Step 2: Encode the consonants
//     for (size_t i = 1; i < upperWord.length() && soundexCode.length() < 8; ++i) {
//         char currentChar = upperWord[i];

//         // Skip vowels, h, w, and y
//         if (currentChar == 'A' || currentChar == 'E' || currentChar == 'I' ||
//             currentChar == 'O' || currentChar == 'U' || currentChar == 'H' ||
//             currentChar == 'W' || currentChar == 'Y') {
//             continue;
//         }

//         // Encode the consonants
//         if (currentChar == 'B' || currentChar == 'F' || currentChar == 'P' || currentChar == 'V') {
//             soundexCode += '1';
//         } else if (currentChar == 'C' || currentChar == 'G' || currentChar == 'J' ||
//                   currentChar == 'K' || currentChar == 'Q' || currentChar == 'S' ||
//                   currentChar == 'X' || currentChar == 'Z') {
//             soundexCode += '2';
//         } else if (currentChar == 'D' || currentChar == 'T') {
//             soundexCode += '3';
//         } else if (currentChar == 'L') {
//             soundexCode += '4';
//         } else if (currentChar == 'M' || currentChar == 'N') {
//             soundexCode += '5';
//         } else if (currentChar == 'R') {
//             soundexCode += '6';
//         }
//     }

//     // Step 3: Drop all the vowels
//     soundexCode.erase(std::remove_if(soundexCode.begin() + 1, soundexCode.end(),
//                                      [](char c) { return c == 'A' || c == 'E' || c == 'I' ||
//                                                   c == 'O' || c == 'U'; }), soundexCode.end());

//     // Step 4: Make the code length 7
//     while (soundexCode.length() < 8) {
//         soundexCode += '0';
//     }

//     // Step 5: Truncate if length exceeds 7
//     soundexCode = soundexCode.substr(0, 7);

//     return soundexCode;
// }

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

std::string soundex(const std::string& word) {
    if (word.empty()) {
        return "";
    }

    // Convert the input word to uppercase
    std::string upperWord = word;
    std::transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);

    // Step 1: Retain the initial letter and drop the vowels, h, w, and y
    std::string soundexCode(1, upperWord[0]);
    for (size_t i = 1; i < upperWord.length() && soundexCode.length() < 8; ++i) {
        char currentChar = upperWord[i];

        // Skip vowels, h, w, and y
        if (currentChar == 'A' || currentChar == 'E' || currentChar == 'I' ||
            currentChar == 'O' || currentChar == 'U' || currentChar == 'H' ||
            currentChar == 'W' || currentChar == 'Y') {
            continue;
        }

        // Step 2: Encode the consonants
        std::unordered_map<char, std::string> soundexMap = {
            {'B', "1"}, {'F', "1"}, {'P', "1"}, {'V', "1"},
            {'C', "2"}, {'G', "2"}, {'J', "2"}, {'K', "2"},
            {'Q', "2"}, {'S', "2"}, {'X', "2"}, {'Z', "2"},
            {'D', "3"}, {'T', "3"},
            {'L', "4"},
            {'M', "5"}, {'N', "5"},
            {'R', "6"}
        };

        auto it = soundexMap.find(currentChar);
        if (it != soundexMap.end()) {
            std::string code = it->second;
            soundexCode += code;
        }
    }

    // Step 3: Make the code length 7
    soundexCode.resize(7, '0');

    return soundexCode;
}

int main() {
    std::string inputWord = "Monterrey";
    std::string result = soundex(inputWord);

    std::cout << "Soundex Code of " << inputWord << ": " << result << std::endl;

    return 0;
}