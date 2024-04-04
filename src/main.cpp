#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class AdjacencyList {
private:
//Think about what member variables you need to initialize
map<string, vector<string>> inDegree;
map<string, float> outDegree;
map<string, float> pageRank;

public:
//Think about what helper functions you will need in the algorithm
    void PageRank(int n);
    void insert(const string& from, const string& to);
};

void AdjacencyList::insert(const string& _from, const string& _to){
        inDegree[_to].push_back(_from);
        outDegree[_from] += 1;

        if(inDegree.find(_from) == inDegree.end()){
            inDegree[_from] = {};
        }
        if(outDegree.find(_to) == outDegree.end()){
            outDegree[_to] = {};
        }
}



void AdjacencyList::PageRank(int n){
// Initialize Map
    map<string, float> tempPageRank;

    for(auto & i : inDegree){
        pageRank[i.first] = (1.0f / inDegree.size());
    }

    // Power iterator
    for(int i = 1; i < n; ++i){
        tempPageRank = pageRank;
        // Go through each vertex and its indegrees
        for(auto & j: inDegree){

            float rankSum = 0;
            // iterate through array of vertexes
/*
            for(int k = 0; k < j.second.size(); ++i){
                rankSum += (1.0f / outDegree.find(j.second[k])->second) * pageRank[j.second[k]];
            }
 */

            for(auto & k: j.second){
                rankSum += (1.0f / (float)outDegree.find(k)->second) * pageRank[k];
            }


            tempPageRank[j.first] = rankSum;


        }
        pageRank = tempPageRank;
    }

    for(auto & i : pageRank){
        cout << setprecision(2) << fixed << i.first << " " << i.second << endl;
    }


}


int main()
{
    AdjacencyList simplePageRank;
    int no_of_lines, power_iterations;
    std::string from, to;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;
    for(int i = 0; i < no_of_lines; i++)
    {
        std::cin >> from;
        std::cin >> to;
        simplePageRank.insert(from, to);

    }
    //Create a graph object
    simplePageRank.PageRank(power_iterations);
}