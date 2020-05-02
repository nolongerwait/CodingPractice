class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> indexOfOdd;
        int result = 0;

        indexOfOdd.push_back(-1); // Set left border -1 to help compute.
        // Record the index of all odd elements.
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] % 2 == 1)
            {
                indexOfOdd.push_back(i);
            }
        }
        indexOfOdd.push_back(nums.size()); // Set right border nums.size() to help compute.

        for(int i = k; i < indexOfOdd.size() - 1; ++i)
        {
            int left = indexOfOdd[i - k + 1] - indexOfOdd[i - k];
            int right = indexOfOdd[i + 1] - indexOfOdd[i];
            result += left * right;
        }

        return result;
    }
};