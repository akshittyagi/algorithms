/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
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
};