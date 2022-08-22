// asks user to enter the number of patrons
// asks to enter their names and donations
// shows separatly who donated more than 10000
// and less

#include <iostream>

struct patron {
    char name[50];
    double donation;
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    int size = 0;
    cout << "Enter the number of patrons: \n";
    
    if (!(cin >> size))
        return 1;
    
    cin.get();
    
    if (size < 0)
        return 1;
    
    patron* patrons = new patron[size];
    
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter the name of " << i << " patron: ";
        if (!(cin.getline(patrons[i].name, 50)))
        {
            delete [] patrons;
            return 1;
        }
        cout << "Enter the donation: ";
        if (!(cin >> patrons[i].donation))
        {
            delete [] patrons;
            return 1;
        }
        cin.get();
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
