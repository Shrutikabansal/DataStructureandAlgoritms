class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(); // rows
        int n = obstacleGrid[0].size(); // column
        int dp[m][n];
        int i,j;

        dp[0][0] = 1;
        if(obstacleGrid[0][0] == 1)
            dp[0][0] = -1;

        for(i=1;i<m;i++){
            if(obstacleGrid[i][0] == 1){
                dp[i][0] = -1;
            }else{
                dp[i][0] = dp[i-1][0];
            }
        }
        
        for(j=1;j<n;j++){
            if(obstacleGrid[0][j] == 1){
                dp[0][j] = -1;
            }else{
                dp[0][j] = dp[0][j-1];
            }
        }


        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = -1;
                }else{
                    if(min(dp[i-1][j], dp[i][j-1]) != -1){
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }

        if(dp[m-1][n-1] == -1)
            return 0;

        return dp[m-1][n-1];
        
    }
};