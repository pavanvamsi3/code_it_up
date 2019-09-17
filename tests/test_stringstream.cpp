#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    // integer to string
    int n = 121213;

    stringstream s;
    s << n;

    cout << s.str() << endl;

    // string to integer
    string str = "123123";
    s.clear();
    s.str("");

    s << str;

    int x;
    s >> x;

    cout << x << endl;
    return 0;
}
