#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
int main(){
    std::string filename = "paperone.txt";
    
    // Open the input file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return 1;
    }
    
    // Vector to store words (dynamic array)
    std::vector<std::string> words;
    std::vector<string> cache;
    std::string line;
    
    // Read file line by line
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        
        // Extract words from each line
        while (iss >> word) {
            words.push_back(word);
        }
    }
    
    file.close();
    
    // Display the words
    std::cout << "\nWords found in the file:" << std::endl;
    std::cout << "Total words: " << words.size() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    size_t counter = 0;
    for (size_t i = 0; i < words.size(); ++i) {

    }
}
