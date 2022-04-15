#ifndef RETURNSTATEMENT_HPP
#define RETURNSTATEMENT_HPP

#include <memory>

#include "../token/Token.hpp"
#include "./basic/Expression.hpp"
#include "./basic/Statement.hpp"

using namespace std;

namespace mirror {
class ReturnStatement : public Statement {
   public:
    unique_ptr<Token> m_token;  // the token.LET token
    unique_ptr<Expression> m_return_value;

   public:
    ReturnStatement(Token& token) : m_token(new Token(token)){};
    ~ReturnStatement(){};

   public:
    string token_literal() override { return m_token->m_literal; };
    string to_string() override {
        string ret = token_literal() + " " + m_return_value->to_string() + ";";
        return ret;
    };
};
}  // namespace mirror
#endif /* RETURNSTATEMENT_HPP */
