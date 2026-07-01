class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1);   // store last index of character
        int left = 0, maxLen = 0;
        
        for(int right = 0; right < s.length(); right++) {
            if(index[s[right]] >= left) {
                left = index[s[right]] + 1;
            }
            
            index[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};