#include <iostream>

using namespace std;

int main(void)
{
    int a = 10;
    int b = 11;
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    a = a xor b;
    b = b xor a;
    a = a xor b;
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;

    float c = 3.1;

    int d = int(c);

    cout << d << endl;

}