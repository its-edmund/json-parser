#include <string>
#include "parser.h"
#include "tokenizer.h"

JSONNode* JSONParser::generate_json() {
  JSONNode* new_node = new JSONNode();
  Token* token = tokenizer->next();

  if (token->type == TokenType::OPEN_BRACE) {
    new_node->type = JSONNode::Type::OBJECT;
  } else if (token->type == TokenType::QUOTE) {
    new_node->type = JSONNode::Type::STRING;
    new_node->value.string = token->value;
  }

  return new_node;
}
