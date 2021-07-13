#pragma once

#include <map>

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
    /**
     * 递归下降算法
     * @param code 代码
     * @param gr 文法
     * @return 语法🌲
     */
    syntax_tree dfs_parsing(const string &code, const grammar &gr) {
        for (char ch:code) {

        }
    }
};