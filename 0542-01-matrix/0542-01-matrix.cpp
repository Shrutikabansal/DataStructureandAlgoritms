class Solution {
public:
    struct queueData {
        int x;
        int y; 
        int d;
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<queueData> q;

        for(int i =0 ; i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                }else{
                    mat[i][j] = INT_MAX;
                }
            }
        }
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};



        while(!q.empty()){
            queueData temp = q.front();
            q.pop();

            for(auto x: directions){
                int nr = temp.x + x.first;
                int nc = temp.y + x.second;

                if(nc>=0 && nr >= 0 && nc <n && nr <m && mat[nr][nc] > mat[temp.x][temp.y]+1){
                    mat[nr][nc] = mat[temp.x][temp.y]+1;
                    q.push({nr,nc, temp.d+1});
                }
            }

        }

        return mat;
        
    }
};