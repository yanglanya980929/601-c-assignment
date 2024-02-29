#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "algorithm.h"
#include "table_algorithm.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argc - 1);
    for(int i = 0; i < argc - 1; i++)
    {
        args[i] = std::string(argv[i+1]);
    }
    // Apply the algorithm function to the tables
    int i;
    int n = std::stoi(args[2]);
    std::unordered_map<char, char> matching;
    for (i=0; i < n; i++){
        matching = table_algorithm(args[0], args[1]);
    }

    // Print the result
    std::cout << "Algorithm Result:" << std::endl;
    for (const auto& entry : matching) {
        std::cout << entry.first << " matches with " << entry.second << std::endl;
    }
    
    return(0);
}
