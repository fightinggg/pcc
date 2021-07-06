#include "regular_lite.h"

#include <stdbool.h>

const char keys_arr[] = {'\\', '(', ')', '[', ']', '*'};

bool isRegLiteKey(char ch) {
  for (int i = 0; i < sizeof(keys_arr); i++) {
    if (ch == keys_arr[i]) return true;
  }
  return false;
}

void regLiteParse(char* code) {}

void lexical_analysis(char* code){
  bool escape = false;
  for (char ch : regular_code) {
    if (escape) {
      if (std::find(keys_arr.begin(), keys_arr.end(), ch) == keys_arr.end()) {
        std::cerr << "error escape" << std::endl;
        exit(-1);
      }
      tokens.push_back({token::token_type::key, ch});
    } else {
      tokens.push_back({token::token_type::word, ch});
    }
  }
}
