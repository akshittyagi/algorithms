/**
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> ret(digits.size());
        int carry = 0;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int sum;
            if(i==digits.size()-1)
                sum = carry + digits[i] + 1;
            else
                sum = carry + digits[i];
            int dig = (sum)%10;
            ret[i] = dig;
            if(sum>=10)
                carry = 1;
            else
                carry = 0;
            
        }
        if(carry == 1)
        {
            vector<int> r = {1};
            r.insert(r.end(), ret.begin(), ret.end());
            return r;
        }
        else
            return ret;
    }
};