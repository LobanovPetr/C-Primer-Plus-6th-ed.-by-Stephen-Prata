#ifndef PORT_
#define PORT_

#include <iostream>

namespace mns
{
using std::ostream;
class Port
{
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char* = "none", const char * ="none", int = 0);
    Port(const Port&);
    virtual ~Port() { delete [] brand;}
    Port& operator=(const Port&);
    Port& operator+=(int);
    Port& operator-=(int);
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream& operator<<(ostream& os, const Port& p);
};

ostream& operator<<(ostream& os, const Port& p);

class VintagePort : public Port
{
private:
    char * nickname;
    int year;
public:
    VintagePort(const char* = "none", int = 0, const char * = "none", int = -1);
    VintagePort(const VintagePort&);
    ~VintagePort() { delete [] nickname; }
    virtual VintagePort& operator=(const VintagePort&);
    void Show() const;
    friend ostream& operator<<(ostream& os, const VintagePort& p);
};
ostream& operator<<(ostream& os, const VintagePort& p);
}

#endif
