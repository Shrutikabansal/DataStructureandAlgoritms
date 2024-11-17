class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int i,j;
        int island = 0;

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    bfs(grid, i,j);
                    island++;
                }
            }
        }

        return island;
    }

    void bfs(vector<vector<char>>& grid, int r, int c){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = '0';
        vector<pair<int, int> > v={{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto [x,y] = q.front();

            for(auto [row, col] : v){

                int newRow = row+x;
                int newCol = col+y;

                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol] == '1'){
                    q.push({newRow,newCol});
                    grid[newRow][newCol] = '0';
                }
            }


            q.pop();

        }





    }

};