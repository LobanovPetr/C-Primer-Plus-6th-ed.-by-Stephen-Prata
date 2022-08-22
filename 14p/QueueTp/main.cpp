#include "QueueTp.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using mns::Queue;

int main()
{
    Queue<int> q, q1;
    q.push(5);
    q.push(6);
    q.push(7);
    
    q1 = q;
    cout << q1.size() << endl;

    
    return 0;
}
