
#include<cstdio>
#include <iostream>
#include "nfa.hpp"
#include "regex_lite.hpp"
#include "parsing.hpp"

using namespace std;

string code = "\n"
              "#include<cstdio>\n"
              "#include <iostream>\n"
              "#include \"nfa.hpp\"\n"
              "#include \"regex_lite.hpp\"\n"
              "#include \"parsing.hpp\"\n"
              "\n"
              "using namespace std;\n"
              "\n"
              "string code = \"\"\n"
              "\n"
              "int main() {\n"
              "    printf(\"hello pcc\\n\");\n"
              "    parsing::_dfs_parsing(\"\");\n"
              "\n"
              "}";

int main() {
    printf("hello pcc\n");
    grammar gr;
    parsing::dfs_parsing(code, gr);

}