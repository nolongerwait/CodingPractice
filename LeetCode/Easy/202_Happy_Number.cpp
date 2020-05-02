class Solution {
public:
    int sumDigitSquare(int n) {
        int sum = 0;
        while(n > 0) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumDigitSquare(slow);
        while(fast != 1) {
            slow = sumDigitSquare(slow);
            fast = sumDigitSquare(sumDigitSquare(fast));
            if(slow == fast) return false;
        }
        return true;
    }
};