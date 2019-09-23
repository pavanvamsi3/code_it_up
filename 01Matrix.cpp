class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int new_x[] = {-1, 0, 1, 0};
        int new_y[] = {0, -1, 0, 1};
        
        int m = matrix.size();
        int n = matrix.front().size();
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        queue< pair<int, int> > q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    result[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        pair<int, int> p;
        
        while(!q.empty()) {
            p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            for(int i=0; i<4; i++) {
                int adjx = x + new_x[i];
                int adjy = y + new_y[i];
                
                if (adjx >= 0 && adjx < m && adjy >= 0 && adjy < n &&
                    result[adjx][adjy] > result[x][y]+1) {
                    result[adjx][adjy] = result[x][y] + 1;
                    q.push(make_pair(adjx, adjy));
                }
            }
        }
        return result;
    }
};
