#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include "algorithm.h"

int main(){
    // Example usage
    std::unordered_map<char, std::vector<char>> preference1 = {
        {'A', {'c', 'b', 'd', 'a'}},
        {'B', {'b', 'a', 'c', 'd'}},
        {'C', {'b', 'd', 'a', 'c'}},
        {'D', {'c', 'a', 'd', 'b'}}
    };

    std::unordered_map<char, std::vector<char>> preference2 = {
        {'a', {'A', 'B', 'D', 'C'}},
        {'b', {'C', 'A', 'D', 'B'}},
        {'c', {'C', 'B', 'D', 'A'}},
        {'d', {'B', 'A', 'C', 'D'}}
    };

    std::unordered_map<char, char> result = algorithm(preference1, preference2);

    // Print the result
    for (const auto& entry : result) {
        std::cout << entry.first << " matches with " << entry.second << std::endl;
    }

    return 0;
}