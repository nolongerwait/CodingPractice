/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int peakIndex(MountainArray mountainArr) {
        int left = 0, right = mountainArr.length() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid == 0) return 1;
            if (mid == mountainArr.length() - 1) return mountainArr.length() - 2;
            int mValue = mountainArr.get(mid);
            int lValue = mountainArr.get(mid - 1);
            int rValue = mountainArr.get(mid + 1);
            if (mValue > lValue && mValue > rValue) return mid;
            if (lValue - mValue > 0) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    // when order is true, ascending order. false - descending order.
    int binarySearch(int target, MountainArray mountainArr, int left, int right, bool order) {
        while(left < right) {
            int mid = (left + right) / 2;
            int mValue = mountainArr.get(mid);
            if (mValue == target) return mid;
            if (mValue > target == order) right = mid - 1;
            else left = mid + 1;
        }
        return target == mountainArr.get(left) ? left : -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peakIndex(mountainArr);
        int result = binarySearch(target, mountainArr, 0, peak, true);
        return result >= 0 ? result : binarySearch(target, mountainArr, peak+1, mountainArr.length()-1, false);
    }
};