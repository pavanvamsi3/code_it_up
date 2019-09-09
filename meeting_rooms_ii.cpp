/*
Input:
3
1 2
2 3
3 4

Output:
1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool sortByStart(Interval i, Interval j)
{
    return i.start < j.start;
}

int minMeetingRooms(vector<Interval>&v)
{
    if (v.empty()) {
        return 0;
    }
    sort(v.begin(), v.end(), sortByStart);
    
    priority_queue<int, vector<int>, greater<int> > heap;

    int rooms = 1;
    heap.push(v[0].end);

    for(int i=1; i<v.size(); i++) {
        if (v[i].start < heap.top()) {
            rooms++;
        } else {
            heap.pop();
        }
        heap.push(v[i].end);
    }
    return rooms;
}


int main()
{
    int n;
    cin >> n;

    vector<Interval>v;

    for(int i=0; i<n; i++) {
        int start;
        int end;

        Interval in;

        cin >> start;
        cin >> end;
        in.start = start;
        in.end = end;

        v.push_back(in);
    }
    
    cout << minMeetingRooms(v) << endl;

    return 0;
}
