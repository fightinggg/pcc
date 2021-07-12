#pragma once

#include <vector>
#include <string>

#include "nfa.hpp"

/**
 * using to support regex
 *
 * only support for five key: "(", ")", "|", "*"
 */
class regex_lite {
public:
    static vector<string> regex_m2s(string reg) {
        vector<string> res;
        vector<string> keys;
        auto is_key = [](char ch) {
            return ch == '(' || ch == ')' || ch == '|' || ch == '*';
        };

        for (int i = 0; i < reg.size(); i++) {
            if (reg[i] == '*') {
                res.emplace_back("*");
            } else if (reg[i] == '(' || reg[i] == '|') {
                keys.push_back(string("") + reg[i]);
            } else if (reg[i] == ')') {
                while (!keys.empty() && keys.back() != "(") {
                    res.emplace_back(keys.back());
                    keys.pop_back();
                }
                keys.pop_back();
            } else {
                string word;
                word.push_back(reg[i]);
                while (i + 1 < reg.size() && !is_key(reg[i + 1])) {
                    i++;
                    word.push_back(reg[i]);
                }
                res.push_back(word);
            }
        }
        while (!keys.empty()) {
            res.emplace_back(keys.back());
            keys.pop_back();
        }
        return res;
    }


    static nfa buildNfa(string reg) {
        reg = "(" + reg + ")";
        struct stk_node {
            bool is_key;
            char raw;
            nfa fa;
        };

        vector<stk_node> nfas;
        for (int i = 0; i < reg.size(); i++) {
            if (reg[i] == '(' || reg[i] == '[') {
                nfas.push_back({true, reg[i], nfa(nfa::EMPTY_TRANS)});
            } else if (reg[i] == ')') {
                while (!nfas[nfas.size() - 2].is_key) {
                    nfas[nfas.size() - 2].fa.tandem(nfas.back().fa);
                    nfas.pop_back();
                }
                nfas.erase(nfas.end() - 2);
            } else if (reg[i] == ']') {
                while (!nfas[nfas.size() - 2].is_key) {
                    nfas[nfas.size() - 2].fa.parallel(nfas.back().fa);
                    nfas.pop_back();
                }
                nfas.erase(nfas.end() - 2);
            } else if (reg[i] == '*') {
                nfas.back().fa.selfLoop();
            } else {
                i += reg[i] == '/' ? 1 : 0;
                nfas.push_back({false, reg[i], nfa(reg[i])});
            }
        }
        return nfas.front().fa;
    }
};