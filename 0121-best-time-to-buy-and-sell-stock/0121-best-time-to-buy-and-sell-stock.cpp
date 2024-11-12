class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i;
        int mini = INT_MAX, maxi = prices[n-1];
        int profit = 0;

        for(i=n-2;i>=0;i--){
            if (prices[i] > maxi){
                maxi = prices[i];    
            }else{
                int currentProfit = maxi - prices[i];
                if (currentProfit > profit){
                    profit = currentProfit;
                }
            }

        }

        return profit;


        
    }
};