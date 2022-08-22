#include "String.h"
#include <cstring>
#include <cctype>

namespace msc
{

String::String()
{
    str = new char[1];
    str[0] = '\0';
    size = 0;
}

String::String(ssize i, char c)
{
    str = new char[i + 1];
    str[i] = '\0';
    size = i;
    while(i--) str[i] = c;
}

String::String(ssize i)
{
    str = new char[i + 1];
    str[i] = '\0';
    size = i;
}

String::String(const char * s)
{
    size = std::strlen(s);
    str = new char[size + 1];
    std::strcpy(str, s);
}

String::String(const String& s)
{
    str = new char[s.size + 1];
    std::strcpy(str, s.str);
    size = s.size;
}
String& String::operator=(const String& s)
{
    if (this == &s)
        return *this;
    if (s.size > size)
    {
        delete [] str;
        str = new char[s.size + 1];
    }
    std::strcpy(str, s.str);
    size = s.size;
    return *this;
}

String::operator const char*() const
{
    return str;
}

char& String::operator[](ssize i)
{
    return str[i];
}

const char& String::operator[](ssize i) const
{
    return str[i];
}

const String String::stringlow() const
{
    String s(*this);
    for (ssize i = 0; i < size; ++i)
        s.str[i] = std::tolower(s.str[i]);
    return s;
}

const String String::stringup() const
{
    String s(*this);
    for (ssize i = 0; i < size; ++i)
        s.str[i] = std::toupper(s.str[i]);
    return s;
}

ssize String::count(char c) const
{
    ssize cnt = 0;
    for (ssize i = 0; i < size; ++i)
        if (str[i] == c) cnt++;
    return cnt;
}

const String operator+(const String& s1, const String& s2)
{
    String s(s1.size + s2.size);
    std::strcpy(s.str, s1.str);
    std::strcat(s.str, s2.str);
    return s;
}
String::~String()
{
    delete [] str;
}

}
