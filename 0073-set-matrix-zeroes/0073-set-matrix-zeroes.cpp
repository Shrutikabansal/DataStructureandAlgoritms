class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns

        int i,j;

        bool row = false, col = false;

            for(j=0;j<n;j++){
                if(matrix[0][j] == 0){
                    row = true;
                    break;
                }
            }

        for(i=0;i<m;i++){
                if(matrix[i][0] == 0){
                    col = true;
                    break;
            }
        }


        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

  
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                   matrix[i][j] = 0;
                }
            }
        }

        if(row){
            for(j=0;j<n;j++){
                matrix[0][j] = 0;
                
            }
        }

        if(col){
            for(j=0;j<m;j++){
                matrix[j][0] = 0;
                
            }
        }
      
    }
};