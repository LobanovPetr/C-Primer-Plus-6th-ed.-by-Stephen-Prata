// count taxes
// first 5000 products taxes = 0%
// second 10 000 products taxes = 10% i.e. 1000
// thirt 20000 - 15%
// more than 35000 - 20 %
// 1000
// 3000
//

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double taxes = 0;
    double profit;
    
    while(cout << "Enter the prfit: ", cin >> profit, profit>= 0)
    {
        if (profit > 35000)
            taxes = 4000 + (profit - 35000) * 0.20;
        else if (profit > 15000)
            taxes = 1000 + (profit - 15000) * 0.15;
        else if (profit > 5000)
            taxes = (profit - 5000) * 0.1;
        else
            taxes = 0;
        cout << "You have to pay " << taxes << " taxes\n";
    }
}
