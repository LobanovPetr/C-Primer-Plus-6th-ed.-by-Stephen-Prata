#include <iostream>

int replace(char * str, char c1, char c2);
int judge(int (*)(const char*));
int code(const char*);

struct applicant
{
    char name[30];
    int credit_range[3];
};

void show(const applicant*);

const char * func(const applicant*, const applicant*);

typedef void (*)(const applicant) p_func1;
typedef const char * (*)(const applicant*, const applicant*) p_func2;

int main()
{
    using std::cout;
    using std::cin;
    using std::string;
    using std::endl;
    
    char a[] {"hello"};
    cout << a << endl;
    cout << replace(a, 'l', 'p') << endl;
    cout << a << endl;
    
    cout << judge(code) << endl;
    
    p_func1 pshow = show;
    p_func2 pfunc = func;
    
    p_func1 ppshow[5];
    const char * (*[10])(const applicant*, const applicant*) ppfunc;
    p_func2 (*ppfunc)[10]
    
    return 0;
}

int replace(char * str, char c1, char c2)
{
    int count = 0;
    for (; (*str) != '\0'; ++str)
    {
        if ((*str) == c1)
        {
            (*str) = c2;
            ++count;
        }
    }
    return count;
}

int judge(int (*f)(const char*))
{
    return f("judge");
}

int code(const char* s)
{
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}
