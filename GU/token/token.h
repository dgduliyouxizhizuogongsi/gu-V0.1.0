#pragma once


#include <string>
#include <map>
using std::string;
namespace gu
{
    namespace token
    {
        class Token{
        public:
            enum Type{
                TOKEN_ILLEGAL=0,
                TOKEN_EOF,
                TOKEN_INTEGER,
                TOKEN_PLUS,
                TOKEN_MINUS,
                TOKEN_ASTERISK,
                TOKEN_SLASH,
                TOKEN_LPAREN,
                TOKEN_RPAREN,
                TOKEN_SEMICOLON,
            };

            Token();
            Token(Type type,const string & literal);
            ~Token()=default;

            Type type() const;
            string name() const;
            string literal() const;

            Token & operator=(const Token & other);

        private:
            Type m_type;
            string m_literal;
            static std::map<Type,string> m_names;
        };
    }
}