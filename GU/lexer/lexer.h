#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <token/token.h>
using namespace gu::token;

namespace gu
{
    namespace lexer
    {
        class Lexer
        {
        public:
            Lexer();
            Lexer(const string & file);
            ~Lexer()=default;

            Token next_token();

        private:
            void skip_white_space();
            void read_char();
            void unread_char();
            bool is_digit(char ch);
            string read_number();
            Token new_Token(Token::Type type,const string & literal);

        private:
            string m_input;
            char m_ch;
            int m_pos;
            int m_next_pos;
        };
    }
}