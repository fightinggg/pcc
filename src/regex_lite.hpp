#pragma once

#include <vector>
#include <string>

#include "nfa.hpp"

/**
 * using to support regex
 *
 * only support for five key: "(", ")", "[", "]", "*"
 */
class regex_lite {
    class regex_lite_token {
        bool is_key;
        char raw;
    };

public:
    static nfa buildNfa(string reg) {
        nfa fa;
        for (int i = 0; i < reg.size(); i++) {
            if (reg[i] == '/') {
                i++;
                fa.endTransTo(reg[i], new nfa::node(nfa::node::END_NODE_TYPE));
            } else {

            }
        }
    }
};