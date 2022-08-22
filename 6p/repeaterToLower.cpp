//reapeat a usert input and convert lower register to upper and vice verse
//skips a digets
#include <iostream>
#include <cctype>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    char ch;
    while((ch = cin.get()) != '@')
    {
        if (isdigit(ch))
            continue;
        if (isalpha(ch))
            if (islower(ch))
                cout.put(toupper(ch));
            else
                cout.put(tolower(ch));
    }
}
