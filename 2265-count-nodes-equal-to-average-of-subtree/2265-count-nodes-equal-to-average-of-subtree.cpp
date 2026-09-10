/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;  // Counter for nodes matching the average condition
    
    // Returns pair: {sum of subtree, count of nodes in subtree}
    pair<int, int> findSumAndNum(TreeNode* root) {
        // Base case: empty node
        if (!root) return {0, 0};
        
        // Recursively get sum and count from left subtree
        pair<int, int> leftN(0, 0);
        if (root->left) {
            leftN = findSumAndNum(root->left);
        }
        
        // Recursively get sum and count from right subtree
        pair<int, int> rightN(0, 0);
        if (root->right) {
            rightN = findSumAndNum(root->right);
        }
        
        // Calculate current subtree's total sum and count
        int sum = leftN.first + rightN.first + root->val;
        int num = leftN.second + rightN.second + 1;
        
        // Check if current node's value equals the average
        if (root->val == (sum / num)) {
            ans++;
        }
        
        // Return sum and count to parent
        return {sum, num};
    }
    
    int averageOfSubtree(TreeNode* root) {
        findSumAndNum(root);
        return ans;
    }
};