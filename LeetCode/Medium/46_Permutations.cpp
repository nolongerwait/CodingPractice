class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>::iterator begin, vector<int>::iterator end)
    {
        if(begin == end)
        {
            result.push_back(nums);
            return;
        }

        for(vector<int>::iterator iter = begin; begin != end; ++iter)
        {
            if(iter == end) break;
            swap(*begin, *iter);
            dfs(result, nums, begin+1, end);
            swap(*iter, *begin);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        dfs(result, nums, nums.begin(), nums.end());
        return result;
    }
};