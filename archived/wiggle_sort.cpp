/*
Input:
4
1 2 3 4

Output:
1 3 2 4
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void wiggle_sort(vector<int> &v)
{
	bool less = true;

	for(int i=0; i<v.size()-1; i++) {
		if (less) {
			if(v[i] > v[i+1]) 
				swap(v[i], v[i+1]);
		} else {
			if(v[i] < v[i+1])
				swap(v[i], v[i+1]);
		}
		less = !less;
	}
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
	
	wiggle_sort(v);

	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}

