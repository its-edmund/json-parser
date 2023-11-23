#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "tokenizer.h"

Tokenizer::Tokenizer(std::string filename) {
  std::ifstream inputFile(filename);
  char c;
  bool in_string = false;
  std::string curr_string = "";

  while (inputFile >> c) {
    if (c == ' ' || c == '\n') {
      continue;
    }

    Token* new_token = new Token;

    if (in_string) {
      if (c == '"') {
        new_token->type = TokenType::STRING;
        new_token->value = curr_string;
        curr_string = "";
        in_string = false;
      } else {
        curr_string += c;
        continue;
      }
    } else {
      switch (c) {
        case '{':
          new_token->type = TokenType::OPEN_BRACE;
          new_token->value = c;
          break;
        case '}':
          new_token->type = TokenType::CLOSE_BRACE;
          new_token->value = c;
          break;
        case '"':
          in_string = true;
          continue;
        case ':':
          new_token->type = TokenType::COLON;
          new_token->value = c;
          break;
        case ',':
          new_token->type = TokenType::COMMA;
          new_token->value = c;
          break;
        default:
          throw std::invalid_argument("Unknown token");
      }
    }
    
    tokens.push_back(new_token);
  }
}

bool Tokenizer::hasNext() {
  return position < tokens.size();
}

Token* Tokenizer::next() {
  if (hasNext()) {
    return tokens[position];
  }
  return nullptr;
}
