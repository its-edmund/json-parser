#include <string>
#include <fstream>
#include <vector>

#ifndef H_TOKENIZER

#define H_TOKENIZER

enum class TokenType {
  OPEN_BRACE,
  CLOSE_BRACE,
  OPEN_BRACKET,
  CLOSE_BRACKET,
  COLON,
  QUOTE,
  STRING,
  NUMBER,
  COMMA,
  BOOLEAN
};


struct Token {
  TokenType type;
  std::string value;
  std::string toString();
};

class Tokenizer {
  std::fstream file;
  size_t position;
  
  public:
    std::vector<Token*> tokens;
    Tokenizer(std::string filename);
    Token* next();
    bool hasNext();
};

#endif // !H_TOKENIZER
