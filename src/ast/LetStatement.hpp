#ifndef LETSTATEMENT_HPP
#define LETSTATEMENT_HPP

#include <memory>

#include "../token/Token.hpp"
#include "./basic/Expression.hpp"
#include "./basic/Node.hpp"
#include "./basic/Statement.hpp"
#include "Identifier.hpp"

using namespace std;

namespace mirror {
class LetStatement : public Statement {
   public:
    unique_ptr<Token> m_token;  // the token.LET token
    unique_ptr<Identifier> m_name;
    unique_ptr<Expression> m_value;

   public:
    LetStatement() = default;
    LetStatement(LetStatement& other) {
        m_token = make_unique<Token>(*other.m_token);
        m_name = make_unique<Identifier>(*other.m_name);
        m_value = make_unique<Expression>(*other.m_value);
    };
    LetStatement(Token& token, unique_ptr<Identifier> name,
                 unique_ptr<Expression> value)
        : m_token(new Token(token)),
          m_name(std::move(name)),
          m_value(std::move(value)){};
    LetStatement(Token& token) : m_token(new Token(token)){};
    ~LetStatement(){};

   public:
    string token_literal() { return m_token->m_literal; };
    string to_string() {
        string ret = token_literal() + " " + m_name->to_string() + " = " +
                     m_value->to_string() + ";";
        return ret;
    };
};
}  // namespace mirror
#endif /* LETSTATEMENT_HPP */
