#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    const int ArSize = 20;
    string name, dessert;
    
    cout << "Enter your name:\n";
    getline(cin, name);
    cout << "Enter you favorite dessert:\n";
    getline(cin, dessert);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;
    return 0;
}
