#include "AdjacencyList.h"

void AdjacencyList::insertEdge(string from, string to)
{
    //add edge from to to from and increment outDegree for from
    inDegree[to].push_back(from);
    ++outDegree[from];

    if (outDegree.find(to) == outDegree.end())      //if to is not in outDegree, add it with an initialize value of 0
    {
        outDegree[to] = 0.0f;
    }
    
    if (inDegree.find(from) == inDegree.end())      //if from is not in inDegree, add it with an initialize empty vector of string
    {
        inDegree[from] = vector<std::string>();
    }
}

void AdjacencyList::PageRank(int n)
{
    map<string, double> tempRank;        //create a temp to store the current rank

    for (auto &webPage : inDegree)        //initialize the rank
    {
        rank[webPage.first] = 1.0f / inDegree.size();
    }

    for (int i = 1; i < n; ++i)     //calculate the rank after n power iterations
    {
        tempRank = rank;
        for (auto &webPage : inDegree)
        {
            float rankSum = 0;

            for (auto &link : webPage.second)
            {
                rankSum += (1.0f / (float)outDegree.find(link)->second) * rank[link];
            }
            tempRank[webPage.first] = rankSum;
        }
        rank.swap(tempRank);
    }

    for (auto &i : rank)        //print out the PageRank with correct order and rounding
    {
        cout << setprecision(2) << fixed << i.first << " " << i.second << endl;
    }
}

void AdjacencyList::parseInput(string input) {
    istringstream iss(input);       //stream the input value
    int noOfLines, powerIterations;
    string from, to;
    iss >> noOfLines >> powerIterations;     //take in the values for num of line and power of iteration
    
    for(int i = 0; i < noOfLines; i++)        //loop to take the input value of the page rank
    {
        iss >> from >> to;
        insertEdge(from, to);
    }

    PageRank(powerIterations);     //do the iterations
}

string AdjacencyList::getRanksAsString() {
    string output;
    for (auto &webPage : rank)    //instead of printing the pageRank of all webpages, we add it into a formatted string using stringstream to use in Catch2 Test
    {
        ostringstream oss; 
        oss << fixed << setprecision(2) << webPage.first << " " << webPage.second << "\n";
        output += oss.str();
    }
    return output;
}