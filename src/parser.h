#include <string>
#include <vector>
#include <map>
#include "tokenizer.h"

#ifndef H_PARSER
#define H_PARSER

struct JSONNode {
  enum class Type { OBJECT, LIST, STRING, NUMBER, BOOLEAN, NULL_TYPE };
  union Value {
    std::string string;
    std::vector<JSONNode*> json_list;
    std::map<std::string, JSONNode*> json_object;
    float float_value;
    bool bool_value;
  } value;
  Type type;
};

class JSONParser {
  public:
    JSONParser(std::string filename) {
      tokenizer = new Tokenizer(filename);
    }
    JSONNode* root;
    JSONNode* generate_json();
    Tokenizer* tokenizer;
};

#endif // !H_PARSER
