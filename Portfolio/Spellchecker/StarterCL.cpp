#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

struct word {
    std::string text;
    int line;
    int column;
};

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
            words.push_back({ match.str(), line, column });
            column += match.length();
            text = match.suffix().str();
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file_name>\n";
        return 1;
    }

    std::string file_name = argv[1];
    std::vector<word> words;
    if (read_words(file_name, words)) {
        for (word w : words) {
            std::cout << w.text << "  (line " << w.line
                      << ", column " << w.column << ")\n";
        }
    } else {
        std::cout << "Unable to read file: " << file_name << "\n";
        return 1;
    }

    return 0;
}
