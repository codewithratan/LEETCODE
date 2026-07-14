#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int subsequencePairCount(std::vector<int>& nums) {
        constexpr int MOD = 1'000'000'007;
        
        // Find the maximum element to bound our DP table size
        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }
        
        // dp[g1][g2] stores number of pairs with GCD g1 and g2
        // Size is (max_val + 1) x (max_val + 1)
        std::vector<std::vector<int>> dp(max_val + 1, std::vector<int>(max_val + 1, 0));
        
        // Base case: both subsequences are empty
        dp[0][0] = 1;
        
        for (int num : nums) {
            // Create a copy of the current DP state to compute the next state
            std::vector<std::vector<int>> next_dp = dp;
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;
                    
                    long long current_ways = dp[g1][g2];
                    
                    // Choice 1: Add 'num' to the first subsequence
                    int n1 = std::gcd(g1, num);
                    next_dp[n1][g2] = (next_dp[n1][g2] + current_ways) % MOD;
                    
                    // Choice 2: Add 'num' to the second subsequence
                    int n2 = std::gcd(g2, num);
                    next_dp[g1][n2] = (next_dp[g1][n2] + current_ways) % MOD;
                }
            }
            dp = std::move(next_dp);
        }
        
        // Sum up all cases where g1 == g2 and both are non-empty (g > 0)
        long long total_pairs = 0;
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % MOD;
        }
        
        return total_pairs;
    }
};