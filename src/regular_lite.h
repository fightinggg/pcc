#include "nfa.h"

/**
 *  key: [ ] ( ) * \
 */
struct reg_lite_token {
  bool is_key;
  char word;
};

void regLiteParse(char* code);

void lexical_analysis(char* code);