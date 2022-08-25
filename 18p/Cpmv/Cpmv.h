#ifndef CPMV_
#define CPMV_
#include <string>
class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };
private:
    Info *pi;
public:
    Cpmv();
    Cpmv(const std::string&, const std::string&);
    Cpmv(const Cpmv&);
    Cpmv(Cpmv &&);
    ~Cpmv();
    Cpmv& operator=(const Cpmv&);
    Cpmv& operator=(Cpmv&&);
    Cpmv operator+(const Cpmv&) const;
    void Display() const;
};
#endif
