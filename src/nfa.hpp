#pragma once

#include <ostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class nfa {
private:
    class node {
    private:
        int type;
        unordered_map<int, vector<node *>> trans;

    public:
        const static int EMPTY_TRANS = 0;

        const static int START_NODE_TYPE = 1;
        const static int NORMAL_NODE_TYPE = 2;
        const static int END_NODE_TYPE = 4;

        node() = delete;

        explicit node(int type) : type(type) {}

        bool isType(int type) {
            return this->type & type;
        }

        int getType() {
            return type;
        }

        void setType(int type) {
            this->type |= type;
        }

        void removeType(int type) {
            if (isType(type)) {
                this->type ^= type;
            }
        }

        unordered_map<int, vector<node *>> &getTrans() {
            return trans;
        }

        void setTrans(const unordered_map<int, vector<node *>> &trans) {
            node::trans = trans;
        }

    };

    node *start{};
    unordered_set<node *> end;

    void initWithoutDelete(int edge) {
        node *from = new node(node::START_NODE_TYPE);
        node *to = new node(node::END_NODE_TYPE);
        start = from;
        start->getTrans()[edge].push_back(to);
        end.clear();
        end.insert(to);
    }

public:

    nfa() = delete;

    /**
     * ┌─────┐   edge   ┌───┐
     * │start├─────────►│end│
     * └─────┘          └───┘
     */
    explicit nfa(int edge) { initWithoutDelete(edge); }

    nfa(const nfa &fa) {
        unordered_map<node *, node *> mp;
        auto makeAvliable = [&mp](node *old) {
            if (mp.find(old) == mp.end()) {
                return mp.find(old)->second;
            } else {
                return mp[old] = new node(old->getType());
            }
        };
        stack<node *> stk;
        stk.push(start);

        unordered_set<node *> se;
        while (!stk.empty()) {
            node *top = stk.top();
            stk.pop();
            if (se.find(top) != se.end()) { continue; }
            se.insert(top);
            node *nw = makeAvliable(top);

            for (const auto &item: top->getTrans()) {
                for (node *son:item.second) {
                    stk.push(son);
                    nw->getTrans()[item.first].push_back(makeAvliable(son));
                }
            }
        }

        start = makeAvliable(start);
        for (node *nd:fa.end) {
            end.insert(makeAvliable(nd));
        }
    }

    ~nfa() {
        stack<node *> stk;
        stk.push(start);

        unordered_set<node *> se;
        while (!stk.empty()) {
            node *top = stk.top();
            stk.pop();
            if (se.find(top) != se.end()) { continue; }
            se.insert(top);
            for (const auto &item: top->getTrans()) {
                for (node *son:item.second) {
                    stk.push(son);
                }
            }
        }

        for (auto nd:se) {
            delete nd;
        }
    }


    void selfLoop() {
        for (auto ed:end) {
            ed->getTrans()[node::EMPTY_TRANS].push_back(start);
        }
    }

    void tandem(nfa &fa) {
        for (auto ed:end) {
            ed->getTrans()[node::EMPTY_TRANS].push_back(fa.start);
        }
        swap(end, fa.end);
    }

};


