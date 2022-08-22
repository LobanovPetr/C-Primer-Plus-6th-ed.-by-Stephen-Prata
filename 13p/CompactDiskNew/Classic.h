#ifndef _CLASSIC_
#define _CLASSIC_
#include "Cd.h"

namespace mns
{
class Classic: public Cd
{
private:
    char* producer;
public:
    Classic();
    Classic(const char*, const char*, const char*, int, double);
    Classic(const Classic&);
    Classic& operator=(const Classic&);
    
    virtual void Report() const;
    virtual ~Classic();
};
}

#endif
