#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool find132pattern(vector<int>nums)
{
    vector<int>_min;
    _min.push_back(nums[0]);
    for(int i=1; i<nums.size(); i++) {
        _min.push_back(min(_min[i-1], _min[i]));
    }
    
    set<int>s;

    for(int i=nums.size()-1; i>0; i--) {
        cout << "Lower bound for:";
        cout << nums[i] << endl;
        cout << *lower_bound(s.begin(), s.end(), nums[i]) << endl;
        int curr_low = *lower_bound(s.begin(), s.end(), nums[i]);
        if (lower_bound(s.begin(), s.end(), nums[i]) != s.end() && nums[i] > curr_low) {
            int right = *lower_bound(s.begin(), s.end(), nums[i]);
            int left = _min[i-1];
            if (left < right) {
                return true;
            }
        }
        s.insert(nums[i]);
      //  cout << *s.begin() << endl;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int>v;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    string ans = find132pattern(v) ? "True" : "False";
    cout << ans << endl;
    return 0;
}
