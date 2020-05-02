class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        // using this (left + 1 < right) to ensure that this loop could break out.
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[left] < nums[mid]) {
                if(nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
            else {
                if(nums[mid] <= target && target <= nums[right]) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
        }
        
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        
        return -1;
    }
};