#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
    using std::list;
    using std::cout;
    using std::endl;
    
    int vals[] {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);
    auto outline = [](int x){cout << x << " ";};
    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outline);
    cout << endl;
    
    for_each(etcetera.begin(), etcetera.end(), outline);
    cout << endl;
    yadayada.remove_if([](int x){return x > 100;});
    etcetera.remove_if([](int x){return x > 200;});
    
    for_each(yadayada.begin(), yadayada.end(), outline);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outline);
    cout << endl;
    return 0;
}
