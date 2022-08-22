// prog works with a box struct
// it can count volume of a box
// it can show all fields of a box

#include <iostream>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show(box);
void countVolume(box *);

int main()
{
    using namespace std;
    
    box b;
    cout << "Enter the box parameters:\n";
    cout << "Maker: ";
    cin >> b.maker;
    cout << "Height: ";
    cin >> b.height;
    cout << "Length: ";
    cin >> b.length;
    cout << "Width: ";
    cin >> b.width;
    
    countVolume(&b);
    
    show(b);
    
    return 0;
}

void show(box b)
{
    using namespace std;
    cout << "Maker:\t" << b.maker << endl;
    cout << "Height:\t" << b.height << endl;
    cout << "Length:\t" << b.length << endl;
    cout << "Volume:\t" << b.volume << endl;
    return;
}

void countVolume(box * b)
{
    b->volume = b->height * b->length * b->width;
    return;
}

