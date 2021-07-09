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

