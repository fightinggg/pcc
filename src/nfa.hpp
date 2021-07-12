#pragma once

#include <vector>
#include <ostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class nfa {
public:
    const static int EMPTY_TRANS;

    class node {
    private:
        bool is_end;
        unordered_map<int, vector<node *>> trans;

    public:
        node() = delete;

        explicit node(bool is_end) : is_end(is_end) {}

        bool isEnd() const {
            return is_end;
        }

        void setIsEnd(bool isEnd) {
            is_end = isEnd;
        }

        unordered_map<int, vector<node *>> &getTrans() {
            return trans;
        }

        void setTrans(const unordered_map<int, vector<node *>> &trans) {
            node::trans = trans;
        }

    };

private:

    node *start{};
    unordered_set<node *> end;

    void initWithoutDelete(int edge) {
        node *from = new node(false);
        node *to = new node(true);
        start = from;
        start->getTrans()[edge].push_back(to);
        end.clear();
        end.insert(to);
    }

    void delete_all() {
        for (auto nd:allNode()) {
            delete nd;
        }
    }

    void copy_from(const nfa &fa) {
        unordered_map<node *, node *> mp;
        for (auto nd:fa.allNode()) {
            mp[nd] = new node(nd->isEnd());
        }
        for (auto it:mp) {
            node *old = it.first;
            node *nw = it.second;
            for (auto[edge, toList]:old->getTrans()) {
                for (auto to:toList) {
                    nw->getTrans()[edge].push_back(mp[to]);
                }
            }
        }

        start = mp[fa.start];
        end.clear();
        for (node *nd:fa.end) {
            end.insert(mp[nd]);
        }
    }

public:

    nfa() = delete;

    /**
     * ┌─────┐   edge   ┌───┐
     * │start├─────────►│end│
     * └─────┘          └───┘
     */
    explicit nfa(int edge) { initWithoutDelete(edge); }

    nfa(const nfa &fa) { copy_from(fa); }

    nfa &operator=(const nfa &fa) {
        delete_all();
        copy_from(fa);
        return *this;
    }

    ~nfa() { delete_all(); }


    vector<node *> allNode() const {
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
        return vector<node *>(se.begin(), se.end());
    }

    void selfLoop() {
        for (auto ed:end) {
            ed->getTrans()[EMPTY_TRANS].push_back(start);
        }
    }

    void tandem(nfa &fa) {
        for (auto ed:end) {
            ed->getTrans()[EMPTY_TRANS].push_back(fa.start);
            ed->setIsEnd(false);
        }
        swap(end, fa.end);
        fa.initWithoutDelete(EMPTY_TRANS);
    }

    void parallel(nfa &fa) {
        start->getTrans()[EMPTY_TRANS].push_back(fa.start);
        end.merge(fa.end);
        assert(fa.end.empty());
        fa.initWithoutDelete(EMPTY_TRANS);
    }

};

const int nfa::EMPTY_TRANS = 0;




