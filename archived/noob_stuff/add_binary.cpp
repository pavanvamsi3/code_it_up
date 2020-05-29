#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

unsigned long int sum(unsigned long int a, unsigned long int b)
{
    return a + b;
}

string addBinary(string a, string b)
{
    bitset<8>a_bit(a);
    bitset<8>b_bit(b);

    bitset<8>sum_bit = sum(a_bit.to_ulong(), b_bit.to_ulong());

    return sum_bit.to_string();
}

int main()
{
    string a;
    string b;

    cin >> a;
    cin >> b;

    cout << addBinary(a, b) << endl;

    return 0;
}
