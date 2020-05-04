class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        digits[len-1] += 1;
        vector<int> res = {};
        int carry = 0;
        for(int i = len-1; i >= 0; --i) {
            int digit = digits[i] + carry;
            carry = digit / 10;
            digit %= 10;
            res.push_back(digit);
        }
        if(carry != 0) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;        
    }
};