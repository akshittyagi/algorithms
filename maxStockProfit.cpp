/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.


*/
int maxSubArray(vector<int>& nums) {
    
        int maxSum = nums[0];
        int currSum = nums[0];
        for(int i = 1; i<nums.size();i++)
        {
            currSum = (currSum<=0?nums[i]:nums[i]+currSum);
            // if(nums[i]+currSum<nums[i])
            // {
            //     currSum = nums[i];
            // }
            // else
            // {
            //     currSum = nums[i] + currSum;
            // }
            if(currSum>maxSum)
                maxSum = currSum;
            // maxSum = max(currSum,maxSum);
        }
        return maxSum;
    }

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        vector<int> diff;
        for(int i=0;i<prices.size()-1;i++)
        {
            diff.push_back(prices[i+1]-prices[i]);
        }
        return max(0,maxSubArray(diff));
    }
};