class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int i=0,j=0;
        vector<int>v;

        while(i<m && j<n){
            for(int k = i; k<n;k++){
                v.push_back(matrix[i][k]);
            }

            i = i+1;
            if(i<m && j<n && n>0&& m >0){
                for(int k = i  ; k<m;k++){
                v.push_back(matrix[k][n-1]);
            }

            }
            n=n-1;
            if(i<m && j<n && n>0&& m >0){
                for(int k = n-1; k>=j;k--){
                v.push_back(matrix[m-1][k]);
            }

            }

            m = m-1;

            if(i<m && j<n && n>0&& m >0){
                for(int k = m-1; k>=i;k--){
                v.push_back(matrix[k][j]);
            }

            }
            j =j+1;
        }

        return v;
        
    }
};