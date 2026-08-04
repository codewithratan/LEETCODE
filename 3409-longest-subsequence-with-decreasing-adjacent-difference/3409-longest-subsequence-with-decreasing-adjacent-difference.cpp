class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int>>> dp(303,vector<pair<int,int>>(303,{0,0}));
        int ans =0;
        
        for(int i=0;i<n;i++){
            int mx = 0;
            for(int j=300;j>=0;j--){
                int prevL = nums[i] - j;
                int prevG = nums[i] + j;
                int cur = 0;
                if(prevL>=0){
                    int l = 1 + dp[prevL][j].second;
                    cur = max(cur,l);
                }
                if(prevG<=300){
                    int l = 1 + dp[prevG][j].second;
                    cur = max(cur,l);
                }
                mx = max(mx,cur);
                dp[nums[i]][j] = {cur,mx};
                            ans = max(ans,mx);

            }
        }
        return ans;
    }
};