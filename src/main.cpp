#include "AdjacencyList.h"

int main()
{
    AdjacencyList pr;

    //given from the template
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    for(int i = 0; i < no_of_lines; i++)
    {
        cin >> from;
        cin >> to;
        pr.insertEdge(from, to);
    }

    //create a graph object
    pr.PageRank(power_iterations);
}