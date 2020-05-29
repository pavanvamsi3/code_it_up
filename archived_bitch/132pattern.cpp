#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool find132pattern(vector<int>nums)
{
    vector<int>_min;
    _min.push_back(nums[0]);
    for(int i=1; i<nums.size(); i++) {
        if (nums[i] < _min[i-1]) {
            _min.push_back(nums[i]);
        } else {
            _min.push_back(_min[i-1]);
        }
    }
    
    stack<int>s;

    for(int i=nums.size()-1; i>=0; i--) {
        if (nums[i] > _min[i]) {
            while(!s.empty() && s.top() <= _min[i]) {
                s.pop();
            }
            if (!s.empty() && s.top() < nums[i]) {
                return true;
            }
            cout << nums[i] << endl;
            s.push(nums[i]);
        }
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
    
    find132pattern(v);
    return 0;
}
