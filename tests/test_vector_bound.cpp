#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << *lower_bound(v.begin(), v.end(), 2) << endl;
    cout << *upper_bound(v.begin(), v.end(), 2) << endl;
    return 0;
}
