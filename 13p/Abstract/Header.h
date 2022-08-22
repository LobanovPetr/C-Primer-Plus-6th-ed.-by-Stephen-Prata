#ifndef HEADER_
#define HEADER_
#include <iostream>
namespace mns
{

class Base
{
private:
    char * label;
    int rating;
protected:
    virtual void show(std::ostream&) const = 0;
public:
    Base(const char* = "null", int = 0);
    Base(const Base&);
    Base& operator=(const Base&);
    virtual ~Base();
    friend std::ostream& operator<<(std::ostream& os, const Base&); //implement
};

std::ostream& operator<<(std::ostream& os, const Base&);

class baseDMA: public Base
{
    virtual void show(std::ostream&) const;
public:
    baseDMA(const char * = "null", int = 0);
//    baseDMA(const baseDMA&);
//    baseDMA& operator=(const baseDMA&);
//    virtual ~baseDMA();
};

class lacksDMA: public Base
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
    virtual void show(std::ostream&) const;
public:
    lacksDMA(const char * = "blank", const char * = "null", int = 0);
    lacksDMA(const char *, const Base&);
    // operator= and desturctor are not needed
};

class hasDMA: public Base
{
private:
    virtual void show(std::ostream&) const;
    char * style;
public:
    hasDMA(const char* = "none", const char * = "null", int = 0);
    hasDMA(const char *, const Base&); // first arg is style
    hasDMA(const hasDMA&);
    hasDMA& operator=(const hasDMA&);
    virtual ~hasDMA();
};

}
#endif
