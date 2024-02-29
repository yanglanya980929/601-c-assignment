#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "algorithm.h"
#include "table_algorithm.h"
#include "isstable.h"

int main() {
    // Apply the algorithm function to the tables
    std::unordered_map<char, char> matching = table_algorithm("table1.txt", "table2.txt");

    // Print the result
    std::cout << "Algorithm Result:" << std::endl;
    for (const auto& entry : matching) {
        std::cout << entry.first << " matches with " << entry.second << std::endl;
    }
    
    return(0);
}
