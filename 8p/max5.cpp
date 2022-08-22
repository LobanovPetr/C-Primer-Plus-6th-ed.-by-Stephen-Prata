// prog shows max element from the array of 5 elements
#include <iostream>
template<typename T>
const T& max5(const T []);

int main()
{
    using std::cout;
    using std::endl;
    int a[5] {1, 2, 3, -1, 2};
    cout << max5(a) << endl;
    
    double b[5] {1., 2., 2.5};
    cout << max5(b) << endl;
    return 0;
}

template<typename T>
const T& max5(const T arr[])
{
    const T* tmp = arr;
    for (int i = 1; i < 5; ++i)
    {
        if (*tmp < arr[i])
            tmp = arr + i;
    }
    return *tmp;
}
