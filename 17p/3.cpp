#include <iostream>
#include <fstream>

int main(int args, char* argv[])
{
    using namespace std;
    if (args != 3)
    {
        cout << "Incorrect input\n";
        cout << "Usage: " << argv[0] << " filename1 filename2" << endl;
        return 0;
    }
    
    ifstream read_from(argv[1]);
    ofstream write_to(argv[2]);
    
    if (!read_from.is_open())
    {
        cout << "Can't open " << argv[1] << endl;
        return 0;
    }
    
    if (!write_to.is_open())
    {
        cout << "Can't open " << argv[2] << endl;
        return 0;
    }
    
    char ch;
    while(read_from.get(ch))
        write_to << ch;
    
    return 0;
}
