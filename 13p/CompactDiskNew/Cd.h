#ifndef _COMPACTDISK_
#define _COMPACTDISK_

namespace mns
{
class Cd
{
private:
    char *performers;
    char *label;
    int selections;
    double playtime;
public:
    Cd(const char *, const char*, int, double);
    Cd();
    virtual void Report() const;
    Cd(const Cd&);
    Cd& operator=(const Cd&);
    virtual ~Cd();
};
}

#endif
