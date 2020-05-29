#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    set<int>s;
    for(int i=4; i>0; i--) {
        s.insert(i);
    }
    
    set<int> :: iterator it;

    for(it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    int bound;
    cin >> bound;

    cout << *lower_bound(s.begin(), s.end(), bound) << endl;
    cout << *upper_bound(s.begin(), s.end(), bound) << endl;

    return 0;
}
