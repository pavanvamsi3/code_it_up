#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string addStrings(string num1, string num2)
{
    int i = num1.length()-1;
    int j = num2.length()-1;

    int carry = 0;
    string result = "";
    while(i >= 0 && j >= 0) {
        int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
        result.push_back(sum%10 + '0');
        carry = sum/10;
        i--; j--;
    }
    
    while(i >= 0) {
        int sum = (num1[i] - '0') + carry;
        result.push_back(sum%10 + '0');
        carry = sum/10;
        i--;
    }

    while(j >= 0) {
        int sum = (num2[j] - '0') + carry;
        result.push_back(sum%10 + '0');
        carry = sum/10;
        j--;
    }

    if (carry) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;

}
int main()
{
    string a;
    string b;
    
    cin >> a;
    cin >> b;

    cout << addStrings(a, b) << endl;

    return 0;
}
