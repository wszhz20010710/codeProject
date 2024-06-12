#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_a(box b)
{
    cout << "maker: " << b.maker << endl;
    cout << "height: " << b.height << endl;
    cout << "width: " << b.width << endl;
    cout << "length: " << b.length << endl;

    b.volume = b.height * b.length * b.width;
    cout << "volume: " << b.volume << endl;
}

void show_b(box * b)
{
    cout << "maker: " << b->maker << endl;
    cout << "height: " << b->height << endl;
    cout << "width: " << b->width << endl;
    cout << "length: " << b->length << endl;

    b->volume = b->height * b->length * b->width;
    cout << "volume: " << b->volume << endl;
}

int main()
{
    box b;
    cout << "type in the maker: ";
    cin >> b.maker;
    cout << "length,width,heiight: ";
    cin >> b.length >> b.width >> b.height;
    show_a(b);
    cout << ".........................." << endl;
    show_b(&b);
    
    return 0;
}