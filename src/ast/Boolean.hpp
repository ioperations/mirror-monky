#ifndef BOOLEAN_HPP
#define BOOLEAN_HPP

#include <memory>

#include "../token/Token.hpp"
#include "./basic/Expression.hpp"

using namespace std;

namespace mirror {
namespace ast {

class Boolean : public Expression {
   public:
    unique_ptr<Token> m_token;
    bool m_value;

   public:
    Boolean(Token& token, bool b) : m_token(new Token(token)), m_value(b) {}

   public:
    string token_literal() { return m_token->m_literal; };
    string to_string() { return m_token->m_literal; };
};
}  // namespace ast
}  // namespace mirror
#endif /* BOOLEAN_HPP */
