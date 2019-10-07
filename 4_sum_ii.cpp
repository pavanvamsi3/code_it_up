class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>m;
        int result = 0;
        for(int i: A) {
            for(int j: B) {
                m[i+j]++;
            }
        }
        for(int i: C) {
            for(int j: D) {
                result += m[-(i+j)];
            }
        }
        return result;
    }
};
