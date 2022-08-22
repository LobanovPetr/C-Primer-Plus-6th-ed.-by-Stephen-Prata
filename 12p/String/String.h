#ifndef _STRING_
#define _STRING_

#include <cstddef>
namespace msc
{
typedef std::size_t ssize;
class String
{
private:
    char * str;
    ssize size;
    String(ssize);
public:
    String();
    String(ssize, char);
    String(const String&);
    String(const char *);
    String& operator=(const String&);
    operator const char*() const;
    char& operator[](ssize i);
    const char& operator[](ssize i) const;
    const String stringlow() const;
    const String stringup() const;
    ssize count(char) const;
    ssize Size() {return size;}
    
    //friend std::ostream& operator(std::ostream&, const String&)
    friend const String operator+(const String&, const String&);
    
    ~String();
};
const String operator+(const String&, const String&);
}

#endif
