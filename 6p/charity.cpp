// reads under 10 values of donation to array
// stops if usert input not a number
// shows average value and number of donations
// that are more than average

#include<iostream>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    double donations[10];
    int num = 0;
    double sum = 0;
    double average = 0;
    int moreThenAv = 0;
    
    while(cin >> donations[num])
    {
        sum += donations[num++];
    }
    
    average = sum/num;
    
    for (int i = 0; i < num; ++i)
    {
        if (donations[i] > average)
            moreThenAv++;
    }
    
    cout << "Average: " << average << endl;
    cout << moreThenAv << " donated more than average\n";
    
    
    return 0;
}
