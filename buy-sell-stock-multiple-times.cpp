class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        //i is buying time
        //j is selling time
        //the strategy is we buy and sell whenever there is profit
        int i = 0;
        int j = 1;
        while (j < prices.size()){
            if (prices[j] - prices[i] < 0){
                i++;
                j++;
            }
            else if (j < prices.size() - 1){
                if (prices[j+1] >= prices[j]){
                    j++;
                    }
                else{
                //we sell stock as soon as the price goes down 
                    profit += prices[j] - prices[i];
                    i = j + 1;
                    j = i + 1;
                }
            }
            //this step is to avoid the disturbance happens at the final index
            else {
                if (prices[j] > prices[j-1]){
                    profit += prices[j] - prices[i];
                    
                }
                else {
                    profit += prices[j-1] - prices[i];
                }
                j++;
            }
        }
        return profit;
    }
};

//Time complexity: O(n) with n is len(prices)
//Spcae complexity: O(1) with variables are 'i','j' and 'profit'