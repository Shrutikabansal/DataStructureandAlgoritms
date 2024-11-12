class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n-1;
        int maxAns = INT_MIN;

        while(left<right){
            int temp = (right-left) * min(height[left], height[right]);
            maxAns = max(maxAns, temp);

            if (height[left]< height[right]){
                left++;
            }else{right--;}
        }
        return maxAns;
        
    }
};