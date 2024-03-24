#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

class AdjacencyList {
public:
    //adds an edge from 'from' to 'to' in the graph
    void addEdge(const string& from, const string& to);

    //calculates the PageRank for each page after a specified number of iterations
    string PageRank(int iterations);

    //returns a string representing the PageRank of each page, sorted alphabetically
    string getRanksAsString() const;

    //parse the input and calculate the rank
    void parseInput(const std::string& input);

private:
    //adjacency list representation of the graph with the webpage as key and the value is a list of webpages it points to.
    unordered_map<string, vector<string>> adjList;

    //current PageRank of each page with webpage as the key and its rank as the value
    unordered_map<string, double> ranks;

    //initializes the ranks of all pages
    void initializeRanks();
};