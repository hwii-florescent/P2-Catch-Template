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

    for (auto &i : inDegree)        //initialize the rank
    {
        rank[i.first] = 1.0f / inDegree.size();
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
    int no_of_lines, power_iterations;
    string from, to;
    iss >> no_of_lines >> power_iterations;     //take in the values for num of line and power of iteration
    
    for(int i = 0; i < no_of_lines; i++)        //loop to take the input value of the page rank
    {
        iss >> from >> to;
        insertEdge(from, to);
    }

    PageRank(power_iterations);     //do the iterations
}

string AdjacencyList::getRanksAsString() {
    string output;
    for (auto &i : rank)    //instead of printing the pageRank of all webpages, we add it into a formatted string using stringstream to use in Catch2 Test
    {
        ostringstream oss; 
        oss << fixed << setprecision(2) << i.first << " " << i.second << "\n";
        output += oss.str();
    }
    return output;
}