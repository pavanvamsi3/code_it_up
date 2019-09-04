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

using namespace std;

struct interval {
    int start;
    int end;
};

bool sort_by_start(interval i, interval j)
{
    return i.start < j.start;
}

int get_meeting_rooms(vector<interval>&v)
{
    if (v.empty()) {
        return 0;
    }
    sort(v.begin(), v.end(), sort_by_start);

    int rooms = 1;
    int min_end_time = v[0].end;

    for(int i=1; i<v.size(); i++) {
        if (v[i].start < min_end_time) {
            rooms++;
        }
        if (v[i].end < min_end_time) {
            min_end_time = v[i].end;
        }
    }
    return rooms;
}


int main()
{
    int n;
    cin >> n;

    vector<interval>v;

    for(int i=0; i<n; i++) {
        int start;
        int end;

        interval in;

        cin >> start;
        cin >> end;
        in.start = start;
        in.end = end;

        v.push_back(in);
    }
    
    cout << get_meeting_rooms(v) << endl;

    return 0;
}
