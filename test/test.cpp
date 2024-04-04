#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "AdjacencyList.h"

using namespace std;

TEST_CASE("Disconnected Graph", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(3 2
web1.com web2.com
web3.com web4.com
web5.com web6.com
)";
    string expectedOutput = R"(web1.com 0.00
web2.com 0.17
web3.com 0.00
web4.com 0.17
web5.com 0.00
web6.com 0.17
)";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Cycle in Graph Test", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(3 2
web1.com web2.com
web2.com web3.com
web3.com web1.com
)";
    string expectedOutput = R"(web1.com 0.33
web2.com 0.33
web3.com 0.33
)";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Large Power Iterations", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(6 9999
web1.com web3.com
web2.com web1.com
web3.com web5.com
web6.com web4.com
web4.com web6.com
web5.com web2.com
)";
    string expectedOutput = R"(web1.com 0.17
web2.com 0.17
web3.com 0.17
web4.com 0.17
web5.com 0.17
web6.com 0.17
)";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Multiple Link to Same Website", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(3 4
web2.com web1.com
web3.com web1.com
web4.com web1.com
)";
    string expectedOutput = R"(web1.com 0.00
web2.com 0.00
web3.com 0.00
web4.com 0.00
)";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Single Website Links To Multiple Different Others", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(3 2
web1.com web2.com
web1.com web3.com
web1.com web4.com
)";
    string expectedOutput = R"(web1.com 0.00
web2.com 0.08
web3.com 0.08
web4.com 0.08
)";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}