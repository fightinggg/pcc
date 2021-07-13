#pragma once

#include <map>
#include <string>

/**
 * 产生式
 */
struct production {
    int id;

    bool end; // 是否终结符
    vector<int> derive; // 不是终结符，才有推导
};

/**
 * 文法
 */
struct grammar {
    map<int, string> raw;
    map<string, int> id;
    map<int, vector<production>> production_table;

    int target; // 包含所有的文法
};

/**
 *  语法树
 */
struct syntax_tree {
    struct node {
        int production_id;
        string raw; // 整颗子树的raw，懒raw，为了省空间，不一定有数据
        vector<node> son;
    };
    grammar syntax_grammar;
    node root;
};

class parsing {
public:
    static syntax_tree dfs_parsing(const string &code, const grammar &gr) {
        syntax_tree st{gr, {gr.target, "",}};
        stack<int> stk;
        stk.push(gr.target);
        if (!_dfs_parsing(code, st, stk, 0)) {
            exit(-1);
        }
        return st;
    }

    /**
     * 递归下降算法
     * @return 语法树
     */
    static bool _dfs_parsing(const string &code, syntax_tree &st,
                             stack<int> &productionMatch, int codeIndex) {
        if (codeIndex == code.size()) {
            return productionMatch.empty();
        } else {
            int firstProduction = productionMatch.top();
            productionMatch.pop();
            vector<production> expandProductionList = st.syntax_grammar.production_table[firstProduction];
            bool match = false;
            if (expandProductionList.empty()) {
                if (st.syntax_grammar.raw[firstProduction].empty()) { // 空字符一定匹配
                    match = _dfs_parsing(code, st, productionMatch, codeIndex);
                } else if (code[codeIndex] == st.syntax_grammar.raw[firstProduction][0]) { // 非空
                    match = _dfs_parsing(code, st, productionMatch, codeIndex + 1);
                }
            } else {
                for (production &expand:expandProductionList) {
                    for (int i = expand.derive.size() - 1; i >= 0; i--) {
                        productionMatch.push(expand.derive[i]);
                    }
                    if (_dfs_parsing(code, st, productionMatch, codeIndex)) {
                        match = true;
                        break;
                    }
                    for (int i = expand.derive.size() - 1; i >= 0; i--) {
                        productionMatch.pop();
                    }
                }
            }
            productionMatch.push(firstProduction);
            return match;
        }
    }
};