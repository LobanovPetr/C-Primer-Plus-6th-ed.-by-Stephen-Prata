#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ctime>

using namespace std;

int myrand(int i) {return std::rand() % i;}
vector<int> Lotto(int, int);

vector<int> Lotto(int size, int nums)
{
    vector<int> v(size);
    v[0] = 1;
    for (int i = 1; i < size; ++i) v[i] = v[i - 1] + 1;
    random_shuffle(v.begin(), v.end(), myrand);
    sort(v.begin(), v.begin() + nums);
    return vector<int>(v.begin(), v.begin() + nums);
}

int main()
{
    std::srand(std::time(NULL));
    auto v = Lotto(11, 4);
    copy(v.begin(), v.end(), ostream_iterator<int, char>(cout, " "));
    cout << endl;
    return 0;
}
