#include <iostream>
#include <vector>
#include "token.h"
#include "tokenizer.h"

int main(){

  std::cout << "Hello world\n"; 
  std::vector<Token> tokens = tokenize("12.5+3/2");

  for (const auto& t : tokens) {
        if (t.type == TokenType::Operator)  std::cout << "Нашли оператор: "      << t.op    << '\n';
        if (t.type == TokenType::Number)    std::cout << "Нашли число: "         << t.value << '\n';
        if (t.type == TokenType::LParen)    std::cout << "Нашли левую скобку: "  << t.op    << '\n';
        if (t.type == TokenType::RParen)    std::cout << "Нашли правую скобку: " << t.op    << '\n';
  }


  return 0;
}
