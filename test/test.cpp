#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "AdjacencyList.h"

using namespace std;

TEST_CASE("Empty Graph Test", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(0 1)";
    string expectedOutput = R"()";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Cycle in Graph Test", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(3 2
web1.com web2.com
web2.com web3.com
web3.com web1.com)";
    string expectedOutput = R"(web1.com 0.33
web2.com 0.33
web3.com 0.33
)";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Website Link To Itself", "[AdjacencyList]") {
    AdjacencyList pr;
    string input = R"(1 3
web1.com web1.com
)";
    string expectedOutput = R"(web1.com 1.00
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
web4.com web1.com)";
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
web1.com web4.com)";
    string expectedOutput = R"(web1.com 0.00
web2.com 0.08
web3.com 0.08
web4.com 0.08
)";

    pr.parseInput(input);
    string actualOutput = pr.getRanksAsString();

    REQUIRE(actualOutput == expectedOutput);
}