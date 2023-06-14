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
    void helper(TreeNode*root,int &prev,int &ans){
        if(root==NULL)
            return;
        helper(root->left,prev,ans);
        ans=min(ans,abs(prev-root->val));
        prev=root->val;
        helper(root->right,prev,ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        int prev=INT_MAX/2;
        helper(root,prev,ans);
        return ans;
    }
};