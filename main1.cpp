#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include "isstable.h"

int main() {
    // Example usage for matching1
    std::unordered_map<char, std::vector<char>> preference1 = {
        {'A', {'c', 'b', 'd', 'a'}},
        {'B', {'b', 'a', 'c', 'd'}},
        {'C', {'b', 'd', 'a', 'c'}},
        {'D', {'c', 'a', 'd', 'b'}}
    };
    std::unordered_map<char, std::vector<char>> preference2 = {
        {'c', {'C', 'B', 'D', 'A'}},
        {'a', {'A', 'B', 'D', 'C'}},
        {'b', {'C', 'A', 'D', 'B'}},
        {'d', {'B', 'A', 'C', 'D'}}
    };
    std::unordered_map<char, char> matching1 = {
        {'A', 'd'},
        {'B', 'a'},
        {'C', 'b'},
        {'D', 'c'}
    }; // stable

    auto result1 = IS_STABLE(preference1, preference2, matching1);
    std::cout << "Result for matching1: " << result1.first << std::endl;
    std::cout << "Flag: " << result1.second << std::endl;

    // Example usage for matching2
    std::unordered_map<char, char> matching2 = {
        {'A', 'a'},
        {'B', 'b'},
        {'C', 'c'},
        {'D', 'd'}
    }; // unstable

    auto result2 = IS_STABLE(preference1, preference2, matching2);
    std::cout << "Result for matching2: " << result2.first << std::endl;
    std::cout << "Flag: " << result2.second << std::endl;

    return 0;
}