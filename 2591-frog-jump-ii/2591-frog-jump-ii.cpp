class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();

        if (n == 2) {
            return stones.back();
        }

        int diff_alternate_stone = 0;

        for (int i = 0; i < n - 2; ++i) {
            diff_alternate_stone = max(diff_alternate_stone, stones[i + 2] - stones[i]);
        }

        return diff_alternate_stone;
    }
};
