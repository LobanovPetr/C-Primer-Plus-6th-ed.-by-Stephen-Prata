#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    struct
    {
        char firstName[50];
        char lastName[50];
        char letter;
        int age;
    } person;
    
    cout << "What is your first name? ";
    cin.getline(person.firstName, 50);
    cout << "What is your last name? ";
    cin.getline(person.lastName, 50);
    cout << "What letter grade do you deserve? ";
    cin >> person.letter;
    cout << "What is you age? ";
    cin >> person.age;
    person.letter += 1;
    cout << "Name: " << person.lastName << ", " << person.firstName << endl;
    cout << "Grade: " << person.letter << endl;
    cout << "Age: " << person.age << endl;
    
    return 0;
}
