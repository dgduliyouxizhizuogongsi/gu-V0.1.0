#include <lexer/lexer.h>
using namespace gu::lexer;

Lexer::Lexer()
{
    m_ch=0;
    m_pos=0;
    m_next_pos=0;
}

Lexer::Lexer(const string & file)
{
    m_ch=0;
    m_pos=0;
    m_next_pos=0;

    std::ifstream  ifs(file);
    if(!ifs.good())
    {
        std::cout<<"file not found:"<<file<<std::endl;
        return;
    }

    std::ostringstream  oss;
    oss<<ifs.rdbuf();
    m_input=oss.str();
}

Token Lexer::next_token()
{
    read_char();
    skip_white_space();
    /*switch (m_ch) {
        case '+':
        {
            break;
        }
    }*/
}

void Lexer::skip_white_space()
{
    while(m_ch==' '||m_ch=='\t'||m_ch=='\n'||m_ch=='\r')
    {
        read_char();
    }
}
void Lexer::read_char()
{
    if(m_next_pos>=m_input.length())
    {
        m_ch=0;
    }
    else
    {
        m_ch=m_input[m_next_pos];
    }
    m_pos=m_next_pos;
    m_next_pos++;
}
void Lexer::unread_char()
{
    m_next_pos=m_pos;
    m_pos--;
}
bool Lexer::is_digit(char ch)
{
    return (ch>='0'&&ch<='9');
}
string Lexer::read_number()
{
    int pos=m_pos;
    while ((is_digit(m_ch)))
    {
        read_char();
    }
    return m_input.substr(pos,m_pos);
}
Token Lexer::new_Token(Token::Type type,const string & literal)
{
    Token token(type,literal);
    return token;
}