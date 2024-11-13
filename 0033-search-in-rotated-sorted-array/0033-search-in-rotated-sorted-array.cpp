class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int left = 0, right = n-1, mid = (left+right)/2;
        int answer = -1;

        while(left<=right){
            mid = (left+right)/2;
            cout<< left << " " << right << " " << mid << endl;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[left]){
                if(target >= nums[left] && target <= nums[mid]){
                    right = mid;
                }else{
                    left = mid+1;
                }

            }else{
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid;
                }else{
                    right = mid-1;
                }

            }

        }

        return answer;
        
    }
};