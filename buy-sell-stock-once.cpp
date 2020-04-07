class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        ## i is the buying time
        int i = 0;
        ## j is the selling time
        int j = 1;
        while (j < prices.size()){
            ## if prices[j] - prices[i] < 0, we can buy stock at a better price at j
            if (prices[j] - prices[i] < 0){
                i = j;
                j = j + 1;
            }
            else if (prices[j] - prices[i] > result){
                ## the result only gets updated if we get a better profit by buying at i and selling at j
                result = prices[j] - prices[i];
                j++;
            }
            else{ 
                j++;
            }
            
        }
        return result;
        
    }
};

//Time complexity: O(n) n is len(prices)
//Space complexity: O(1) variables are 'result', 'i', 'j'