class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countNumEnclaves = 0;
        queue<pair<int, int> > q;

        vector< vector< bool> > vis (n, vector<bool> (m, false));

        for(int i = 0; i< n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1 || j == m-1 || i == 0 || j == 0)&& grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        vector<int> xDir{ 1, 0, -1, 0};
        vector<int> yDir{ 0, -1, 0, 1};



        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            // cout<< i<< " "<< j <<endl;



            for(int k = 0; k < 4;k++){
                int newCol = j + yDir[k];
                int newRow = i + xDir[k];

                if(newRow<n && newCol <m && newRow >= 0 && newCol >= 0 && vis[newRow][newCol] == false && grid[newRow][newCol] == 1){
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }

            }


        }

        for(int i = 0; i< n;i++){
            for(int j=0;j<m;j++){
                // cout<< i<< " "<< j << " "<< grid[i][j]<< " "<< vis[i][j]<< endl;
                // cout<< vis[i][j] << " ";
                if(grid[i][j] == 1 && vis[i][j] == false){
                    countNumEnclaves++;  
                }
            }
            // cout<<endl;
        }
        
        return countNumEnclaves;
    }
};