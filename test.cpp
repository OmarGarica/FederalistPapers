#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    // Static array of strings
    static std::string words[] = {
        "apple", "banana", "cherry", "apple", "date", 
        "elderberry", "banana", "fig", "grape", "apple",
        "cherry", "honeydew", "kiwi", "banana", "lemon"
    };
    
    // Calculate array size
    int arraySize = sizeof(words) / sizeof(words[0]);
    
    // Unordered map cache with string keys and int values
    std::unordered_map<std::string, int> cache;
    
    // Iterate through the array
    for (int i = 0; i < arraySize; i++) {
        // Check if the current string exists as a key in cache
        if (cache.find(words[i]) != cache.end()) {
            // Key exists, increment its value
            cache[words[i]]++;
        } else {
            // Key doesn't exist, add it with initial value of 0
            cache[words[i]] = 0;
        }
    }
    
    // Display the cache contents
    std::cout << "Cache contents:\n";
    for (const auto& pair : cache) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    
    return 0;
}
