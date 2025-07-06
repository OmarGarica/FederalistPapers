#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

std::string toLowerCase(const std::string& input){
    std::string result;
    result.reserve(input.size());

    for(char ch: input){
        result += std::tolower(static_cast<unsigned char>(ch));
    }
    return result;
}

std::string removePunctuation(const std::string& input){
    char lastChar = input.back();
    if(lastChar == '.' || lastChar == ','){
        return input.substr(0, input.size() - 1);
    }
    return input;
}

const int ENTRIES = 3;

int main() {
    std::cout << "Please enter the filename: ";
    std::string fname;
    std::cin >> fname;
    std::string filename = fname;
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return 1;
    }
    
    std::vector<std::string> words;
    int wordCount = 0;
    int counter = 0;
    std::unordered_map<std::string,  int> cache;
    std::string line;
    
    while (std::getline(file,line)) {
        std::istringstream iss(line);
        std::string word;
        
        while (iss >> word) {
            std::string puncWord = removePunctuation(word);
            std::string lcWord = toLowerCase(puncWord);
            words.push_back(lcWord);
        }
    }
    
    file.close();
    
    std::cout << "\nWords found in the file:" << std::endl;
    std::cout << "Total words: " << words.size() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for(int i = 0; i < words.size(); i++){
        std::cout << i << ": \t" << words[i] << std::endl;
    }

    for (int i = 0; i < words.size(); i++) {
        if(cache.find(words.at(i)) != cache.end()){
            cache[words[i]]++;
        } else{
            cache[words[i]] = 0;
        }
    }

    std::vector<std::pair<std::string, int>> sortedPairs;
    for (const auto& pair : cache) {
        sortedPairs.push_back(pair);
    }

    std::sort(sortedPairs.begin(), sortedPairs.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    int topCount = std::min(ENTRIES, static_cast<int>(sortedPairs.size()));
    for (int i = 0; i < topCount; i++) {
        std::cout << (i + 1) << ". Key: " << sortedPairs[i].first 
                  << ", Value: " << sortedPairs[i].second << std::endl;
    }

    
    return 0;
}
