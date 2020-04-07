class Solution(object):
    def maxProfit(self, prices, fee):
        ##cash is the total money you have
        ##hold is the money in your hand
        
        ##at first: you have no cash and you paid prices[0] to buy a share, so you have -prices[0] in your hand 
        cash, hold = 0, -prices[0]
        
        for i in range(1, len(prices)):
            ##cash gets updated when hold + prices[i] - fee > cash[i-1], meaning the ith transaction is worth doing
            ##cash is increasing
            cash = max(cash, hold + prices[i] - fee)
            ##hold gets updated when cash - prices[i] > hold[i-1], meaning we will buy stock at i 
            ##hold is increasing 
            hold = max(hold, cash - prices[i])
            print(cash,hold)
            
        return cash

        ##Time complexity: O(n), n = len(prices)
        ##Space complexity: O(1), variables are cash and hold