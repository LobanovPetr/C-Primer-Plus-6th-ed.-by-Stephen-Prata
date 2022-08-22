// count body mass index

#include <iostream>

void BMI(void);

int main()
{
    BMI();
    return 0;
}

void BMI(void)
{
    using namespace std;
    const int footsToInches = 12;
    const double inchesToMeters = 0.0254;
    const double poundsToKilos = 2.2;
    
    int foots;
    int inches;
    int pounds;
    double meters;
    double kilos;
    double bmi;
    
    cout << "Enter the foots: __\b\b";
    cin >> foots;
    cout << "Enter the inches: __\b\b";
    cin >> inches;
    cout << "Enter the pounds: __\b\b";
    cin >> pounds;
    
    inches = inches + foots * footsToInches;
    meters = inches * inchesToMeters;
    kilos = pounds / poundsToKilos;
    
    bmi = kilos / (meters * meters);
    
    cout << "BMI " << bmi << endl;
}
