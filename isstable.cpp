#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

std::pair<std::string, int> IS_STABLE(std::unordered_map<char, std::vector<char>>& preference1, 
                                      std::unordered_map<char, std::vector<char>>& preference2, 
                                      std::unordered_map<char, char>& matching) {
    int flag = 0;

    for (const auto& myPair : matching) {
        char husband = myPair.first; // the husband <- the key 
        char wife = myPair.second;    // his wife
        std::vector<char>& preference_husband = preference1[husband]; // the husband's preference
        int index_wife = -1;

        // find the index of the wife in the preference list
        for (int i = 0; i < preference_husband.size(); ++i) {
            if (preference_husband[i] == wife) {
                index_wife = i;
                break;
            }
        }

        for (int i = 0; i < index_wife; ++i) {
            char woman = preference_husband[i]; // a woman who the husband prefers than his wife
            std::vector<char>& preference_woman = preference2[woman]; // the preference list of this woman

            // find her own husband
            char her_husband = -1;
            for (const auto& entry : matching) {
                if (entry.second == woman) {
                    her_husband = entry.first;
                    break;
                }
            }

            // find the index of her own husband
            int index_her_husband = -1;
            for (int j = 0; j < preference_woman.size(); ++j) {
                if (preference_woman[j] == her_husband) {
                    index_her_husband = j;
                    break;
                }
            }

            // find the index of the husband
            int index_husband = -1;
            for (int j = 0; j < preference_woman.size(); ++j) {
                if (preference_woman[j] == husband) {
                    index_husband = j;
                    break;
                }
            }

            if (index_husband < index_her_husband) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0) {
        return std::make_pair("stable", flag);
    }
    if (flag == 1) {
        return std::make_pair("unstable", flag);
    }

    // Default return if no conditions are met (should not be reached)
    return std::make_pair("unknown", -1);
}