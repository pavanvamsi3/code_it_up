/*
   Didn't understand the question in the first go? 

   Welcome to the club, let me try and make it a little simple for you.

   An array of flowers is given, which contains the day on which it blooms
   
Example: flowers[1, 3, 2]

Flower 1 will bloom on day 1
Flower 2 on day 3
Flower 3 on day 2

Blooming status would be like [B, 3, 2] on day 1 and [B, 3, B] on day 2...

Now, given an integer k, you need to find a day on which there exists k non blooming flowers between two blooming ones

from the example, given k = 1 on day 2, the status is like [B, 3, B], so ans is 2

If there's no such day return -1

Input:
3
1 3 2
1

Output:
2
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int kEmptySlots(vector<int> &flowers, int k)
{
    vector<int>days(flowers.size());

    // Populating the days array for better visualisation
    for(int i=0; i<flowers.size(); i++) {
        days[flowers[i]-1] = i+1;
    }
    int left = 0;
    int right = k+1;
    int blooming_day = INT_MAX;

    for(int i = 0; right < days.size(); i++) {
        if (days[i] > days[left] && days[i] > days[right]) {
            continue;
        }
        if (i == right) {
            blooming_day = min(blooming_day, max(days[left], days[right]));
        }
        left = i;
        right = i + k + 1;
    }

    return blooming_day == INT_MAX ? -1 : blooming_day;
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

    int k; cin >> k;

    cout << kEmptySlots(v, k) << endl;

    return 0;
}

