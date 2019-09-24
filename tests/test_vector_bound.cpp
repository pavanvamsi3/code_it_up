#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>v;

    int n;

    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int bound;
    cin >> bound;
    cout << *lower_bound(v.begin(), v.end(), bound) << endl;
    cout << *upper_bound(v.begin(), v.end(), bound) << endl;
    return 0;
}
