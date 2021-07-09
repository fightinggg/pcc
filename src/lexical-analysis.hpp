#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "../lib/json.hpp"

using namespace std;

struct {
  string type;
  string raw;
} token;

vector<string> lexicalAnalysis(string context, string tokenProperties) {
  using namespace nlohmann;
  json tokensList = json::parse(tokenProperties);
  for (auto& [keyObj, valueObj] : tokensList.items()) {
      regex reg(to_string(valueObj));
  }
}

#ifdef TEST
const string lexicalAnalysisTestContext = R"(
#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../lib/json.hpp"

using namespace std;

struct {
  string type;
  string raw;
} token;

vector<string> lexicalAnalysis(string context, string tokenProperties) {
  using namespace nlohmann;
  auto tokensList = json::parse(context);
  for (auto& item : tokensList) {
    if (item.is_structured()) {
      exit(-1);
    } else {
      cout << item << endl;
    }
  }
}
)";

string lexicalAnalysisTestTokenProperties = R"(
{
    "include": "#include",
    "stdlib": "<.*>",
    "var": "[_a-zA-Z][_a-zA-Z0-9]+"
}
)";
void lexicalAnalysisTest() {
  lexicalAnalysis(lexicalAnalysisTestContext,
                  lexicalAnalysisTestTokenProperties);
}
#endif
