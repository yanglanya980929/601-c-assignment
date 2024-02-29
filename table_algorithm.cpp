#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "algorithm.h"
#include "isstable.h"

std::unordered_map<char, char> table_algorithm(const std::string filename1, const  std::string filename2){
    std::ifstream file1(filename1);

    std::unordered_map<char, std::vector<char>> table1;
    std::string line1;
    while (std::getline(file1, line1)) {
        std::istringstream iss(line1);
        char key1;
        char value1;
        iss >> key1;
        table1[key1] = std::vector<char>();

        while (iss >> value1) {
            table1[key1].push_back(value1);
        }
    }
    file1.close();

    // Read and store values from the second file ('table2.txt')
    std::ifstream file2(filename2);

    std::unordered_map<char, std::vector<char>> table2;
    std::string line2;
    while (std::getline(file2, line2)) {
        std::istringstream iss(line2);
        char key2;
        char value2;
        iss >> key2;
        table2[key2] = std::vector<char>();

        while (iss >> value2) {
            table2[key2].push_back(value2);
        }
    }
    file2.close();

    // Apply the algorithm function to the tables
    std::unordered_map<char, char> matching = algorithm(table1, table2);

    //auto result = IS_STABLE(table1, table2, matching);
    //std::cout << "Result for matching: " << result.first << std::endl;
    //std::cout << "Flag: " << result.second << std::endl;

    return matching;
}