#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ctime>
using namespace std;

int main()
{
    const size_t N = 10000000;
    srand(time(0));
    vector<int> vi0(N);
    for (auto& it: vi0) it = rand() % N;
    vector<int> vi(vi0.begin(), vi0.end());
    list<int> li(vi0.begin(), vi0.end());
    
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "Time for sorting array: ";
    cout << (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl;
    
    start = clock();
    li.sort();
    end = clock();
    cout << "Time for sorting list: ";
    cout << (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl;
    
    
    
}
