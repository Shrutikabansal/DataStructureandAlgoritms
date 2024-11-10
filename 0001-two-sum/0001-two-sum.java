class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();
        int i,j;
        int[] result = new int[2];
        for(i=0;i<nums.length;i++) {
            mp.put(nums[i],i);
        }
        int diff;
        for(i=0;i<nums.length;i++) {
            diff=target-nums[i];
            if(mp.get(diff) != null && mp.get(diff) != i) {
                result[0]=i;
                result[1]=mp.get(diff);
                return result;
            }
        }
        return result;
    }
}