// using the pointer to function to emplement calculator

#include <iostream>

typedef double (*p_func)(double, double);

double calculat(double, double, p_func);
double add(double, double);
double subtract(double, double);
double divide(double, double);
double product(double, double);

int char_to_fun_idx(char);


int main()
{
    using namespace std;
    p_func functions[] {add, subtract, divide, product};
    int idx;
    double x, y;
    char ch;
    while(cout << "Enter the formula to calculate, q to exit\n" && cin >> x >> ch >> y)
    {
        idx = char_to_fun_idx(ch);
        if (idx < 0)
        {
            cout << "Incorrect input.\n";
            continue;
        }
        cout << calculat(x, y, functions[idx]) << endl;
    }
    return 0;
}

int char_to_fun_idx(char ch)
{
    switch (ch)
    {
        case '+':
            return 0;
        case '-':
            return 1;
        case '/':
            return 2;
        case '*':
            return 3;
    }
    return -1;
}

double calculat(double x, double y, double (*func)(double, double))
{
    return func(x, y);
}

double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double divide(double x, double y)
{
    return x / y;
}

double product(double x, double y)
{
    return x * y;
}
