#pragma once

enum class TokenType {Number, Operator, LParen, RParen };
struct Token { TokenType type; double value; char op;};
