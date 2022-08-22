#ifndef _CLASSIC_
#define _CLASSIC_
#include "Cd.h"

namespace mns
{
class Classic: public Cd
{
private:
    char producer[40];
public:
    Classic();
    Classic(const char*, const char*, const char*, int, double);
    virtual void Report() const;
};
}

#endif
