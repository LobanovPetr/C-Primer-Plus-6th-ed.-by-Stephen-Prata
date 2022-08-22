// opens file to read.
// reads all symbols, inform about number of symbols

#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    ifstream fin;
    char filename[50];
    char tmp;
    int count = 0;
    
    cout << "Enter the file name: ";
    cin.getline(filename, 50);
    
    fin.open(filename);
    if (!fin.is_open())
    {
        cout << "Can't open the file.\n";
        return 1;
    }
    
    while(fin >> tmp)
    {
        count++;
    }
    
    if (!fin.eof())
    {
        cout << "Problem with reading file\n";
        return 1;
    }
    
    cout << "There are " << count << " symbols\n";
}

