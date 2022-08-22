#include "Tv.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace mns;

int main()
{
    Tv Philips(Tv::On);
    Remote controller;
    
    cout << "Tv settings:\n";
    Philips.settings();
    cout << endl;
    
    controller.volup(Philips);
    controller.set_chan(Philips, 100);
    
    cout << "Tv settings:\n";
    Philips.settings();
    cout << endl;
    
    cout << "Remote regim:\n";
    controller.show_regim();
    cout << endl;
    
    Philips.change_regim(controller);
    
    cout << "Remote regim:\n";
    controller.show_regim();
    cout << endl;
    
    
    return 0;
}
