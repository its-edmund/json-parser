#include <iostream>
#include <fstream>
#include <string>
#include "tokenizer.h"

int main() {
  Tokenizer tokenizer("example.json");

  for (size_t i = 0; i < tokenizer.tokens.size(); i++) {
    std::cout << tokenizer.tokens[i]->value << "\n";
  }

  return 0;
}
