class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool z = true;
        for(int i = 0; i < nums.size(); i++) {
            x ^= nums[i];
            if(nums[i] != 0) z = false;
        }

        if(z) return 0;           // all zeros, no valid subsequence
        if(x != 0) return nums.size();  // whole array works
        return nums.size() - 1;   // remove one element
    }
};