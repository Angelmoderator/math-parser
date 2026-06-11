
#include "tokenizer.h"
#include <vector>
#include <iostream>
#include "token.h"


std::vector<Token> tokenize(const std::string& s){
  std::vector<Token> L; // То что должны вернуть как вектор типа токентов
  double num(0), drop(10); // Впременное число и ограничетель дробного числа его глубина  
  int p(0);   // - кол-во дробных чисел п осле запятой
  bool dot(0); // - наличие точки у числа   
  for (size_t i = 0; i < s.size()+1; i++){        // s[size()] — это '\0'
    if (s[i] == ' ') continue;                    // пробле - пропуск
    if (s[i] == '.') {dot = 1; continue;}                     // наличие точки у числа 
    else if (s[i] >= '0' && s[i] <= '9' ){        // Вычисление числа
      
      if (!dot) { num = num * 10.0 + s[i] - '0';              }
      else      { num = num + ((s[i] - '0') / drop); drop *= 10;}  
      p++; continue;
    }
    else if(p != 0) { // сброс: числа, наличие точки, глубины точки, и последовательности числа и возвращения числа  
      L.push_back({TokenType::Number, num, ' '});
      p = 0; dot = 0; drop = 10; num = 0;
    }
    if (s[i] == '\0') break;

    if (s[i] == '(') { L.push_back({TokenType::LParen, 0, '('}); continue; } // вычесляет левую  скобку
    if (s[i] == ')') { L.push_back({TokenType::RParen, 0, ')'}); continue; } // вычесляет правую скобку

    if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-'){ // вычесляет оператор 
      L.push_back({TokenType::Operator, 0, s[i]}); continue;
    }

    std::cout << "Неправ. символ в позиций[" << i <<  "]: " << s[i] << "\n";
  }
  return L;
}


