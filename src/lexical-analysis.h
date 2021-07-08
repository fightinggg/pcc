#pragma once
#include <string>

using namespace std;

const string INCLUDE_LIB_MACRO = "#include<.*>";
const string INCLUDE_FILE_MACRO = R"(#include".*")";
const string VAR = "[_a-zA-Z][_a-zA-Z0-9]+";
const string INT = "^[+-]?((0)|([1-9][0-9]*))$";
const string HEX_INT = "0x[0-9a-fA-F]";
