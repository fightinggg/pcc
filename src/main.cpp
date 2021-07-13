
#include<cstdio>
#include <iostream>
#include "nfa.hpp"
#include "regex_lite.hpp"
#include "parsing.hpp"

using namespace std;

int main() {
    printf("hello pcc\n");
    for (string s:regex_lite::regex_m2s("((abc*)|cde)*|123")) {
        cout << s << " ";
    }
    int
    a

//    nfa fa = regex_lite::buildNfa("(123aabb)+[abcd]*d*");

}