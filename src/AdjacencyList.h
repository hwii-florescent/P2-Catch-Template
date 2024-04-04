// Copyright [2023] <Tuan Truong & Lam Luu>
#ifndef AUTOGRADER_SOURCE_TESTS_COP3530_6_1_H
#define AUTOGRADER_SOURCE_TESTS_COP3530_6_1_H
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Graph
{
   private:
      // TODO: Graph structure that supports parallel edges and self-loops
      std::unordered_map<int, std::vector<std::pair<int, int>>> table;

    public:
      void insertEdge(int from, int to, int weight);
      bool isEdge(int from, int to);
      int sumEdge(int from, int to);
      std::vector<int> getWeight(int from, int to);
      std::vector<int> getAdjacent(int vertex);
};

void Graph::insertEdge(int from, int to, int weight)
{
    std::vector<std::pair<int, int>> that_vector;
    std::pair<int, int> result(to, weight);
   /*
        TODO: insertEdge() adds a new edge between the from
        and to vertex.
   */

    if (!table.count(from))
    {
        table[from] = that_vector;
        table[from].push_back(result);
    }
    else
    {
        table[from].push_back(result);
    }
}

bool Graph::isEdge(int from, int to)
{
    /*
        TODO: isEdge() returns a boolean indicating true
        if there is an edge between the from and to vertex
    */

    for (auto member: table[from])
    {
        if (member.first == to)
        {
            return true;
        }
    }

    return false;
}

int Graph::sumEdge(int from, int to)
{
    int sum = 0;

    /*
        TODO: sumEdge() returns the sum of weights of all edges
        connecting the from and to vertex. Returns 0 if no edges
        connect the two vertices.
    */

    for (auto member: table[from])
    {
        if (member.first == to)
        {
            sum += member.second;
        }
    }

    for (auto member: table[to])
    {
        if (member.first == from)
        {
            if (member.first == to) continue;
            else sum += member.second;
        }
    }

    return sum;
}

std::vector<int> Graph::getWeight(int from, int to)
{
    std::vector<int> sorted;

    for (auto member: table[from])
    {
        if (member.first == to)
        {
            sorted.push_back(member.second);
        }
    }

    for (auto member: table[to])
    {
        if (member.first == from)
        {
            if (member.second > sorted.at(0))
            {
                sorted.push_back(member.second);
            }
            else
            {
                sorted.push_back(member.second);
                int temp = sorted.at(0);
                sorted.at(0) = sorted.at(1);
                sorted.at(1) = temp;
            }
        }
    }
    
    /*
        TODO: getWeight() returns a sorted vector containing all
        weights of the edges connecting the from and to vertex
    */
    return sorted;
}

std::vector<int> Graph::getAdjacent(int vertex)
{
    std::vector<int> adjacent;

    for (auto member: table[vertex])
    {
        adjacent.push_back(member.first);
    }
    
    /*
        TODO: getAdjacent() returns a sorted vector of all vertices
        that are connected to a vertex
    */
    return adjacent;
}

#endif // AUTOGRADER_SOURCE_TESTS_COP3530_6_1_H"