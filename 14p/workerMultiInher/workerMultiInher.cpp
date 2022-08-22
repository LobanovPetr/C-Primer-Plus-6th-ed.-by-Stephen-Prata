#include "workerMultiInher.h"
#include <iostream>


using std::cout;
using std::endl;
using std::getline;
using std::cin;

void Worker::Data() const
{
    cout << "fullname: " << fullname << endl;
    cout << "id: " << id << endl;
}

void Worker::Get()
{
    cout << "Enter the name:\n";
    getline(cin, fullname);
    cout << "Enter the id: \n";
    cin >> id;
    while(cin.get() != '\n');
}

void Waiter::Data() const
{
    cout << "panache: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter the panache:\n";
    cin >> panache;
    while(cin.get() != '\n');
}

void Waiter::Set()
{
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    Worker::Data();
    Data();
}

const char* Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Data() const
{
    cout << "voice: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Enter number of vocal range: \n";
    cin >> voice;
    while(cin.get() != '\n');
}

void Singer::Set()
{
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    Worker::Data();
    Data();
}

void SingerWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingerWaiter::Get()
{
    Singer::Get();
    Waiter::Get();
}

void SingerWaiter::Set()
{
    Worker::Get();
    Get();
}

void SingerWaiter::Show() const
{
    Worker::Data();
    Data();
}
