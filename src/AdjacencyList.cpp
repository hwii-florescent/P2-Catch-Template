#include <iostream>
#include "AdjacencyList.h"

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    return "";
}

string AdjacencyList::getRanksAsString() const {
    std::stringstream ss;
    std::vector<std::pair<std::string, double>> sortedRanks(ranks.begin(), ranks.end());
    std::sort(sortedRanks.begin(), sortedRanks.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; // Alphabetical order
    });
    for (const auto& rank : sortedRanks) {
        ss << rank.first << " " << std::fixed << std::setprecision(2) << rank.second << "\n";
    }
    return ss.str();
}

void AdjacencyList::parseInput(const std::string& input) {

}
