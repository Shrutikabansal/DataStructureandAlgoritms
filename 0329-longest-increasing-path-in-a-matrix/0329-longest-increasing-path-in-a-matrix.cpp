class Solution {
public:
    struct priorityQueue{
        int val;
        int x;
        int y;
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // cout<< m<< " "<< n << endl;

        priority_queue<pair<int,int> >pq;
        vector<vector<int> > dis(m , vector<int>(n,1));

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                priorityQueue temp;
                // x = i;
                // y = j;
                // temp.val = matrix[i][j];
                pq.push({matrix[i][j], n*i + j});
            }
        }

        vector<pair<int, int>> dir{{1,0}, {0,1}, {-1,0}, {0,-1}};

        while(!pq.empty()){
            pair<int, int> p = pq.top();

            for(auto d: dir){
                int x = (p.second) / n, y = (p.second) % n; 
                int nr = x + d.first;
                int nc = y + d.second;
                // cout<< nr << " "<< nc << " "<< endl;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[x][y] < matrix[nr][nc]){
                    dis[x][y] = max(dis[x][y], dis[nr][nc]+1);
                }
            }


            pq.pop();

        }

        int getMax = 0;

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dis[i][j] > getMax){
                    getMax = dis[i][j];
                }
            }
        }

        return getMax;


        
    }
};