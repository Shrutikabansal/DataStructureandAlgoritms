class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i,j;

        for(i=0;i<m;i++){
            for(j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n/2;j++){
                // cout<< i << " "<< j<< " "<< n-j-1 <<endl;

                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
        
    }
};