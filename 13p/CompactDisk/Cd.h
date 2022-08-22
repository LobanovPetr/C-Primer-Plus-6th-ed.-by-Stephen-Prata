#ifndef _COMPACTDISK_
#define _COMPACTDISK_

namespace mns
{
class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(const char *, const char*, int, double);
    Cd();
    virtual void Report() const;
    Cd(const Cd&) = default;
    Cd& operator=(const Cd&) = default;
    virtual ~Cd() = default;
};
}

#endif
