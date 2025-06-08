class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i*i <= c; ++i) {
            long long num = c - (i * i);
            long long target = sqrt(num);
            if (target * target == num) {
                return true;
            }
        }
        return false;
    }
};