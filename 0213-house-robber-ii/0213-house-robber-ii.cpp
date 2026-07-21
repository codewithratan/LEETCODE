class Solution {
public:
    int helper(vector<int>nums,int st,int end){
         int n=nums.size();
        
        int prev2=nums[st];
        int prev1=max(nums[st],nums[st+1]);
        int result=prev1;
        for(int i=st+2;i<=end;i++){
            result=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=result;
        }
        return result;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};