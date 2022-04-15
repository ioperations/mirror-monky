#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include <memory>
#include <string>

#include "../token/Token.hpp"
#include "./basic/Expression.hpp"

using namespace std;

namespace mirror {
// Expressions
class Identifier : public Expression {
   public:
    unique_ptr<Token> m_token;  // the token.IDENT token
    string m_value;

   public:
    Identifier() = default;
    Identifier(Identifier& ident)
        : m_token(make_unique<Token>(*ident.m_token)), m_value(ident.m_value){};
    Identifier(Token& token, string value)
        : m_token(new Token(token)), m_value(value){};

   public:
    string token_literal() { return m_token->m_literal; };
    string to_string() { return m_value; };
};
}  // namespace mirror
#endif /* IDENTIFIER_HPP */
