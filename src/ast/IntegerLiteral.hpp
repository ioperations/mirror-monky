#ifndef INTEGERLITERAL_HPP
#define INTEGERLITERAL_HPP

#include <memory>
#include <string>

#include "../token/Token.hpp"
#include "./basic/Expression.hpp"

using namespace std;

namespace mirror {
// Expressions
class IntegerLiteral : public Expression {
   public:
    unique_ptr<Token> m_token;  // the token.IDENT token
    int64_t m_value;

    string token_literal() { return m_token->m_literal; };
    string to_string() { return std::to_string(m_value); };

   public:
    IntegerLiteral(Token& token) : m_token(new Token(token)){};
    IntegerLiteral(Token& token, int64_t value)
        : m_token(new Token(token)), m_value(value){};
};
}  // namespace mirror
#endif /* INTEGERLITERAL_HPP */
