#include <iostream>
using namespace std;
const int& const fun() {
    int a = 10;
    int& b = a;
    return b;
}
int main()
{
    const int& const a = fun();
    cout << a;
    return 0;
}