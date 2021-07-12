//#pragma once
//
//#include <string>
//
//using namespace std;
//
//class string_utils {
//public:
//    template<class T>
//    static string to_string(T *p) {
//        return std::to_string((long long) p);
//    }
//
//    template<class T>
//    static string to_string(vector<T *> vec) {
//        if (vec.empty()) {
//            return "[]";
//        }
//        string res = vec[0]->to_string();
//        for (int i = 1; i < vec.size(); i++) {
//            res += "," + vec[i]->to_string();
//        }
//        return "[" + res + "]";
//    }
//
//    static string join(vector<string> list) {
//        string res = "";
//    }
//};