#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    using namespace std;
    if (argc != 4)
    {
        cout << "Incorrect input\n";
        cout << "Usage: " << argv[0] << " filename1 filename2\n";
        return 0;
    }
    ifstream input1(argv[1]);
    ifstream input2(argv[2]);
    ofstream output(argv[3]);
    if (!input1.is_open())
    {
        cout << "Can't open " << argv[1] << endl;
        return 0;
    }
    if (!input2.is_open())
    {
        cout << "Can't open " << argv[2] << endl;
        return 0;
    }
    if (!output.is_open())
    {
        cout << "Can't open " << argv[3] << endl;
        return 0;
    }
    while ((input1 || input2) && output)
    {
        char ch;
        bool read_first = false;
        input1.get(ch);
        if (input1 && ch != '\n')
        {
            read_first = true;
            output << ch;
        }
        
        while(input1.get(ch) && ch != '\n')
            output << ch;
        
        input2.get(ch);
        if (input2 && ch != '\n')
        {
            output << " ";
            output << ch;
        }
        while(input2.get(ch) && ch != '\n')
            output << ch;
        output << endl;
    }
    return 0;
}
