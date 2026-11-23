#pragma once
#include <stdint.h>
#include <string>
#include <variant>

namespace vibe {

  struct Token {
    enum class Type {
      INVALID,
      $,
      IDENTIFIER,
      NUMBER,
      STRING,
      CHAR,
      WHILE,
      FOR,
      ASSIGN,
      FALSE,
      TRUE,
      ARROW,
      COLUMN,
      COMMA,
      DOT,
      DOTDOT,
      LPAR,
      RPAR,
      LBRACE,
      RBRACE,
      LSQUARE,
      RSQUARE,
      IF,
      ELSE,
      PRINT,
      ENDLINE,
      PLUS,
      MINUS,
      STAR,
      SLASH,
      MODULO,
      AND,
      OR,
      NOT,
      EQ,
      NEQ,
      LT,
      GT,
      LEQ,
      GEQ,
    };

    Type type { };
    std::variant<std::string, double, int64_t, char> value;

    static const Token $;
    static const Token WHILE;
    static const Token FOR;
    static const Token ASSIGN;
    static const Token FALSE;
    static const Token TRUE;
    static const Token ARROW;
    static const Token COLUMN;
    static const Token COMMA;
    static const Token DOT;
    static const Token DOTDOT;
    static const Token LPAR;
    static const Token RPAR;
    static const Token LBRACE;
    static const Token RBRACE;
    static const Token LSQUARE;
    static const Token RSQUARE;
    static const Token IF;
    static const Token ELSE;
    static const Token PRINT;
    static const Token ENDLINE;
    static const Token PLUS;
    static const Token MINUS;
    static const Token STAR;
    static const Token SLASH;
    static const Token MODULO;
    static const Token AND;
    static const Token OR;
    static const Token NOT;
    static const Token EQ;
    static const Token NEQ;
    static const Token LT;
    static const Token GT;
    static const Token LEQ;
    static const Token GEQ;


    auto operator<=>(Token const&) const -> std::strong_ordering = default;
    auto operator==(Token const&) const -> bool = default;
    auto operator!=(Token const&) const -> bool = default;
  };
}
