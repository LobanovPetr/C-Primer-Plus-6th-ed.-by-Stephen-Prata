#include <new>
#include <iostream>

struct chaff
{
    char dross[20];
    int slag;
};

void showchaff(const chaff&);

static char buffer[sizeof(chaff) * 2];

int main()
{
    using std::cout;
    using std::endl;
    chaff * bc = new (buffer) chaff[2] {{"hello", 1}, {"hi", 2}};
    
    cout << "bc address: " << (void *)bc << endl;
    showchaff(bc[0]);
    showchaff(bc[1]);
    
    void * bfr = new char[sizeof(chaff) * 2];
    chaff * hc = new (bfr) chaff[2] {{"it's heap", 3}, {"cool!", 4}};
    cout << "hc address: " << (void *)hc << endl;
    showchaff(hc[0]);
    showchaff(hc[1]);
    
    return 0;
}

void showchaff(const chaff& c)
{
    using std::cout;
    using std::endl;
    cout << c.dross << ' ' << c.slag << endl;
    return;
}
