#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class AdjacencyList
{
private:
    map<string, vector<string>> inDegree;
    map<string, double> outDegree;
    map<string, double> rank;

public:
    void insertEdge(string from, string to);      //insert edge for the two given from and to webpages
    void PageRank(int n);       //print the PageRank of all pages after p powerIterations in ascending alphabetical order of webpage and rounding rank to two decimal places
    void parseInput(string input);      //parse the input given from the catch2 test 
    string getRanksAsString();      //return a string of the page rank output
};

