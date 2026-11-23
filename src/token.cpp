#include <vibe/token.h>


namespace vibe {
  const Token Token::$ = {
    .type = Token::Type::$,
    .value = "",
  };
  const Token Token::WHILE = {
    .type = Token::Type::WHILE,
    .value = "while",
  };
  const Token Token::FOR = {
    .type = Token::Type::FOR,
    .value = "for",
  };
  const Token Token::ASSIGN = {
    .type = Token::Type::ASSIGN,
    .value = "=",
  };
  const Token Token::FALSE = {
    .type = Token::Type::FALSE,
    .value = "false",
  };
  const Token Token::TRUE = {
    .type = Token::Type::TRUE,
    .value = "true",
  };
  const Token Token::ARROW = {
    .type = Token::Type::ARROW,
    .value = "=>",
  };
  const Token Token::COLUMN = {
    .type = Token::Type::COLUMN,
    .value = ":",
  };
  const Token Token::COMMA = {
    .type = Token::Type::COMMA,
    .value = ",",
  };
  const Token Token::DOT = {
    .type = Token::Type::DOT,
    .value = ".",
  };
  const Token Token::DOTDOT = {
    .type = Token::Type::DOTDOT,
    .value = "..",
  };
  const Token Token::LPAR = {
    .type = Token::Type::LPAR,
    .value = "(",
  };
  const Token Token::RPAR = {
    .type = Token::Type::RPAR,
    .value = ")",
  };
  const Token Token::LBRACE = {
    .type = Token::Type::LBRACE,
    .value = "{",
  };
  const Token Token::RBRACE = {
    .type = Token::Type::RBRACE,
    .value = "}",
  };
  const Token Token::LSQUARE = {
    .type = Token::Type::LSQUARE,
    .value = "[",
  };
  const Token Token::RSQUARE = {
    .type = Token::Type::RSQUARE,
    .value = "]",
  };
  const Token Token::IF = {
    .type = Token::Type::IF,
    .value = "if",
  };
  const Token Token::ELSE = {
    .type = Token::Type::ELSE,
    .value = "else",
  };
  const Token Token::PRINT = {
    .type = Token::Type::PRINT,
    .value = "print",
  };
  const Token Token::ENDLINE = {
    .type = Token::Type::ENDLINE,
    .value = "\n",
  };
  const Token Token::PLUS = {
    .type = Token::Type::PLUS,
    .value = "+",
  };
  const Token Token::MINUS = {
    .type = Token::Type::MINUS,
    .value = "-",
  };
  const Token Token::STAR = {
    .type = Token::Type::STAR,
    .value = "*",
  };
  const Token Token::SLASH = {
    .type = Token::Type::SLASH,
    .value = "/",
  };
  const Token Token::MODULO = {
    .type = Token::Type::MODULO,
    .value = "%",
  };
  const Token Token::AND = {
    .type = Token::Type::AND,
    .value = "&&",
  };
  const Token Token::OR = {
    .type = Token::Type::OR,
    .value = "||",
  };
  const Token Token::NOT = {
    .type = Token::Type::NOT,
    .value = "!",
  };
  const Token Token::EQ = {
    .type = Token::Type::EQ,
    .value = "==",
  };
  const Token Token::NEQ = {
    .type = Token::Type::NEQ,
    .value = "!=",
  };
  const Token Token::LT = {
    .type = Token::Type::LT,
    .value = "<",
  };
  const Token Token::GT = {
    .type = Token::Type::GT,
    .value = ">",
  };
  const Token Token::LEQ = {
    .type = Token::Type::LEQ,
    .value = "<=",
  };
  const Token Token::GEQ = {
    .type = Token::Type::GEQ,
    .value = ">=",
  };
}
