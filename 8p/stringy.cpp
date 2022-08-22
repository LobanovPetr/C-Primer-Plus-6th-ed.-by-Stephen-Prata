#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
    char * str;
    int ct;
};

void set(stringy&, const char*);
void show(const stringy&, int = 1);
void show(const char*, int = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    delete [] beany.str;
    return 0;
}

void set(stringy& stry, const char* str)
{
    int size = strlen(str);
    stry.ct = size;
    stry.str = new char[size + 1];
    stry.str[size] = '\0';
    while(size--)
        stry.str[size] = str[size];
    return;
}

void show(const stringy& stry, int cnt)
{
    using std::cout;
    using std::endl;
    while(cnt--)
        cout << stry.str << endl;
    return;
}

void show(const char* str, int cnt)
{
    using std::cout;
    using std::endl;
    while(cnt--)
        cout << str << endl;
    return;
}


