// read the file with patrons
// and show the gread patrons and usual

#include <iostream>
#include <fstream>

struct patron {
    char name[50];
    double donation;
};

int main()
{
    using std::ifstream;
    using std::cout;
    using std::endl;
    using std::cin;
    
    int size = 0;
    ifstream fin;
    char filename[50];
    
    cout << "Enter the filename: ";
    cin.getline(filename, 50);
    
    fin.open(filename);
    
    if (!fin.is_open())
    {
        cout << "Can't open the file.\n";
        return 1;
    }
    
    if (!(fin >> size))
    {
        cout << "Incorrect file.\n";
        return 1;
    }
    fin.get();
    
    if (size < 0)
    {
        cout << "Size is less then 0.\n";
        return 1;
    }
    
    patron* patrons = new patron[size];
    
    for (int i = 0; i < size; ++i)
    {
        if (!(fin.getline(patrons[i].name, 50)))
        {
            cout << "Incorrect number of strings.\n";
            delete [] patrons;
            return 1;
        }
        if (!(fin >> patrons[i].donation))
        {
            cout << "Incorrect numeric format.\n";
            delete [] patrons;
            return 1;
        }
        fin.get();
    }
    
    cout << "Great patrons:\n";
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (patrons[i].donation >= 10000.)
        {
            count++;
            cout << patrons[i].name << ' ' << patrons[i].donation
                 << endl;
        }
    }
    if (!count)
    {
        cout << "none\n";
    }
    count = 0;
    
    cout << "Patrons: " << endl;
    
    for (int i = 0; i < size; ++i)
    {
        if (patrons[i].donation < 10000.)
        {
            count++;
            cout << patrons[i].name << ' ' << patrons[i].donation
                 << endl;
        }
    }
    
    delete [] patrons;
    return 0;
}
