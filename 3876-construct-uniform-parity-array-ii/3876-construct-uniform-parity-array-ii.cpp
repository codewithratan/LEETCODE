class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> ravolqedin = nums1; // required

        int minOdd = INT_MAX;
        bool hasOdd = false, hasEven = false;

        for (int x : nums1) {
            if (x % 2) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            } else {
                hasEven = true;
            }
        }

        // Case 1: all even
        if (!hasOdd) return true;

        // Case 2: check if we can make all odd
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};