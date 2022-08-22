// prog shows max element from the array of 5 elements
#include <iostream>
#include <cstring>
template<typename T>
const T& maxn(const T [], int = 1);

template<>
const char* const& maxn<>(const char* const [], int);

int main()
{
    using std::cout;
    using std::endl;
    int a[5] {1, 2, 3, -1, 2};
    cout << maxn(a, 5) << endl;
    
    double b[6] {1., 2., 2.5, 3.5, -4., 6.5};
    cout << maxn(b, 6) << endl;
    
    const char* strs[] {"Hello", "it's me", "Nice to see you"};
    
    cout << maxn(strs, 3) << endl;
    return 0;
}

template<typename T>
const T& maxn(const T arr[], int size)
{
    const T* tmp = arr;
    for (int i = 1; i < size; ++i)
    {
        if (*tmp < arr[i])
            tmp = arr + i;
    }
    return *tmp;
}

template<>
const char* const& maxn(const char* const ar[], int size)
{
    const char *const * pt = &ar[0];
    for (int i = 1; i < size; ++i)
        if (strlen(*pt) < strlen(ar[i]))
            pt = &ar[i];
    return *pt;
}
